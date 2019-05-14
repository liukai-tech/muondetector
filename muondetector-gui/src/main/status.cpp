#include <QtGlobal>
#include <status.h>
#include <ui_status.h>
#include <plotcustom.h>
#include <QTime>


static quint64 rateSecondsBuffered = 60*120; // 120 min
static const int MAX_BINS = 200; // bins in pulse height histogram
static const float MAX_ADC_VOLTAGE = 4.0;

Status::Status(QWidget *parent) :
    QWidget(parent),
    statusUi(new Ui::Status)
{
    statusUi->setupUi(this);
    statusUi->pulseHeightHistogram->title="Pulse Height";
	
	statusUi->pulseHeightHistogram->setXMin(0.0);
	statusUi->pulseHeightHistogram->setXMax(MAX_ADC_VOLTAGE);
	statusUi->pulseHeightHistogram->setNrBins(MAX_BINS);
	statusUi->pulseHeightHistogram->setLogY(false);

    statusUi->ratePlotPresetComboBox->addItems(QStringList() << "seconds" << "hh:mm:ss" << "time");
    statusUi->ratePlotBufferEdit->setText(QString("%1:%2:%3:%4")
                                          .arg(rateSecondsBuffered/(3600*24),2,10,QChar('0'))
                                          .arg((rateSecondsBuffered%(3600*24))/3600,2,10,QChar('0'))
                                          .arg((rateSecondsBuffered%(3600))/60,2,10,QChar('0'))
                                          .arg(rateSecondsBuffered%60,2,10,QChar('0')));

    connect(statusUi->ratePlotBufferEdit, &QLineEdit::editingFinished, this, [this](){this->setRateSecondsBuffered(statusUi->ratePlotBufferEdit->text());});
    connect(statusUi->ratePlotPresetComboBox, &QComboBox::currentTextChanged, statusUi->ratePlot, &PlotCustom::setPreset);
    connect(statusUi->resetHistoPushButton, &QPushButton::clicked, this, &Status::clearPulseHeightHisto);
    connect(statusUi->resetRatePushButton, &QPushButton::clicked, this, &Status::clearRatePlot);
    connect(statusUi->resetRatePushButton, &QPushButton::clicked, this, [this](){ this->resetRateClicked(); } );
    connect(statusUi->ratePlotGroupBox, &QGroupBox::toggled, statusUi->ratePlot, &PlotCustom::setStatusEnabled);
    connect(statusUi->pulseHeightHistogramGroupBox, &QGroupBox::toggled, statusUi->pulseHeightHistogram, &CustomHistogram::setStatusEnabled);
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
    connect(fInputSwitchButtonGroup, static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [=](int id){ emit inputSwitchChanged(id); });
//    connect(fInputSwitchButtonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), [=](int id){ emit inputSwitchChanged(id); });

    foreach (GpioSignalDescriptor item, GPIO_SIGNAL_MAP) {
        if (item.direction==DIR_IN) statusUi->triggerSelectionComboBox->addItem(item.name);
    }
    //timepulseTimer = new QTimer(this);
    timepulseTimer.setSingleShot(true);
    timepulseTimer.setInterval(3000);
    connect(&timepulseTimer, &QTimer::timeout, this, [this]() {
         statusUi->timePulseLabel->setStyleSheet("QLabel {background-color: red;}");
    });
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

void Status::setRateSecondsBuffered(const QString& bufferTime){
    QStringList values = bufferTime.split(':');
    quint64 secs = 0;
    if (values.size()>4){
        statusUi->ratePlotBufferEdit->setText(QString("%1:%2:%3:%4")
                                              .arg(rateSecondsBuffered/(3600*24),2,10,QChar('0'))
                                              .arg((rateSecondsBuffered%(3600*24))/3600,2,10,QChar('0'))
                                              .arg((rateSecondsBuffered%(3600))/60,2,10,QChar('0'))
                                              .arg(rateSecondsBuffered%60,2,10,QChar('0')));
        return;
    }
    for (int i = values.size()-1; i >= 0; i--){
        if (i == values.size()-1){
            secs += values.at(i).toInt();
        }
        if (i == values.size()-2){
            secs += 60*values.at(i).toInt();

        }
        if (i == values.size()-3){
            secs += 3600*values.at(i).toInt();
        }
        if (i == values.size()-4){
            secs += 3600*24*values.at(i).toInt();
        }
    }
    rateSecondsBuffered = secs;
    statusUi->ratePlotBufferEdit->setText(QString("%1:%2:%3:%4")
                                          .arg(rateSecondsBuffered/(3600*24),2,10,QChar('0'))
                                          .arg((rateSecondsBuffered%(3600*24))/3600,2,10,QChar('0'))
                                          .arg((rateSecondsBuffered%(3600))/60,2,10,QChar('0'))
                                          .arg(rateSecondsBuffered%60,2,10,QChar('0')));
}

void Status::clearRatePlot()
{
    andSamples.clear();
    xorSamples.clear();
    statusUi->ratePlot->plotXorSamples(xorSamples);
    statusUi->ratePlot->plotAndSamples(andSamples);
}

void Status::onTriggerSelectionReceived(GPIO_PIN signal)
{
    if (GPIO_PIN_NAMES.find(signal)==GPIO_PIN_NAMES.end()) return;
    unsigned int i=0;
    while (i<statusUi->triggerSelectionComboBox->count()) {
        if (statusUi->triggerSelectionComboBox->itemText(i).compare(GPIO_PIN_NAMES[signal])==0) break;
        i++;
    }
    if (i>=statusUi->triggerSelectionComboBox->count()) return;
    statusUi->triggerSelectionComboBox->blockSignals(true);
    statusUi->triggerSelectionComboBox->setEnabled(true);
    statusUi->triggerSelectionComboBox->setCurrentIndex(i);
    statusUi->triggerSelectionComboBox->blockSignals(false);
}

void Status::onTimepulseReceived()
{
    statusUi->timePulseLabel->setStyleSheet("QLabel {background-color: lightGreen;}");
    timepulseTimer.start();
}

void Status::clearPulseHeightHisto()
{
	statusUi->pulseHeightHistogram->clear();
	//fPulseHeightHistogramMap.clear();
	updatePulseHeightHistogram();
}

void Status::onAdcSampleReceived(uint8_t channel, float value)
{
	if (channel==0) {
		statusUi->ADCLabel1->setText("Ch1: "+QString::number(value,'f',3)+" V");
//        int binNr = (MAX_BINS-1)*value/MAX_ADC_VOLTAGE;
		statusUi->pulseHeightHistogram->fill(value);
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
//	statusUi->pulseHeightHistogram->replot();
	statusUi->pulseHeightHistogram->update();
	long int entries = statusUi->pulseHeightHistogram->getEntries();
	statusUi->PulseHeightHistogramEntriesLabel->setText(QString::number(entries)+" entries");
}

void Status::onUiEnabledStateChange(bool connected){
    if (connected){
        if (statusUi->ratePlotGroupBox->isChecked()){
            statusUi->ratePlot->setStatusEnabled(true);
        }
        if (statusUi->pulseHeightHistogramGroupBox->isChecked()){
            statusUi->pulseHeightHistogram->setStatusEnabled(true);
        }
        this->setEnabled(true);
    }else{
        andSamples.clear();
        xorSamples.clear();
//		updatePulseHeightHistogram();        
        statusUi->ratePlot->setStatusEnabled(false);
        statusUi->pulseHeightHistogram->clear();
		statusUi->pulseHeightHistogram->setStatusEnabled(false);
        statusUi->triggerSelectionComboBox->setEnabled(false);
        timepulseTimer.stop();
        statusUi->timePulseLabel->setStyleSheet("QLabel {background-color: Window;}");
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

void Status::onTemperatureReceived(float value)
{
	statusUi->temperatureLabel->setText("Temperature: "+QString::number(value,'f',2)+" °C");
}

Status::~Status()
{
    delete statusUi;
    delete fInputSwitchButtonGroup;
}


void Status::on_triggerSelectionComboBox_currentIndexChanged(const QString &arg1)
{
    int i=statusUi->triggerSelectionComboBox->currentIndex();
    auto it=qFind(GPIO_PIN_NAMES, arg1);
    if (it==GPIO_PIN_NAMES.end()) return;
    emit triggerSelectionChanged(it.key());
}
