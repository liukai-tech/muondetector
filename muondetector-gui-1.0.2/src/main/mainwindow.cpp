#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <QThread>
#include <QFile>
#include <QKeyEvent>
#include <QDebug>
#include <QErrorMessage>
#include <gpio_pin_definitions.h>
#include <calib_struct.h>
#include <gnsssatellite.h>
#include <settings.h>
#include <status.h>
#include <tcpmessage_keys.h>
#include <map.h>
#include <i2cform.h>
#include <calibform.h>
#include <gpssatsform.h>
#include <iostream>

using namespace std;

QDataStream & operator >> (QDataStream& in, CalibStruct& calib)
{
	QString s1,s2,s3;
	quint16 u;
	in >> s1 >> s2;
	in >> u;
	in >> s3;
	calib.name = s1.toStdString();
	calib.type = s2.toStdString();
	calib.address = (uint16_t)u;
	calib.value = s3.toStdString();
	return in;
}

QDataStream& operator << (QDataStream& out, const CalibStruct& calib)
{
    out << QString::fromStdString(calib.name) << QString::fromStdString(calib.type)
     << (quint16)calib.address << QString::fromStdString(calib.value);
    return out;
}

QDataStream& operator >> (QDataStream& in, GnssSatellite& sat)
{
/*
	int fGnssId=0, fSatId=0, fCnr=0, fElev=0, fAzim=0;
	float fPrRes=0.;
	int fQuality=0, fHealth=0;
	int fOrbitSource=0;
	bool fUsed=false, fDiffCorr=false, fSmoothed=false;
*/
	in >> sat.fGnssId >> sat.fSatId >> sat.fCnr >> sat.fElev >> sat.fAzim
		>> sat.fPrRes >> sat.fQuality >> sat.fHealth >> sat.fOrbitSource
		>> sat.fUsed >> sat.fDiffCorr >> sat.fSmoothed;
	return in;
}


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    qRegisterMetaType<TcpMessage>("TcpMessage");
    qRegisterMetaType<GeodeticPos>("GeodeticPos");
    qRegisterMetaType<bool>("bool");
    qRegisterMetaType<I2cDeviceEntry>("I2cDeviceEntry");
    qRegisterMetaType<CalibStruct>("CalibStruct");
	qRegisterMetaType<std::vector<GnssSatellite>>("std::vector<GnssSatellite>");
    ui->setupUi(this);
	ui->discr1Layout->setAlignment(ui->discr1Slider, Qt::AlignHCenter);
    ui->discr2Layout->setAlignment(ui->discr2Slider, Qt::AlignHCenter); // aligns the slider in their vertical layout centered
#if defined(Q_OS_UNIX)
        QIcon icon("/usr/share/pixmaps/muon.ico");
#elif defined(Q_OS_WIN)
        QIcon icon("muon.ico");
#else
        QIcon icon("muon.ico");
