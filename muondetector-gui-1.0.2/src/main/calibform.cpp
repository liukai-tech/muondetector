#include "calibform.h"
#include "ui_calibform.h"
#include <calib_struct.h>

CalibForm::CalibForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalibForm)
{
    ui->setupUi(this);
}

CalibForm::~CalibForm()
{
    delete ui;
}

void CalibForm::onCalibReceived(bool valid, bool eepromValid, quint64 id, const QVector<CalibStruct> & calibList)
{
    QString str = "invalid";
    if (eepromValid) str="valid";
    ui->eepromValidLabel->setText("EEPROM data: "+str);
    str = "invalid";
    if (valid) str="valid";
    ui->calibValidLabel->setText("Calib data: "+str);
    ui->idLineEdit->setText(QString::number(id,16));

    ui->calibItemTableWidget->setRowCount(calibList.size());
    fCalibList.clear();
    for (int i=0; i<calibList.size(); i++)
    {
        fCalibList.push_back(calibList[i]);
        QTableWidgetItem *newItem1 = new QTableWidgetItem(QString::fromStdString(calibList[i].name));
        ui->calibItemTableWidget->setItem(i, 0, newItem1);
        QString type = QString::fromStdString(calibList[i].type);
        QString numberstr = "";
        if (type=="FLOAT") {
            double val = QString::fromStdString(calibList[i].value).toDouble(NULL);
            numberstr = QString::number(val);
        } else {
            numberstr = QString::fromStdString(calibList[i].value);
        }

        QTableWidgetItem *newItem2 = new QTableWidgetItem(type);
        ui->calibItemTableWidget->setItem(i, 1, newItem2);
        QTableWidgetItem *newItem3 = new QTableWidgetItem(numberstr);
        ui->calibItemTableWidget->setItem(i, 2, newItem3);
        QTableWidgetItem *newItem4 = new QTableWidgetItem("0x"+QString("%1").arg(calibList[i].address, 2, 16, QChar('0')));
        ui->calibItemTableWidget->setItem(i, 3, newItem4);
    }

}

void CalibForm::onAdcSampleReceived(uint8_t channel, float value)
{
    if (channel == 3) {
        ui->biasAdcLineEdit->setText(QString::number(value));
        if (!fCalibList.empty()) {
            auto result = std::find_if(fCalibList.begin(), fCalibList.end(), [](const CalibStruct& s){ return s.name=="VDIV"; } );
            if (result != fCalibList.end()) {
                double vdiv = QString::fromStdString(result->value).toDouble(NULL);
                double ubias = vdiv*value/100.;
                ui->biasVoltageLineEdit->setText(QString::number(ubias));
            }
        }
    }
}

void CalibForm::on_readCalibPushButton_clicked()
{
    // calib reread triggered
    emit calibRequest();
}


void CalibForm::on_writeEepromPushButton_clicked()
{
    // write eeprom clicked
    emit writeCalibToEeprom();
}
