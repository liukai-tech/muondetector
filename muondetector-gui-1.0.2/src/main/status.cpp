#include <status.h>
#include <ui_status.h>
#include <plotcustom.h>



static const int rateSecondsBuffered = 60*120; // 120 min
static const int MAX_BINS = 200; // bins in pulse height histogram
static const float MAX_ADC_VOLTAGE = 4.0;

Status::Status(QWidget *parent) :
    QWidget(parent),
    statusUi(new Ui::Status)
{
    statusUi->setupUi(this);
    statusUi->pulseHeightHistogram->title="Pulse Height";
    statusUi->pulseHeightHistogram->setLogY(false);
    connect(statusUi->resetHistoPushButton, &QPushButton::clicked, this, &Status::clearPulseHeightHisto);
    connect(statusUi->biasEnableCheckBox, &QCheckBox::clicked, this, &Status::biasSwitchChanged);
    connect(statusUi->highGainCheckBox, &QCheckBox::clicked, this, &Status::gainSwitchChanged);
    connect(statusUi->preamp1CheckBox, &QCheckBox::clicked, this, &Status::preamp1SwitchChanged);
    connect(statusUi->preamp2CheckBox, &QCheckBox::clicked, this, &Status::preamp2SwitchChanged);
    
    fInputSwitchButtonGroup = new QButtonGroup(this);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton0,0);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton1,1);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton2,2);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton3,3);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton4,4);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton5,5);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton6,6);
    fInputSwitchButtonGroup->addButton(statusUi->InputSelectRadioButton7,7);
    connect(fInputSwitchButtonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked),
    [=](int id){ emit inputSwitchChanged(id); });
    
    
}

void Status::onGpioRatesReceived(quint8 whichrate, QVector<QPointF> rates){
    if (whichrate==0){
        if (xorSamples.size()>0){
            for (int k = rates.size()-1; k>=0; k--){
                bool foundK = false; // if foundK it has found an index k where the x values of the input points
                // are smaller or equal to the x values of the already existing points -> overlap
                for (int i = xorSamples.size()-1; i>=xorSamples.size()-1-rates.size(); i--){
                    if (rates.at(k).x()<=xorSamples.at(i).x()){
                        foundK = true;
                    }
                }
                if (foundK && k<rates.size()){
                    // if there is an overlap, remove all points from input rate points that are already existing
                    rates.remove(0,k+1);
                    break;
                }
            }
        }
        for (auto rate : rates){
            xorSamples.append(rate);
        }
        while (xorSamples.first().x()<rates.last().x()-rateSecondsBuffered){
            xorSamples.pop_front();
        }
        statusUi->ratePlot->plotXorSamples(xorSamples);
    }
    if (whichrate==1){
        if (andSamples.size()>0){
            for (int k = rates.size()-1; k>=0; k--){
                bool foundK = false; // if foundK it has found an index k where the x values of the input points
                // are smaller or equal to the x values of the already existing points -> overlap
                for (int i = andSamples.size()-1; i>=andSamples.size()-1-rates.size(); i--){
                    if (rates.at(k).x()<=andSamples.at(i).x()){
                        foundK = true;
                    }
                }
                if (foundK && k<rates.size()){
                    // if there is an overlap, remove all points from input rate points that are already existing
                    rates.remove(0,k+1);
                    break;
                }
            }
        }
        for (auto rate : rates){
            andSamples.append(rate);
        }
        while (andSamples.first().x()<rates.last().x()-rateSecondsBuffered){
            andSamples.pop_front();
        }
        statusUi->ratePlot->plotAndSamples(andSamples);
    }
}

void Status::clearPulseHeightHisto()
{
	fPulseHeightHistogramMap.clear();
	updatePulseHeightHistogram();
}

void Status::onAdcSampleReceived(uint8_t channel, float value)
{
	if (channel==0) {
		statusUi->ADCLabel1->setText("Ch1: "+QString::number(value,'f',3)+" V");
        int binNr = (MAX_BINS-1)*value/MAX_ADC_VOLTAGE;
        fPulseHeightHistogramMap[binNr]++;
        updatePulseHeightHistogram();

	} else if (channel==1)
		statusUi->ADCLabel2->setText("Ch2: "+QString::number(value,'f',3)+" V");
	else if (channel==2)
		statusUi->ADCLabel3->setText("Ch3: "+QString::number(value,'f',3)+" V");
	else if (channel==3)
		statusUi->ADCLabel4->setText("Ch4: "+QString::number(value,'f',3)+" V");

}

void Status::updatePulseHeightHistogram()
{
	QVector< QPointF > series;
	for (int i=0; i<MAX_BINS; i++) {
		QPointF point;
		point.rx() = MAX_ADC_VOLTAGE*i/MAX_BINS;
		point.ry() = fPulseHeightHistogramMap[i];
		series.push_back(point);
	}
	statusUi->pulseHeightHistogram->setData( series );
}

void Status::onUiEnabledStateChange(bool connected){
    if (connected){
        statusUi->ratePlot->setStatusEnabled(true);
        statusUi->pulseHeightHistogram->setStatusEnabled(true);
        this->setEnabled(true);
    }else{
        andSamples.clear();
        xorSamples.clear();
        fPulseHeightHistogramMap.clear();
        updatePulseHeightHistogram();
        statusUi->ratePlot->setStatusEnabled(false);
        statusUi->pulseHeightHistogram->setStatusEnabled(false);
        this->setDisabled(true);
    }
}

void Status::on_histoLogYCheckBox_clicked()
{
    statusUi->pulseHeightHistogram->setLogY(statusUi->histoLogYCheckBox->isChecked());
}

void Status::onInputSwitchReceived(uint8_t id)
{
	fInputSwitchButtonGroup->button(id)->setChecked(true);
}

void Status::onBiasSwitchReceived(bool state)
{
	statusUi->biasEnableCheckBox->setChecked(state);
}

void Status::onGainSwitchReceived(bool state)
{
	statusUi->highGainCheckBox->setChecked(state);
}

void Status::onPreampSwitchReceived(uint8_t channel, bool state)
{
	if (channel==0)
		statusUi->preamp1CheckBox->setChecked(state);
	else if (channel==1)
		statusUi->preamp2CheckBox->setChecked(state);
}

void Status::onDacReadbackReceived(uint8_t channel, float value)
{
	if (channel==0)
		statusUi->DACLabel1->setText("Ch1: "+QString::number(value,'f',3)+" V");
	else if (channel==1)
		statusUi->DACLabel2->setText("Ch2: "+QString::number(value,'f',3)+" V");
	else if (channel==2)
		statusUi->DACLabel3->setText("Ch3: "+QString::number(value,'f',3)+" V");
	else if (channel==3)
		statusUi->DACLabel4->setText("Ch4: "+QString::number(value,'f',3)+" V");
	
}

Status::~Status()
{
    delete statusUi;
    delete fInputSwitchButtonGroup;
}