#endif
	this->setWindowIcon(icon);
    setMaxThreshVoltage(1.0);

    // setup ipBox and load addresses etc.
    addresses = new QStandardItemModel(this);
    loadSettings(addresses);
	ui->ipBox->setModel(addresses);
	ui->ipBox->setAutoCompletion(true);
	ui->ipBox->setEditable(true);
	//ui->ipBox->installEventFilter(this);

	// setup colors
	ui->ipStatusLabel->setStyleSheet("QLabel {color : darkGray;}");/*
	ui->discr1Hit->setStyleSheet("QLabel {background-color : darkRed;}");
	ui->discr2Hit->setStyleSheet("QLabel {background-color : darkRed;}");*/

	// setup event filter
	ui->ipBox->installEventFilter(this);
	ui->ipButton->installEventFilter(this);

	// set timer for and/xor label color change after hit
    int timerInterval = 100; // in msec
	andTimer.setSingleShot(true);
	xorTimer.setSingleShot(true);
	andTimer.setInterval(timerInterval);
	xorTimer.setInterval(timerInterval);
	connect(&andTimer, &QTimer::timeout, this, &MainWindow::resetAndHit);
	connect(&xorTimer, &QTimer::timeout, this, &MainWindow::resetXorHit);

    // set timer for automatic rate poll
    if (automaticRatePoll){
        ratePollTimer.setInterval(5000);
        ratePollTimer.setSingleShot(false);
        connect(&ratePollTimer, &QTimer::timeout, this, &MainWindow::sendRequestGpioRates);
        connect(&ratePollTimer, &QTimer::timeout, this, &MainWindow::sendValueUpdateRequests);
        ratePollTimer.start();
    }

    // set all tabs
    ui->tabWidget->removeTab(0);
    Status *status = new Status(this);
    connect(this, &MainWindow::setUiEnabledStates, status, &Status::onUiEnabledStateChange);
    connect(this, &MainWindow::gpioRates, status, &Status::onGpioRatesReceived);
    connect(this, &MainWindow::adcSampleReceived, status, &Status::onAdcSampleReceived);
    connect(this, &MainWindow::dacReadbackReceived, status, &Status::onDacReadbackReceived);
    connect(status, &Status::inputSwitchChanged, this, &MainWindow::sendInputSwitch);
    connect(this, &MainWindow::inputSwitchReceived, status, &Status::onInputSwitchReceived);
    connect(this, &MainWindow::biasSwitchReceived, status, &Status::onBiasSwitchReceived);
    connect(status, &Status::biasSwitchChanged, this, &MainWindow::sendSetBiasStatus);
    connect(this, &MainWindow::preampSwitchReceived, status, &Status::onPreampSwitchReceived);
    connect(status, &Status::preamp1SwitchChanged, this, &MainWindow::sendPreamp1Switch);
    connect(status, &Status::preamp2SwitchChanged, this, &MainWindow::sendPreamp2Switch);
    connect(this, &MainWindow::gainSwitchReceived, status, &Status::onGainSwitchReceived);
    connect(status, &Status::gainSwitchChanged, this, &MainWindow::sendGainSwitch);
    connect(this, &MainWindow::temperatureReceived, status, &Status::onTemperatureReceived);
    
    ui->tabWidget->addTab(status,"status");

    Settings *settings = new Settings(this);
    connect(this, &MainWindow::setUiEnabledStates, settings, &Settings::onUiEnabledStateChange);
    connect(this, &MainWindow::txBufReceived, settings, &Settings::onTxBufReceived);
    connect(this, &MainWindow::txBufPeakReceived, settings, &Settings::onTxBufPeakReceived);
    ui->tabWidget->addTab(settings,"settings");

    Map *map = new Map(this);
    ui->tabWidget->addTab(map, "map");
    connect(this, &MainWindow::geodeticPos, map, &Map::onGeodeticPosReceived);
    connect(this, &MainWindow::addUbxMsgRates, settings, &Settings::addUbxMsgRates);
    connect(settings, &Settings::sendRequestUbxMsgRates, this, &MainWindow::sendRequestUbxMsgRates);
    connect(settings, &Settings::sendSetUbxMsgRateChanges, this, &MainWindow::sendSetUbxMsgRateChanges);



    I2cForm *i2cTab = new I2cForm(this);
//    connect(this, &MainWindow::setUiEnabledStates, settings, &Settings::onUiEnabledStateChange);
    connect(this, &MainWindow::i2cStatsReceived, i2cTab, &I2cForm::onI2cStatsReceived);
    connect(i2cTab, &I2cForm::i2cStatsRequest, this, [this]() { this->sendRequest(i2cStatsRequestSig); } );
    connect(i2cTab, &I2cForm::scanI2cBusRequest, this, [this]() { this->sendRequest(i2cScanBusRequestSig); } );

    ui->tabWidget->addTab(i2cTab,"I2C bus");

    calib = new CalibForm(this);
//    connect(this, &MainWindow::setUiEnabledStates, settings, &Settings::onUiEnabledStateChange);
    connect(this, &MainWindow::calibReceived, calib, &CalibForm::onCalibReceived);
    connect(calib, &CalibForm::calibRequest, this, [this]() { this->sendRequest(calibRequestSig); } );
    connect(calib, &CalibForm::writeCalibToEeprom, this, [this]() { this->sendRequest(calibWriteEepromSig); } );
    connect(this, &MainWindow::adcSampleReceived, calib, &CalibForm::onAdcSampleReceived);
    connect(calib, &CalibForm::setBiasDacVoltage, this, &MainWindow::sendSetBiasVoltage);
    connect(calib, &CalibForm::updatedCalib, this, &MainWindow::onCalibUpdated);
    ui->tabWidget->addTab(calib,"Calibration");


    GpsSatsForm *satsTab = new GpsSatsForm(this);
    connect(this, &MainWindow::satsReceived, satsTab, &GpsSatsForm::onSatsReceived);
    connect(this, &MainWindow::timeAccReceived, satsTab, &GpsSatsForm::onTimeAccReceived);
    connect(this, &MainWindow::intCounterReceived, satsTab, &GpsSatsForm::onIntCounterReceived);
    connect(this, &MainWindow::gpsMonHWReceived, satsTab, &GpsSatsForm::onGpsMonHWReceived);
    connect(this, &MainWindow::gpsVersionReceived, satsTab, &GpsSatsForm::onGpsVersionReceived);
    connect(this, &MainWindow::gpsFixReceived, satsTab, &GpsSatsForm::onGpsFixReceived);
    connect(this, &MainWindow::geodeticPos, satsTab, &GpsSatsForm::onGeodeticPosReceived);
    

