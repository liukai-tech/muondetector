#include <i2cform.h>
#include <ui_i2cform.h>


I2cForm::I2cForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::I2cForm)
{
    ui->setupUi(this);
}


I2cForm::~I2cForm()
{
    delete ui;
}


void I2cForm::onI2cStatsReceived(quint32 bytesRead, quint32 bytesWritten, const QVector<I2cDeviceEntry>& deviceList)
{
	ui->nrDevicesLabel->setText("Nr. of devices: "+QString::number(deviceList.size()));
	ui->bytesReadLabel->setText("total bytes read: "+QString::number(bytesRead));
	ui->bytesWrittenLabel->setText("total bytes written: "+QString::number(bytesWritten));
	
	ui->devicesTableWidget->setRowCount(deviceList.size());
	for (int i=0; i<deviceList.size(); i++)
	{
		QTableWidgetItem *newItem1 = new QTableWidgetItem("0x"+QString("%1").arg(deviceList[i].address, 2, 16, QChar('0')));     
    	ui->devicesTableWidget->setItem(i, 0, newItem1);
		QTableWidgetItem *newItem2 = new QTableWidgetItem(deviceList[i].name);
    	ui->devicesTableWidget->setItem(i, 1, newItem2);
		QTableWidgetItem *newItem3 = new QTableWidgetItem((deviceList[i].online)?"online":"missing");
		if (deviceList[i].online) newItem3->setBackground(QBrush(Qt::green, Qt::SolidPattern));
		else newItem3->setBackground(QBrush(Qt::red, Qt::SolidPattern));
		ui->devicesTableWidget->setItem(i, 2, newItem3);
	}

}

void I2cForm::on_statsQueryPushButton_clicked()
{
    emit i2cStatsRequest();
}

void I2cForm::on_scanBusPushButton_clicked()
{
    emit scanI2cBusRequest();
}
