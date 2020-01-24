#include <qwt_symbol.h>
#include "parametermonitorform.h"
#include "ui_parametermonitorform.h"
#include <muondetector_structs.h>

parameterMonitorForm::parameterMonitorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parameterMonitorForm)
{
    ui->setupUi(this);
    ui->adcTracePlot->setTitle("ADC trace");
    ui->adcTracePlot->setAxisTitle(QwtPlot::xBottom,"sample nr. since trigger");
    ui->adcTracePlot->setAxisTitle(QwtPlot::yLeft,"U / V");

    ui->adcTracePlot->addCurve("curve1", Qt::blue);
    ui->adcTracePlot->curve("curve1").setStyle(QwtPlotCurve::NoCurve);
    QwtSymbol *sym=new QwtSymbol(QwtSymbol::Rect, QBrush(Qt::blue, Qt::SolidPattern),QPen(Qt::black),QSize(5,5));
    ui->adcTracePlot->curve("curve1").setSymbol(sym);
    ui->adcTracePlot->setAxisAutoScale(QwtPlot::xBottom, false);
    ui->adcTracePlot->setAxisAutoScale(QwtPlot::yLeft, false);
    ui->adcTracePlot->setAxisScale(QwtPlot::xBottom, -10., 40. );
    ui->adcTracePlot->setAxisScale(QwtPlot::yLeft, 0., 3.5 );
    ui->adcTracePlot->replot();
    foreach (GpioSignalDescriptor item, GPIO_SIGNAL_MAP) {
        if (item.direction==DIR_IN) ui->adcTriggerSelectionComboBox->addItem(item.name);
    }

}

parameterMonitorForm::~parameterMonitorForm()
{
    delete ui;
}

void parameterMonitorForm::onAdcSampleReceived(uint8_t channel, float value)
{
    if (channel==0)
        ui->adcLabel1->setText(QString::number(value,'f',4));
    else if (channel==1)
        ui->adcLabel2->setText(QString::number(value,'f',4));
    else if (channel==2)
        ui->adcLabel3->setText(QString::number(value,'f',4));
    else if (channel==3)
        ui->adcLabel4->setText(QString::number(value,'f',4));
}

void parameterMonitorForm::onDacReadbackReceived(uint8_t channel, float value)
{
    ui->dacSpinBox1->blockSignals(true);
    ui->dacSpinBox2->blockSignals(true);
    ui->dacSpinBox3->blockSignals(true);
    ui->dacSpinBox4->blockSignals(true);
    if (channel==0)
        ui->dacSpinBox1->setValue(value);
    else if (channel==1)
        ui->dacSpinBox2->setValue(value);
    else if (channel==2)
        ui->dacSpinBox3->setValue(value);
    else if (channel==3)
        ui->dacSpinBox4->setValue(value);
    ui->dacSpinBox1->blockSignals(false);
    ui->dacSpinBox2->blockSignals(false);
    ui->dacSpinBox3->blockSignals(false);
    ui->dacSpinBox4->blockSignals(false);
}

void parameterMonitorForm::onInputSwitchReceived(uint8_t index)
{
    ui->timingSelectionComboBox->setCurrentIndex(index);
}

void parameterMonitorForm::onBiasSwitchReceived(bool state)
{
    ui->biasEnCheckBox->setChecked(state);
}

void parameterMonitorForm::onPreampSwitchReceived(uint8_t channel, bool state)
{
    if (channel==0) ui->preamp1EnCheckBox->setChecked(state);
    else if (channel==1) ui->preamp2EnCheckBox->setChecked(state);
}

void parameterMonitorForm::onTriggerSelectionReceived(GPIO_PIN signal)
{
    if (GPIO_PIN_NAMES.find(signal)==GPIO_PIN_NAMES.end()) return;
    unsigned int i=0;
    while (i<ui->adcTriggerSelectionComboBox->count()) {
        if (ui->adcTriggerSelectionComboBox->itemText(i).compare(GPIO_PIN_NAMES[signal])==0) break;
        i++;
    }
    if (i>=ui->adcTriggerSelectionComboBox->count()) return;
    ui->adcTriggerSelectionComboBox->blockSignals(true);
    ui->adcTriggerSelectionComboBox->setEnabled(true);
    ui->adcTriggerSelectionComboBox->setCurrentIndex(i);
    ui->adcTriggerSelectionComboBox->blockSignals(false);
}

void parameterMonitorForm::onGainSwitchReceived(bool state)
{
    ui->hiGainCheckBox->setChecked(state);
}

void parameterMonitorForm::onTemperatureReceived(float temp)
{
    ui->temperatureLabel->setText(QString::number(temp, 'f', 2));
}

void parameterMonitorForm::onTimepulseReceived()
{
    //
}

void parameterMonitorForm::onAdcTraceReceived(const QVector<float> &sampleBuffer)
{
    //
    QVector<QPointF> vec;
    for (int i=0; i<sampleBuffer.size(); i++) {
        QPointF p1;
        p1.rx()=i-10;
        p1.ry()=sampleBuffer[i];
        vec.push_back(p1);
    }

    ui->adcTracePlot->curve("curve1").setSamples(vec);
    ui->adcTracePlot->replot();

}

void parameterMonitorForm::onTimeAccReceived(quint32 acc)
{
    ui->timePrecLabel->setText(QString::number(acc*1e-9, 'g', 6));
}

void parameterMonitorForm::onFreqAccReceived(quint32 acc)
{//

}

void parameterMonitorForm::onIntCounterReceived(quint32 cnt)
{
    ui->ubloxCounterLabel->setText(QString::number(cnt));
}


void parameterMonitorForm::on_dacSpinBox1_valueChanged(double arg1)
{
    emit setDacVoltage(0, arg1);
}

void parameterMonitorForm::on_dacSpinBox2_valueChanged(double arg1)
{
    emit setDacVoltage(1, arg1);
}

void parameterMonitorForm::on_dacSpinBox3_valueChanged(double arg1)
{
    emit setDacVoltage(2, arg1);
}

void parameterMonitorForm::on_dacSpinBox4_valueChanged(double arg1)
{
    emit setDacVoltage(3, arg1);
}

void parameterMonitorForm::onCalibReceived(bool valid, bool eepromValid, quint64 id, const QVector<CalibStruct> & calibList)
{
    if (!eepromValid) { ui->eepromGroupBox->setDisabled(true); return; }
    else ui->eepromGroupBox->setEnabled(true);
    QString str = "invalid";
    if (valid) str="valid";
    ui->eepromValidLabel->setText(str);
    ui->eepromShaLabel->setText(QString::number(id,16));

    fCalibList.clear();
    for (int i=0; i<calibList.size(); i++)
    {
        fCalibList.push_back(calibList[i]);
    }

}