/*
//    connect(this, &MainWindow::setUiEnabledStates, settings, &Settings::onUiEnabledStateChange);
    connect(this, &MainWindow::calibReceived, calibTab, &CalibForm::onCalibReceived);
    connect(calibTab, &CalibForm::calibRequest, this, [this]() { this->sendRequest(calibRequestSig); } );
    connect(calibTab, &CalibForm::writeCalibToEeprom, this, [this]() { this->sendRequest(calibWriteEepromSig); } );
    connect(this, &MainWindow::adcSampleReceived, calibTab, &CalibForm::onAdcSampleReceived);
*/    
	ui->tabWidget->addTab(satsTab,"GNSS/GPS Data");

	//sendRequest(calibRequestSig);

    //settings->show();
	// set menu bar actions
    //connect(ui->actionsettings, &QAction::triggered, this, &MainWindow::settings_clicked);

    const QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->biasControlTypeComboBox->model());
    QStandardItem *item = model->item(1);
    item->setEnabled(false);
    // initialise all ui elements that will be inactive at start
    uiSetDisconnectedState();
}

MainWindow::~MainWindow()
{
	emit closeConnection();
    saveSettings(addresses);
    delete ui;
}

void MainWindow::makeConnection(QString ipAddress, quint16 port) {
    // add popup windows for errors!!!
	QThread *tcpThread = new QThread();
	if (!tcpConnection) {
		delete(tcpConnection);
	}
	tcpConnection = new TcpConnection(ipAddress, port, verbose);
	tcpConnection->moveToThread(tcpThread);
	connect(tcpThread, &QThread::started, tcpConnection, &TcpConnection::makeConnection);
    connect(tcpThread, &QThread::finished, tcpThread, &TcpConnection::deleteLater);
	connect(tcpConnection, &TcpConnection::connected, this, &MainWindow::connected);
    connect(this, &MainWindow::closeConnection, tcpConnection, &TcpConnection::closeThisConnection);
    connect(this, &MainWindow::sendTcpMessage, tcpConnection, &TcpConnection::sendTcpMessage);
    connect(tcpConnection, &TcpConnection::receivedTcpMessage, this, &MainWindow::receivedTcpMessage);
	tcpThread->start();
}

bool MainWindow::saveSettings(QStandardItemModel *model) {
#if defined(Q_OS_UNIX)
    QFile file(QString("/usr/share/muondetector-gui/ipAddresses.save"));
#elif defined(Q_OS_WIN)
    QFile file(QString("ipAddresses.save"));
#else
    QFile file(QString("ipAddresses.save"));
#endif
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "file open failed in 'ReadWrite' mode at location " << file.fileName();
		return false;
	}
	QDataStream stream(&file);
	qint32 n(model->rowCount());
	stream << n;
	for (int i = 0; i < n; i++) {
		model->item(i)->write(stream);
	}
	file.close();
	return true;
}

bool MainWindow::loadSettings(QStandardItemModel* model) {
#if defined(Q_OS_UNIX)
    QFile file(QString("/usr/share/muondetector-gui/ipAddresses.save"));
#elif defined(Q_OS_WIN)
    QFile file(QString("ipAddresses.save"));
#else
    QFile file(QString("ipAddresses.save"));
#endif
	if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "file open failed in 'ReadOnly' mode at location " << file.fileName();
		return false;
	}
	QDataStream stream(&file);
	qint32 n;
	stream >> n;
	for (int i = 0; i < n; i++) {
		model->appendRow(new QStandardItem());
		model->item(i)->read(stream);
	}
	file.close();
	return true;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent *ke = static_cast<QKeyEvent *>(event);
		auto combobox = dynamic_cast<QComboBox *>(object);
		if (combobox == ui->ipBox) {
			if (ke->key() == Qt::Key_Delete) {
				ui->ipBox->removeItem(ui->ipBox->currentIndex());
			}
		}
		if (ke->key() == Qt::Key_Escape) {
			QCoreApplication::quit();
			//this->deleteLater();
		}
		if (ke->key() == Qt::Key_Enter) {
			this->on_ipButton_clicked();
		}
		return false;
	}
	else {
		return false;
	}
}

void MainWindow::receivedTcpMessage(TcpMessage tcpMessage) {
    quint16 msgID = tcpMessage.getMsgID();
	if (msgID == gpioPinSig) {
        quint8 gpioPin;
        *(tcpMessage.dStream) >> gpioPin;
        receivedGpioRisingEdge(gpioPin);
        return;
	}
	if (msgID == ubxMsgRate) {
		QMap<uint16_t, int> msgRateCfgs;
        *(tcpMessage.dStream) >> msgRateCfgs;
		emit addUbxMsgRates(msgRateCfgs);
		return;
    }
    if (msgID == threshSig){
        quint8 channel;
        float threshold;
        *(tcpMessage.dStream) >> channel >> threshold;
        if (threshold > maxThreshVoltage){
            sendSetThresh(channel,maxThreshVoltage);
            return;
        }
        sliderValues[channel] = (int)(2000 * threshold);
        updateUiProperties();
        return;
    }
    if (msgID == biasVoltageSig){
        *(tcpMessage.dStream) >> biasDacVoltage;
        updateUiProperties();
        return;
    }
    if (msgID == biasSig){
        *(tcpMessage.dStream) >> biasON;
        emit biasSwitchReceived(biasON);
        updateUiProperties();
        return;
    }
    if (msgID == preampSig){
        quint8 channel;
        bool state;
        *(tcpMessage.dStream) >> channel >> state;
        emit preampSwitchReceived(channel, state);
        updateUiProperties();
        return;
    }
    if (msgID == gainSwitchSig){
        bool gainSwitch;
        *(tcpMessage.dStream) >> gainSwitch;
        emit gainSwitchReceived(gainSwitch);
        updateUiProperties();
        return;
    }
    if (msgID == pcaChannelSig){
        *(tcpMessage.dStream) >> pcaPortMask;
        //status->setInputSwitchButtonGroup(pcaPortMask);
        emit inputSwitchReceived(pcaPortMask);
        updateUiProperties();
        return;
    }
    if (msgID == gpioRateSig){
        quint8 whichRate;
        QVector<QPointF> rate;
        *(tcpMessage.dStream) >> whichRate >> rate;
        float rateYValue;
        if (!rate.empty()){
            rateYValue = rate.at(rate.size()-1).y();
        }else{
            rateYValue = 0.0;
        }
        if (whichRate == 0){
            ui->rate1->setText(QString::number(rateYValue,'g',3)+"/s");
        }
        if (whichRate == 1){
            ui->rate2->setText(QString::number(rateYValue,'g',3)+"/s");
        }
        emit gpioRates(whichRate, rate);
        updateUiProperties();
        return;
    }
    if (msgID == quitConnectionSig){
        connectedToDemon = false;
        uiSetDisconnectedState();
    }
    if (msgID == geodeticPosSig){
        GeodeticPos pos;
        *(tcpMessage.dStream) >> pos.iTOW >> pos.lon >> pos.lat
                >> pos.height >> pos.hMSL >> pos.hAcc >> pos.vAcc;
        emit geodeticPos(pos);
    }
    if (msgID == adcSampleSig){
        quint8 channel;
        float value;
        *(tcpMessage.dStream) >> channel >> value;
        emit adcSampleReceived(channel, value);
        updateUiProperties();
        return;
    }
    if (msgID == dacReadbackSig){
        quint8 channel;
        float value;
        *(tcpMessage.dStream) >> channel >> value;
        emit dacReadbackReceived(channel, value);
        updateUiProperties();
        return;
    }
    if (msgID == temperatureSig){
        float value;
        *(tcpMessage.dStream) >> value;
        emit temperatureReceived(value);
        updateUiProperties();
        return;
    }
    if (msgID == i2cStatsSig){
		quint8 nrDevices=0;
		quint32 bytesRead = 0;
		quint32 bytesWritten = 0;
    	*(tcpMessage.dStream) >> nrDevices >> bytesRead >> bytesWritten;

		QVector<I2cDeviceEntry> deviceList;
		for (uint8_t i=0; i<nrDevices; i++)
		{
			uint8_t addr = 0;
			QString title = "none";
			uint8_t status = 0;
			*(tcpMessage.dStream) >> addr >> title >> status;
			I2cDeviceEntry entry;
			entry.address=addr;
			entry.name = title;
			entry.status=status;
			deviceList.push_back(entry);
		}
        emit i2cStatsReceived(bytesRead, bytesWritten, deviceList);
        //updateUiProperties();
        return;
    }
    if (msgID == calibSetSig){
		quint16 nrPars=0;
		quint64 id = 0;
		bool valid = false;
		bool eepromValid = 0;
    	*(tcpMessage.dStream) >> valid >> eepromValid >> id >> nrPars;

		QVector<CalibStruct> calibList;
		for (uint8_t i=0; i<nrPars; i++)
		{
			CalibStruct item;
			*(tcpMessage.dStream) >> item;
			calibList.push_back(item);
		}
        emit calibReceived(valid, eepromValid, id, calibList);
        return;
    }
    if (msgID == gpsSatsSig){
		int nrSats=0;    	
		*(tcpMessage.dStream) >> nrSats;

		QVector<GnssSatellite> satList;
		for (uint8_t i=0; i<nrSats; i++)
		{
			GnssSatellite sat;
			*(tcpMessage.dStream) >> sat;
			satList.push_back(sat);
		}
        emit satsReceived(satList);
        return;
    }
    if (msgID == gpsTimeAccSig){
	quint32 acc=0;    	
	*(tcpMessage.dStream) >> acc;
        emit timeAccReceived(acc);
        return;
    }
    if (msgID == gpsIntCounterSig){
	quint32 cnt=0;    	
	*(tcpMessage.dStream) >> cnt;
        emit intCounterReceived(cnt);
        return;
    }
    if (msgID == gpsTxBufSig){
	quint8 val=0;    	
	*(tcpMessage.dStream) >> val;
        emit txBufReceived(val);
        return;
    }
    if (msgID == gpsTxBufPeakSig){
	quint8 val=0;    	
	*(tcpMessage.dStream) >> val;
        emit txBufPeakReceived(val);
        return;
    }
    if (msgID == gpsMonHWSig){
	quint16 noise=0;    	
	quint16 agc=0;
	quint8 antStatus=0;
	quint8 antPower=0;
	quint8 jamInd=0;
	quint8 flags=0;
	*(tcpMessage.dStream) >> noise >> agc >> antStatus >> antPower >> jamInd >> flags;
        emit gpsMonHWReceived(noise,agc,antStatus,antPower,jamInd,flags);
        return;
    }
    if (msgID == gpsVersionSig){
	QString sw="";
	QString hw="";
	QString pv="";
	*(tcpMessage.dStream) >> sw >> hw >> pv;
        emit gpsVersionReceived(sw, hw, pv);
        return;
    }
    if (msgID == gpsFixSig){
	quint8 val=0;
	*(tcpMessage.dStream) >> val;
        emit gpsFixReceived(val);
        return;
    }
}

void MainWindow::sendRequest(quint16 requestSig){
    TcpMessage tcpMessage(requestSig);
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendRequest(quint16 requestSig, quint8 par){
    TcpMessage tcpMessage(requestSig);
    *(tcpMessage.dStream) << par;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendRequestUbxMsgRates(){
    TcpMessage tcpMessage(ubxMsgRateRequest);
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendSetBiasVoltage(float voltage){
    TcpMessage tcpMessage(biasVoltageSig);
    *(tcpMessage.dStream) << voltage;
    emit sendTcpMessage(tcpMessage);
    emit sendRequest(dacRequestSig, 2);
//    emit sendRequest(adcSampleRequestSig, 2);
//    emit sendRequest(adcSampleRequestSig, 3);
}

void MainWindow::sendSetBiasStatus(bool status){
    TcpMessage tcpMessage(biasSig);
    *(tcpMessage.dStream) << status;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendGainSwitch(bool status){
    TcpMessage tcpMessage(gainSwitchSig);
    *(tcpMessage.dStream) << status;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendPreamp1Switch(bool status){
    TcpMessage tcpMessage(preampSig);
    *(tcpMessage.dStream) << (quint8)0 << status;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendPreamp2Switch(bool status){
    TcpMessage tcpMessage(preampSig);
    *(tcpMessage.dStream) << (quint8)1 << status;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendSetThresh(uint8_t channel, float value){
    TcpMessage tcpMessage(threshSig);
    *(tcpMessage.dStream) << channel << value;
    emit sendTcpMessage(tcpMessage);
    emit sendRequest(dacRequestSig, channel);
}

void MainWindow::sendSetUbxMsgRateChanges(QMap<uint16_t, int> changes){
    TcpMessage tcpMessage(ubxMsgRate);
    *(tcpMessage.dStream) << changes;
    emit sendTcpMessage(tcpMessage);
}

void MainWindow::sendRequestGpioRates(){
    TcpMessage xorRateRequest(gpioRateRequestSig);
    *(xorRateRequest.dStream) << (quint16)5 << (quint8)0;
    emit sendTcpMessage(xorRateRequest);
    TcpMessage andRateRequest(gpioRateRequestSig);
    *(andRateRequest.dStream) << (quint16)5 << (quint8)1;
    emit sendTcpMessage(andRateRequest);
}

void MainWindow::sendRequestGpioRateBuffer(){
    TcpMessage xorRateRequest(gpioRateRequestSig);
    *(xorRateRequest.dStream) << (quint16)0 << (quint8)0;
    emit sendTcpMessage(xorRateRequest);
    TcpMessage andRateRequest(gpioRateRequestSig);
    *(andRateRequest.dStream) << (quint16)0 << (quint8)1;
    emit sendTcpMessage(andRateRequest);
}

void MainWindow::receivedGpioRisingEdge(quint8 pin) {
	if (pin == EVT_AND) {
		ui->ANDHit->setStyleSheet("QLabel {color: white; background-color: darkGreen;}");
		andTimer.start();
	}
	if (pin == EVT_XOR) {
		ui->XORHit->setStyleSheet("QLabel {color: white; background-color: darkGreen;}");
		xorTimer.start();
	}
}

void MainWindow::resetAndHit() {
	ui->ANDHit->setStyleSheet("QLabel {color: white; background-color: darkRed;}");
}
void MainWindow::resetXorHit() {
	ui->XORHit->setStyleSheet("QLabel {color: white; background-color: darkRed;}");
}

void MainWindow::uiSetDisconnectedState() {
	// set button and color of label
	ui->ipStatusLabel->setStyleSheet("QLabel {color: darkGray;}");
	ui->ipStatusLabel->setText("not connected");
	ui->ipButton->setText("connect");
	ui->ipBox->setEnabled(true);
    // disable all relevant objects of mainwindow
	ui->discr1Label->setStyleSheet("QLabel {color: darkGray;}");
	ui->discr2Label->setStyleSheet("QLabel {color: darkGray;}");
	ui->discr1Slider->setValue(0);
	ui->discr1Slider->setDisabled(true);
	ui->discr1Edit->clear();
	ui->discr1Edit->setDisabled(true);
	ui->discr2Slider->setValue(0);
	ui->discr2Slider->setDisabled(true);
	ui->discr2Edit->clear();
	ui->discr2Edit->setDisabled(true);
	ui->ANDHit->setDisabled(true);
	ui->ANDHit->setStyleSheet("QLabel {color: darkGray;}");
	ui->XORHit->setDisabled(true);
    ui->XORHit->setStyleSheet("QLabel {color: darkGray;}");
    ui->rate1->setDisabled(true);
    ui->rate2->setDisabled(true);
	ui->biasPowerLabel->setDisabled(true);
	ui->biasPowerLabel->setStyleSheet("QLabel {color: darkGray;}");
	ui->biasPowerButton->setDisabled(true);
    // disable other widgets
    emit setUiEnabledStates(false);
}

void MainWindow::uiSetConnectedState() {
	// change color and text of labels and buttons
	ui->ipStatusLabel->setStyleSheet("QLabel {color: darkGreen;}");
	ui->ipStatusLabel->setText("connected");
	ui->ipButton->setText("disconnect");
	ui->ipBox->setDisabled(true);
	ui->discr1Label->setStyleSheet("QLabel {color: black;}");
	ui->discr2Label->setStyleSheet("QLabel {color: black;}");
    // enable other widgets
    emit setUiEnabledStates(true);
}

void MainWindow::updateUiProperties() {
    mouseHold = true;

    ui->discr1Slider->setEnabled(true);
    ui->discr1Slider->setValue(sliderValues.at(0));
    ui->discr1Edit->setEnabled(true);
    ui->discr1Edit->setText(QString::number(sliderValues.at(0) / 2.0) + "mV");

    ui->discr2Slider->setEnabled(true);
    ui->discr2Slider->setValue(sliderValues.at(1));
    ui->discr2Edit->setEnabled(true);
    ui->discr2Edit->setText(QString::number(sliderValues.at(1) / 2.0) + "mV");
    double biasVoltage = biasCalibOffset + biasDacVoltage*biasCalibSlope;
    ui->biasVoltageDoubleSpinBox->setValue(biasVoltage);
    ui->biasVoltageSlider->setValue(100*biasVoltage/maxBiasVoltage);
    // equation:
    // UBias = c1*UDac + c0
    // (UBias - c0)/c1 = UDac

	ui->ANDHit->setEnabled(true);
	ui->ANDHit->setStyleSheet("QLabel {background-color: darkRed; color: white;}");
	ui->XORHit->setEnabled(true);
	ui->XORHit->setStyleSheet("QLabel {background-color: darkRed; color: white;}");
    ui->rate1->setEnabled(true);
    ui->rate2->setEnabled(true);
	ui->biasPowerButton->setEnabled(true);
	ui->biasPowerLabel->setEnabled(true);
    if (biasON) {
		ui->biasPowerButton->setText("Disable Bias");
		ui->biasPowerLabel->setText("Bias ON");
		ui->biasPowerLabel->setStyleSheet("QLabel {background-color: darkGreen; color: white;}");
	}
	else {
		ui->biasPowerButton->setText("Enable Bias");
		ui->biasPowerLabel->setText("Bias OFF");
		ui->biasPowerLabel->setStyleSheet("QLabel {background-color: red; color: white;}");
	}
	mouseHold = false;
}

void MainWindow::connected() {
    connectedToDemon = true;
    saveSettings(addresses);
    uiSetConnectedState();
    sendRequest(biasVoltageRequestSig);
    sendRequest(biasRequestSig);
    sendRequest(preampRequestSig,0);
    sendRequest(preampRequestSig,1);
    sendRequest(threshRequestSig);
    sendRequest(dacRequestSig,0);
    sendRequest(dacRequestSig,1);
    sendRequest(dacRequestSig,2);
    sendRequest(dacRequestSig,3);
    //sendRequest(adcSampleRequestSig,0);
    sendRequest(adcSampleRequestSig,1);
    sendRequest(adcSampleRequestSig,2);
    sendRequest(adcSampleRequestSig,3);
    sendRequest(pcaChannelRequestSig);
    sendRequestUbxMsgRates();
    sendRequestGpioRateBuffer();
    sendRequest(temperatureRequestSig);
    sendRequest(i2cStatsRequestSig);
    sendRequest(calibRequestSig);
}


void MainWindow::sendValueUpdateRequests() {
    sendRequest(biasVoltageRequestSig);
//    sendRequest(biasRequestSig);
//    sendRequest(preampRequestSig,0);
//    sendRequest(preampRequestSig,1);
//    sendRequest(threshRequestSig);
    sendRequest(dacRequestSig,0);
    sendRequest(dacRequestSig,1);
    sendRequest(dacRequestSig,2);
    sendRequest(dacRequestSig,3);
    //sendRequest(adcSampleRequestSig,0);
    sendRequest(adcSampleRequestSig,1);
    sendRequest(adcSampleRequestSig,2);
    sendRequest(adcSampleRequestSig,3);
//    sendRequest(pcaChannelRequestSig);
//    sendRequestUbxMsgRates();
//    sendRequestGpioRateBuffer();
    sendRequest(temperatureRequestSig);
    sendRequest(i2cStatsRequestSig);
//    sendRequest(calibRequestSig);
}

void MainWindow::on_ipButton_clicked()
{
	if (connectedToDemon) {
		// it is connected and the button shows "disconnect" -> here comes disconnect code
		connectedToDemon = false;
		emit closeConnection();
		andTimer.stop();
		xorTimer.stop();
		uiSetDisconnectedState();
		return;
	}
	QString ipBoxText = ui->ipBox->currentText();
    QStringList ipAndPort = ipBoxText.split(':');
    if (ipAndPort.size() > 2 || ipAndPort.size() < 1) {
        QString errorMess = "error, size of ipAndPort not 1 or 2";
		errorM.showMessage(errorMess);
        return;
    }
	QString ipAddress = ipAndPort.at(0);
	if (ipAddress == "local" || ipAddress == "localhost") {
		ipAddress = "127.0.0.1";
    }
	QString portString;
    if (ipAndPort.size() == 2) {
		portString = ipAndPort.at(1);
	}
	else {
		portString = "51508";
    }
    makeConnection(ipAddress, portString.toUInt());
    if (!ui->ipBox->currentText().isEmpty() && ui->ipBox->findText(ui->ipBox->currentText()) == -1) {
		// if text not already in there, put it in there
		ui->ipBox->addItem(ui->ipBox->currentText());
	}
}

void MainWindow::on_discr1Slider_sliderPressed()
{
	mouseHold = true;
}

void MainWindow::on_discr1Slider_sliderReleased()
{
	mouseHold = false;
	on_discr1Slider_valueChanged(ui->discr1Slider->value());
}

void MainWindow::on_discr1Edit_editingFinished()
{
	float value = parseValue(ui->discr1Edit->text());
	if (value < 0) {
		return;
	}
	ui->discr1Slider->setValue((int)(value * 2 + 0.5));
}

void MainWindow::on_discr1Slider_valueChanged(int value)
{
    float thresh0 = (float)(value / 2000.0);
	ui->discr1Edit->setText(QString::number((float)value / 2.0) + "mV");
    if (!mouseHold) {
        sendSetThresh(0, thresh0);
	}
}

void MainWindow::on_discr2Slider_sliderPressed()
{
	mouseHold = true;
}

void MainWindow::on_discr2Slider_sliderReleased()
{
	mouseHold = false;
	on_discr2Slider_valueChanged(ui->discr2Slider->value());
}

void MainWindow::on_discr2Edit_editingFinished()
{
	float value = parseValue(ui->discr2Edit->text());
	if (value < 0) {
		return;
	}
	ui->discr2Slider->setValue((int)(value * 2 + 0.5));
}

void MainWindow::on_discr2Slider_valueChanged(int value)
{
    float thresh1 =  (float)(value / 2000.0);
	ui->discr2Edit->setText(QString::number((float)(value / 2.0)) + "mV");
    if (!mouseHold) {
        sendSetThresh(1, thresh1);
	}
}
void MainWindow::setMaxThreshVoltage(float voltage){
    // we have 0.5 mV resolution so we have (int)(mVolts)*2 steps on the slider
    // the '+0.5' is to round up or down like in mathematics
    maxThreshVoltage = voltage;
    int maximum = (int)(voltage*2000+0.5);
    ui->discr1Slider->setMaximum(maximum);
    ui->discr2Slider->setMaximum(maximum);
    int bigger = (sliderValues.at(0)>sliderValues.at(1))?0:1;
    if( sliderValues.at(bigger) > maximum){
        sendSetThresh(bigger,voltage);
        if (sliderValues.at(!bigger) > maximum){
            sendSetThresh(!bigger,voltage);
        }
    }
}
float MainWindow::parseValue(QString text) {
	// ignores everything that is not a number or at least most of it
	QRegExp alphabetical = QRegExp("[a-z]+[A-Z]+");
	QRegExp specialCharacters = QRegExp(
		QString::fromUtf8("[\\-`~!@#\\$%\\^\\&\\*()_\\—\\+=|:;<>«»\\?/{}\'\"ß\\\\]+"));
	text = text.simplified();
	text = text.replace(" ", "");
	text = text.remove(alphabetical);
	text = text.replace(",", ".");
	text = text.remove(specialCharacters);
	bool ok;
	float value = text.toFloat(&ok);
	if (!ok) {
		errorM.showMessage("failed to parse discr1Edit to float");
		return -1;
	}
	return value;
}

void MainWindow::on_biasPowerButton_clicked()
{
    sendSetBiasStatus(!biasON);
}

void MainWindow::sendInputSwitch(int id) {
    TcpMessage tcpMessage(pcaChannelSig);
    *(tcpMessage.dStream) << (quint8)id;
    emit sendTcpMessage(tcpMessage);
    sendRequest(pcaChannelRequestSig);
}

void MainWindow::on_biasVoltageSlider_sliderReleased()
{
    mouseHold = false;
    on_biasVoltageSlider_valueChanged(ui->biasVoltageSlider->value());
}

void MainWindow::on_biasVoltageSlider_valueChanged(int value)
{
    if (!mouseHold)
    {
        double biasVoltage = (double)value/ui->biasVoltageSlider->maximum()*maxBiasVoltage;
        if (fabs(biasCalibSlope)<1e-5) return;
        double dacVoltage = (biasVoltage-biasCalibOffset)/biasCalibSlope;
        if (dacVoltage<0.) dacVoltage=0.;
        if (dacVoltage>3.3) dacVoltage=3.3;
        sendSetBiasVoltage(dacVoltage);
    }
    // equation:
    // UBias = c1*UDac + c0
    // (UBias - c0)/c1 = UDac
}

void MainWindow::on_biasVoltageSlider_sliderPressed()
{
    mouseHold=true;
}

void MainWindow::onCalibUpdated(const QVector<CalibStruct>& items)
{
    if (calib==nullptr) return;

    TcpMessage tcpMessage(calibSetSig);
    if (items.size()) {
        *(tcpMessage.dStream) << (quint8)items.size();
        for (int i=0; i<items.size(); i++) {
            *(tcpMessage.dStream) << items[i];
        }
        emit sendTcpMessage(tcpMessage);
    }

    uint8_t flags = calib->getCalibParameter("CALIB_FLAGS").toUInt();
    bool calibedBias = false;
    if (flags & CalibStruct::CALIBFLAGS_VOLTAGE_COEFFS) calibedBias=true;

    const QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->biasControlTypeComboBox->model());
    QStandardItem *item = model->item(1);

    item->setEnabled(calibedBias);
/*
    item->setFlags(disable ? item->flags() & ~(Qt::ItemIsSelectable|Qt::ItemIsEnabled)
                           : Qt::ItemIsSelectable|Qt::ItemIsEnabled));
    // visually disable by greying out - works only if combobox has been painted already and palette returns the wanted color
    item->setData(disable ? ui->comboBox->palette().color(QPalette::Disabled, QPalette::Text)
                          : QVariant(), // clear item data in order to use default color
                  Qt::TextColorRole);
*/
    ui->biasControlTypeComboBox->setCurrentIndex((calibedBias)?1:0);
}

void MainWindow::on_biasControlTypeComboBox_currentIndexChanged(int index)
{
    if (index==1) {
        if (calib==nullptr) return;
        QString str = calib->getCalibParameter("COEFF0");
        if (!str.size()) return;
        double c0 = str.toDouble();
        str = calib->getCalibParameter("COEFF1");
        if (!str.size()) return;
        double c1 = str.toDouble();
        biasCalibOffset=c0; biasCalibSlope=c1;
        minBiasVoltage=0.; maxBiasVoltage=40.;
        ui->biasVoltageDoubleSpinBox->setMaximum(maxBiasVoltage);
        ui->biasVoltageDoubleSpinBox->setSingleStep(0.1);
    } else {
        biasCalibOffset=0.; biasCalibSlope=1.;
        minBiasVoltage=0.; maxBiasVoltage=3.3;
        ui->biasVoltageDoubleSpinBox->setMaximum(maxBiasVoltage);
        ui->biasVoltageDoubleSpinBox->setSingleStep(0.01);
    }
}
