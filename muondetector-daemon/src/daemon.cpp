#include <QtNetwork>
#include <chrono>
#include <time.h>
#include <QThread>
#include <QNetworkInterface>
#include <daemon.h>
#include <gpio_pin_definitions.h>
#include <gpio_mapping.h>
//#include <calib_struct.h>
#include <ublox_messages.h>
#include <tcpmessage_keys.h>
#include <iomanip>      // std::setfill, std::setw
#include <locale>
#include <iostream>
#include <muondetector_structs.h>

// for i2cdetect:
extern "C" {
#include <custom_i2cdetect.h>
}

#define DAC_BIAS 2 // channel of the dac where bias voltage is set
#define DAC_TH1 0 // channel of the dac where threshold 1 is set
#define DAC_TH2 1 // channel of the dac where threshold 2 is set

#define OLED_UPDATE_PERIOD 2000
#define DEGREE_CHARCODE 248

#define ADC_SAMPLEBUFFER_SIZE 50
#define ADC_PRETRIGGER 10
#define TRACE_SAMPLING_INTERVAL 5  // free running adc sampling interval in ms

extern QDataStream& operator << (QDataStream& out, const CalibStruct& calib);
extern QDataStream& operator >> (QDataStream& in, CalibStruct& calib);

const QVector<QString> FIX_TYPE_STRINGS = { "No Fix", "Dead Reck." , "2D-Fix", "3D-Fix", "GPS+Dead Reck.", "Time Fix"  };

// REMEMBER: "emit" keyword is just syntactic sugar and not needed AT ALL ... learned it after 1 year *clap* *clap*

using namespace std;


static unsigned int HW_VERSION = 0; // default value is set in calibration.h


int64_t msecdiff(timespec &ts, timespec &st){
    int64_t diff;
    diff = (int64_t)ts.tv_sec - (int64_t)st.tv_sec;
    diff *= 1000;
    diff += ((int64_t)ts.tv_nsec-(int64_t)st.tv_nsec)/1000000;
    return diff;
}

static QVector<uint16_t> allMsgCfgID({
	//   UBX_CFG_ANT, UBX_CFG_CFG, UBX_CFG_DAT, UBX_CFG_DOSC,
	//   UBX_CFG_DYNSEED, UBX_CFG_ESRC, UBX_CFG_FIXSEED, UBX_CFG_GEOFENCE,
	//   UBX_CFG_GNSS, UBX_CFG_INF, UBX_CFG_ITFM, UBX_CFG_LOGFILTER,
	//   UBX_CFG_MSG, UBX_CFG_NAV5, UBX_CFG_NAVX5, UBX_CFG_NMEA,
	//   UBX_CFG_ODO, UBX_CFG_PM2, UBX_CFG_PMS, UBX_CFG_PRT, UBX_CFG_PWR,
	//   UBX_CFG_RATE, UBX_CFG_RINV, UBX_CFG_RST, UBX_CFG_RXM, UBX_CFG_SBAS,
	//   UBX_CFG_SMGR, UBX_CFG_TMODE2, UBX_CFG_TP5, UBX_CFG_TXSLOT, UBX_CFG_USB
		 UBX_TIM_TM2,UBX_TIM_TP,
		 UBX_NAV_CLOCK, UBX_NAV_DGPS, UBX_NAV_AOPSTATUS, UBX_NAV_DOP,
		 UBX_NAV_POSECEF, UBX_NAV_POSLLH, UBX_NAV_PVT, UBX_NAV_SBAS, UBX_NAV_SOL,
		 UBX_NAV_STATUS, UBX_NAV_SVINFO, UBX_NAV_TIMEGPS, UBX_NAV_TIMEUTC, UBX_NAV_VELECEF,
		 UBX_NAV_VELNED, /* UBX_NAV_SAT, */
		 UBX_MON_HW, UBX_MON_HW2, UBX_MON_IO, UBX_MON_MSGPP,
         UBX_MON_RXBUF, UBX_MON_RXR, UBX_MON_TXBUF
	});

/*
QDataStream& operator << (QDataStream& out, const CalibStruct& calib)
{
	out << QString::fromStdString(calib.name) << QString::fromStdString(calib.type)
	 << (quint16)calib.address << QString::fromStdString(calib.value);
    return out;
}

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
*/

QDataStream& operator << (QDataStream& out, const GnssSatellite& sat)
{
	out << sat.fGnssId << sat.fSatId << sat.fCnr << sat.fElev << sat.fAzim
		<< sat.fPrRes << sat.fQuality << sat.fHealth << sat.fOrbitSource
		<< sat.fUsed << sat.fDiffCorr << sat.fSmoothed;
	return out;
}

QDataStream& operator << (QDataStream& out, const UbxTimePulseStruct& tp)
{
	out << tp.tpIndex << tp.version << tp.antCableDelay << tp.rfGroupDelay
	<< tp.freqPeriod << tp.freqPeriodLock << tp.pulseLenRatio << tp.pulseLenRatioLock
	<< tp.userConfigDelay << tp.flags;
    return out;
}

QDataStream& operator >> (QDataStream& in, UbxTimePulseStruct& tp)
{
    in >> tp.tpIndex >> tp.version >> tp.antCableDelay >> tp.rfGroupDelay
    >> tp.freqPeriod >> tp.freqPeriodLock >> tp.pulseLenRatio >> tp.pulseLenRatioLock
    >> tp.userConfigDelay >> tp.flags;
    return in;
}

QDataStream& operator << (QDataStream& out, const Histogram& h)
{
	out << QString::fromStdString(h.fName) << h.fMin << h.fMax << h.fUnderflow << h.fOverflow << h.fNrBins;
	for (int i=0; i<h.fNrBins; i++) {
		out << h.getBinContent(i);
	}
	out << QString::fromStdString(h.fUnit);
    return out;
}

// signal handling stuff: put code to execute before shutdown down there
static int setup_unix_signal_handlers()
{
	struct sigaction hup, term, inte;

	hup.sa_handler = Daemon::hupSignalHandler;
	sigemptyset(&hup.sa_mask);
	hup.sa_flags = 0;
	hup.sa_flags |= SA_RESTART;

	if (sigaction(SIGHUP, &hup, 0)) {
		return 1;
	}

	term.sa_handler = Daemon::termSignalHandler;
	sigemptyset(&term.sa_mask);
	term.sa_flags = 0;
	term.sa_flags |= SA_RESTART;

	if (sigaction(SIGTERM, &term, 0)) {
		return 2;
	}

	inte.sa_handler = Daemon::intSignalHandler;
	sigemptyset(&inte.sa_mask);
	inte.sa_flags = 0;
	inte.sa_flags |= SA_RESTART;

	if (sigaction(SIGINT, &inte, 0)) {
		return 3;
	}
	return 0;
}
int Daemon::sighupFd[2];
int Daemon::sigtermFd[2];
int Daemon::sigintFd[2];
void Daemon::handleSigTerm()
{
	snTerm->setEnabled(false);
	char tmp;
	::read(sigtermFd[1], &tmp, sizeof(tmp));

	// do Qt stuff
	if (verbose > 1) {
		cout << "\nSIGTERM received" << endl;
	}
    emit aboutToQuit();
	exit(0);
	snTerm->setEnabled(true);
}
void Daemon::handleSigHup()
{
	snHup->setEnabled(false);
	char tmp;
	::read(sighupFd[1], &tmp, sizeof(tmp));

	// do Qt stuff
	if (verbose > 1) {
		cout << "\nSIGHUP received" << endl;
	}
    emit aboutToQuit();
	exit(0);
	snHup->setEnabled(true);
}
void Daemon::handleSigInt()
{
	snInt->setEnabled(false);
	char tmp;
	::read(sigintFd[1], &tmp, sizeof(tmp));

	// do Qt stuff
	if (verbose > 1) {
		cout << "\nSIGINT received" << endl;
	}
	if (showin || showout) {
		qDebug() << allMsgCfgID.size();
		qDebug() << msgRateCfgs.size();
		for (QMap<uint16_t, int>::iterator it = msgRateCfgs.begin(); it != msgRateCfgs.end(); it++) {
			qDebug().nospace() << "0x" << hex << (uint8_t)(it.key() >> 8) << " 0x" << hex << (uint8_t)(it.key() & 0xff) << " " << dec << it.value();
		}
	}
    emit aboutToQuit();
	exit(0);
	snInt->setEnabled(true);
}


// begin of the Daemon class
Daemon::Daemon(QString username, QString password, QString new_gpsdevname, int new_verbose, quint8 new_pcaPortMask,
    float *new_dacThresh, float new_biasVoltage, bool bias_ON, bool new_dumpRaw, int new_baudrate,
    bool new_configGnss, unsigned int new_eventTrigger, QString new_peerAddress, quint16 new_peerPort,
    QString new_daemonAddress, quint16 new_daemonPort, bool new_showout, bool new_showin, bool preamp1, bool preamp2, bool gain, QObject *parent)
	: QTcpServer(parent)
{

	// first, we must set the locale to be independent of the number format of the system's locale.
	// We rely on parsing floating point numbers with a decimal point (not a komma) which might fail if not setting the classic locale
	//	std::locale::global( std::locale( std::cout.getloc(), new punct_facet<char, '.'>) ) );
	//	std::locale mylocale( std::locale( std::cout.getloc(), new punct_facet<char, '.'>) );
	std::locale::global(std::locale::classic());

    qRegisterMetaType<TcpMessage>("TcpMessage");
    qRegisterMetaType<GeodeticPos>("GeodeticPos");
    qRegisterMetaType<int32_t>("int32_t");
    qRegisterMetaType<uint32_t>("uint32_t");
    qRegisterMetaType<uint16_t>("uint16_t");
    qRegisterMetaType<uint8_t>("uint8_t");
    qRegisterMetaType<int8_t>("int8_t");
    qRegisterMetaType<CalibStruct>("CalibStruct");
	qRegisterMetaType<std::vector<GnssSatellite>>("std::vector<GnssSatellite>");
	qRegisterMetaType<std::vector<GnssConfigStruct>>("std::vector<GnssConfigStruct>");
	qRegisterMetaType<std::chrono::duration<double>>("std::chrono::duration<double>");
	qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<LogParameter>("LogParameter");
    qRegisterMetaType<UbxTimePulseStruct>("UbxTimePulseStruct");
    qRegisterMetaType<UbxDopStruct>("UbxDopStruct");
    qRegisterMetaType<timespec>("timespec");
    qRegisterMetaType<GPIO_PIN>("GPIO_PIN");
    
    // signal handling
	setup_unix_signal_handlers();
	if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sighupFd)) {
		qFatal("Couldn't create HUP socketpair");
	}

	if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigtermFd)) {
		qFatal("Couldn't create TERM socketpair");
	}
	if (::socketpair(AF_UNIX, SOCK_STREAM, 0, sigintFd)) {
		qFatal("Couldn't createe INT socketpair");
	}

	snHup = new QSocketNotifier(sighupFd[1], QSocketNotifier::Read, this);
	connect(snHup, SIGNAL(activated(int)), this, SLOT(handleSigHup()));
	snTerm = new QSocketNotifier(sigtermFd[1], QSocketNotifier::Read, this);
	connect(snTerm, SIGNAL(activated(int)), this, SLOT(handleSigTerm()));
	snInt = new QSocketNotifier(sigintFd[1], QSocketNotifier::Read, this);
	connect(snInt, SIGNAL(activated(int)), this, SLOT(handleSigInt()));

	// general
	verbose = new_verbose;
	if (verbose > 4) {
        cout << "daemon running in thread " << QString("0x%1").arg((intptr_t)this->thread()) << endl;
    }

	// try to find out on which hardware version we are running
	// for this to work, we have to initialize and read the eeprom first
	// EEPROM 24AA02 type
	eep = new EEPROM24AA02();
	calib = new ShowerDetectorCalib(eep);
	if (eep->devicePresent()) {
//		readEeprom();
		calib->readFromEeprom();
		if (verbose>1) {
			cout<<"eep device is present."<<endl;
//			readEeprom();
//			calib->readFromEeprom();
			uint64_t id=calib->getSerialID();
			cout<<"unique ID: 0x"<<hex<<id<<dec<<endl;
			
			if (1==0) {
				uint8_t buf[256];
				for (int i=0; i<256; i++) buf[i]=i;
				if (!eep->writeBytes(0, 256, buf)) cerr<<"error: write to eeprom failed!"<<endl;
				if (verbose>2) cout<<"eep write took "<<eep->getLastTimeInterval()<<" ms"<<endl;
				readEeprom();
			}
            if (1==1) {
				calib->printCalibList();

/*
				calib->setCalibItem("VERSION", (uint8_t)1);
				calib->setCalibItem("DATE", (uint32_t)time(NULL));
				calib->setCalibItem("CALIB_FLAGS", (uint8_t)1);
				calib->setCalibItem("FEATURE_FLAGS", (uint8_t)1);
				calib->setCalibItem("RSENSE", (uint16_t)205);
				calib->setCalibItem("COEFF0", (float)3.1415926535);
				calib->setCalibItem("COEFF1", (float)-1.23456e-4);
				calib->setCalibItem("WRITE_CYCLES", (uint32_t)5);

				calib->printCalibList();
				calib->updateBuffer();
				calib->printBuffer();
				//calib->writeToEeprom();
				readEeprom();
*/
			}
		}
        //if (calib->isValid()) {

        //}
    } else {
        cerr<<"eeprom device NOT present!"<<endl;
    }
    CalibStruct verStruct = calib->getCalibItem("VERSION");
    unsigned int version=0;
    ShowerDetectorCalib::getValueFromString(verStruct.value,version);
    if (version>0) {
        HW_VERSION=version;
        if (verbose>1) cout<<"found HW version "<<version<<" in eeprom"<<endl;
        }

	// set up the pin definitions (hw version specific)
	GPIO_PINMAP=GPIO_PINMAP_VERSIONS[HW_VERSION];

	if (verbose>1) {
		cout<<"GPIO pin mapping:"<<endl;
		
		for (auto signalIt=GPIO_PINMAP.begin(); signalIt!=GPIO_PINMAP.end(); signalIt++) {
			const GPIO_PIN signalId=signalIt->first;
			cout<<GPIO_SIGNAL_MAP[signalId].name<<"   \t: "<<signalIt->second;
			switch (GPIO_SIGNAL_MAP[signalId].direction) {
				case DIR_IN: cout<<" (in)";
					break;
				case DIR_OUT: cout<<" (out)";
					break;
				case DIR_IO: cout<<" (i/o)";
					break;
				default: cout<<" (undef)";
			}
			cout<<endl;
		}
/*		cout<<" EVT_AND     : "<<GPIO_PINMAP[EVT_AND]<<endl;
		cout<<" EVT_XOR     : "<<GPIO_PINMAP[EVT_XOR]<<endl;
		cout<<" UBIAS_EN    : "<<GPIO_PINMAP[UBIAS_EN]<<endl;
		cout<<" PREAMP_1    : "<<GPIO_PINMAP[PREAMP_1]<<endl;
		cout<<" PREAMP_2    : "<<GPIO_PINMAP[PREAMP_2]<<endl;
		cout<<" GAIN_HL     : "<<GPIO_PINMAP[GAIN_HL]<<endl;
		cout<<" TIMEPULSE   : "<<GPIO_PINMAP[TIMEPULSE]<<endl;
		cout<<" ADC_READY   : "<<GPIO_PINMAP[ADC_READY]<<endl;
		cout<<" STATUS1     : "<<GPIO_PINMAP[STATUS1]<<endl;
		cout<<" STATUS2     : "<<GPIO_PINMAP[STATUS2]<<endl;
		cout<<" PREAMP_FAULT: "<<GPIO_PINMAP[PREAMP_FAULT]<<endl;
*/
	}

    // create fileHandler
    QThread *fileHandlerThread = new QThread();

    fileHandler = new FileHandler(username, password);
    fileHandler->moveToThread(fileHandlerThread);
    connect(this, &Daemon::aboutToQuit, fileHandler, &FileHandler::deleteLater);
    connect(this, &Daemon::logParameter, fileHandler, &FileHandler::onReceivedLogParameter);
    connect(fileHandlerThread, &QThread::finished, fileHandlerThread, &QThread::deleteLater);
    connect(fileHandlerThread, &QThread::started, fileHandler, &FileHandler::start);
    fileHandlerThread->start();

	// for i2c devices
	lm75 = new LM75();
	if (lm75->devicePresent()) {
		if (verbose>2) {
			cout<<"LM75 device is present."<<endl;
			cout<<"temperature is "<<lm75->getTemperature()<<" centigrades Celsius"<<endl;
			cout<<"readout took "<<lm75->getLastTimeInterval()<<" ms"<<endl;
		}
	} else {
		cerr<<"LM75 device NOT present!"<<endl;
	}
	adc = new ADS1115();
	if (adc->devicePresent()) {
		adc->setPga(ADS1115::PGA4V);
		//adc->setPga(0, ADS1115::PGA2V);
//		adc->setRate(0x06);  // ADS1115::RATE475
		adc->setRate(0x07);  // ADS1115::RATE860
		adc->setAGC(false);
		if (!adc->setDataReadyPinMode()) {
			cerr<<"error: failed setting data ready pin mode (setting thresh regs)"<<endl;
		}

        // set up free running sampling
        QTimer* samplingTimer = new QTimer(this);
        samplingTimer->setInterval(TRACE_SAMPLING_INTERVAL);
        samplingTimer->setSingleShot(false);
        connect(samplingTimer, &QTimer::timeout, this, &Daemon::sampleAdc0TraceEvent);
        samplingTimer->start();
		
		if (verbose>2) {
			cout<<"ADS1115 device is present."<<endl;
			bool ok=adc->setLowThreshold(0b00000000);
			ok = ok && adc->setHighThreshold(0b10000000);
			if (ok) cout<<"successfully setting threshold registers"<<endl;
			else cerr<<"error: failed setting threshold registers"<<endl;
			cout<<"single ended channels:"<<endl;
			cout<<"ch0: "<<adc->readADC(0)<<" ch1: "<<adc->readADC(1)
			<<" ch2: "<<adc->readADC(2)<<" ch3: "<<adc->readADC(3)<<endl;
			adc->setDiffMode(true);
			cout<<"diff channels:"<<endl;
			cout<<"ch0-1: "<<adc->readADC(0)<<" ch0-3: "<<adc->readADC(1)
			<<" ch1-3: "<<adc->readADC(2)<<" ch2-3: "<<adc->readADC(3)<<endl;
			adc->setDiffMode(false);
			cout<<"readout took "<<adc->getLastTimeInterval()<<" ms"<<endl;
		}
	} else {
        adcSamplingMode = ADC_MODE_DISABLED;
        cerr<<"ADS1115 device NOT present!"<<endl;
	}
	

	dac = new MCP4728();
	if (dac->devicePresent()) {
		if (verbose>2) {
			cout<<"MCP4728 device is present."<<endl;
			cout<<"DAC registers / output voltages:"<<endl;
			for (int i=0; i<4; i++) {
				MCP4728::DacChannel dacChannel;
				MCP4728::DacChannel eepromChannel;
				eepromChannel.eeprom=true;
				dac->readChannel(i, dacChannel);
				dac->readChannel(i, eepromChannel);
				cout<<"  ch"<<i<<": "<<dacChannel.value<<" = "<<MCP4728::code2voltage(dacChannel)<<" V"
				"  (stored: "<<eepromChannel.value<<" = "<<MCP4728::code2voltage(eepromChannel)<<" V)"<<endl;
			}
			cout<<"readout took "<<dac->getLastTimeInterval()<<" ms"<<endl;
		}
	} else {
		cerr<<"MCP4728 device NOT present!"<<endl;
	}
	float *tempThresh = new_dacThresh;
	for (int i=std::min(DAC_TH1, DAC_TH2); i<=std::max(DAC_TH1, DAC_TH2); i++) {
		if (tempThresh[i]<0. && dac->devicePresent()) {
			MCP4728::DacChannel dacChannel;
			MCP4728::DacChannel eepromChannel;
			eepromChannel.eeprom=true;
			dac->readChannel(i, dacChannel);
			dac->readChannel(i, eepromChannel);
			tempThresh[i]=MCP4728::code2voltage(dacChannel);
			//tempThresh[i]=code2voltage(eepromChannel);
		}
	}
	dacThresh.push_back(tempThresh[0]);
	dacThresh.push_back(tempThresh[1]);
	
	biasVoltage = new_biasVoltage;
	if (biasVoltage<0. && dac->devicePresent()) {
		MCP4728::DacChannel dacChannel;
		MCP4728::DacChannel eepromChannel;
		eepromChannel.eeprom=true;
		dac->readChannel(DAC_BIAS, dacChannel);
		dac->readChannel(DAC_BIAS, eepromChannel);
		biasVoltage=MCP4728::code2voltage(dacChannel);
		//tempThresh[i]=code2voltage(eepromChannel);
    }
    
    // PCA9536 4 bit I/O I2C device used for selecting the UBX timing input
    pca = new PCA9536();
	if (pca->devicePresent()) {
		if (verbose>2) {
			cout<<"PCA9536 device is present."<<endl;
			cout<<" inputs: 0x"<<hex<<(int)pca->getInputState()<<endl;
			cout<<"readout took "<<dec<<pca->getLastTimeInterval()<<" ms"<<endl;
		}
		pca->setOutputPorts(0b00000111);
		setPcaChannel(new_pcaPortMask);
	} else {
		cerr<<"PCA9536 device NOT present!"<<endl;
	}
    
    if (dac->devicePresent()) {
		if (dacThresh[0] > 0) dac->setVoltage(DAC_TH1, dacThresh[0]);
		if (dacThresh[1] > 0) dac->setVoltage(DAC_TH2, dacThresh[1]);
		if (biasVoltage > 0) dac->setVoltage(DAC_BIAS, biasVoltage);
	}


// removed instantiation of ublox i2c interface since it doesn't work properly on RPi
// the Ublox i2c relies on clock stretching, which RPi is not supporting

	ubloxI2c = new UbloxI2c(0x42);
	ubloxI2c->lock();
	if (ubloxI2c->devicePresent()) {
		if (verbose>1) {
			cout<<"ublox I2C device interface is present."<<endl;
			uint16_t bufcnt = 0;
			bool ok = ubloxI2c->getTxBufCount(bufcnt);
			if (ok) cout<<"bytes in TX buf: "<<bufcnt<<endl;

 			//unsigned long int argh=0;
			//while (argh++<100UL) {
				//bufcnt = 0;
				//ok = ubloxI2c->getTxBufCount(bufcnt);
				//if (ok) cout<<"bytes in TX buf: "<<hex<<bufcnt<<dec<<endl;
				//std::string str=ubloxI2c->getData();
				//cout<<"string length: "<<str.size()<<endl;
				//usleep(200000L);
			//}
			//ubloxI2c->getData();
			//ok = ubloxI2c->getTxBufCount(bufcnt);
			//if (ok) cout<<"bytes in TX buf: "<<bufcnt<<endl;

		}
	} else {
		cerr<<"ublox I2C device interface NOT present!"<<endl;
	}

	
	oled = new Adafruit_SSD1306(0x3c);
	if (oled->devicePresent()) {
		if (verbose>1) {
			cout<<"I2C OLED display is present."<<endl;
		}
		oled->begin();
		oled->clearDisplay();
		
		// text display tests
		oled->setTextSize(1);
		oled->setTextColor(Adafruit_SSD1306::WHITE);
		oled->setCursor(0,2);
		oled->print("*Cosmic Shower Det.*\n");
		oled->print("V 1.0.3\n");
		//  display.setTextColor(BLACK, WHITE); // 'inverted' text
/*
		struct timespec tNow;
		clock_gettime(CLOCK_REALTIME, &tNow);
  
		oled->printf("time:\n%ld.%06d\n", tNow.tv_sec, tNow.tv_nsec/1000L);
		oled->printf("  %02d s", tNow.tv_sec%60);
		oled->drawHorizontalBargraph(0,24,128,8,1, (tNow.tv_sec%60)*10/6);
*/
		//  display.setTextSize(1);
		//  display.setTextColor(WHITE);
		//  display.printf("0x%8X\n", 0xDEADBEEF);
		oled->display();
		usleep(500000L);
		connect(&oledUpdateTimer, SIGNAL(timeout()), this, SLOT(updateOledDisplay()));
		oledUpdateTimer.start(OLED_UPDATE_PERIOD);
	} else {
		cerr<<"I2C OLED display NOT present!"<<endl;
	}
	
    // for pigpio signals:
    preampStatus[0]=preamp1;
    preampStatus[1]=preamp2;
    gainSwitch=gain;
    biasON = bias_ON;
    eventTrigger = (GPIO_PIN)new_eventTrigger;


	// for diagnostics:
	// print out some i2c device statistics
	if (1==0) {
		cout<<"Nr. of invoked I2C devices (plain count): "<<i2cDevice::getNrDevices()<<endl;
		cout<<"Nr. of invoked I2C devices (gl. device list's size): "<<i2cDevice::getGlobalDeviceList().size()<<endl;
		cout<<"Nr. of bytes read on I2C bus: "<<i2cDevice::getGlobalNrBytesRead()<<endl;
		cout<<"Nr. of bytes written on I2C bus: "<<i2cDevice::getGlobalNrBytesWritten()<<endl;
		cout<<"list of device addresses: "<<endl;
		for (uint8_t i=0; i<i2cDevice::getGlobalDeviceList().size(); i++)
		{
			cout<<(int)i+1<<" 0x"<<hex<<(int)i2cDevice::getGlobalDeviceList()[i]->getAddress()<<" "<<i2cDevice::getGlobalDeviceList()[i]->getTitle();
			if (i2cDevice::getGlobalDeviceList()[i]->devicePresent()) cout<<" present"<<endl;
			else cout<<" missing"<<endl;
		}
		lm75->getCapabilities();
	}
	
	// for gps module
	gpsdevname = new_gpsdevname;
	dumpRaw = new_dumpRaw;
	baudrate = new_baudrate;
	configGnss = new_configGnss;
	showout = new_showout;
	showin = new_showin;

	// for tcp connection with fileServer
	peerPort = new_peerPort;
	if (peerPort == 0) {
		peerPort = 51508;
	}
	peerAddress = new_peerAddress;
	if (peerAddress.isEmpty() || peerAddress == "local" || peerAddress == "localhost") {
		peerAddress = QHostAddress(QHostAddress::LocalHost).toString();
	}

	if (new_daemonAddress.isEmpty()) {
		// if not otherwise specified: listen on all available addresses
		daemonAddress = QHostAddress(QHostAddress::Any);
		if (verbose > 1) {
			cout << daemonAddress.toString() << endl;
		}
	}
	daemonPort = new_daemonPort;
	if (daemonPort == 0) {
		// maybe think about other fall back solution
		daemonPort = 51508;
	}
	if (!this->listen(daemonAddress, daemonPort)) {
		cerr << tr("Unable to start the server: %1.\n").arg(this->errorString());
	}
	else {
		if (verbose > 4) {
			cout << tr("\nThe server is running on\n\nIP: %1\nport: %2\n\n")
				.arg(daemonAddress.toString()).arg(serverPort());
		}
	}
	flush(cout);

	// connect to the regular log timer signal to log several non-regularly polled parameters
    connect(fileHandler, &FileHandler::logIntervalSignal, this, &Daemon::onLogParameterPolled);

    connectToPigpiod();
	// set up histograms
	setupHistos();

    // start gps module connection
	connectToGps();
	//delay(1000);
	if (configGnss) {
		configGps();
	}
	pollAllUbxMsgRate();
}


Daemon::~Daemon() {
    snHup.clear();
    snTerm.clear();
    snInt.clear();
    if (pca!=nullptr){ delete pca; pca = nullptr; }
    if (dac!=nullptr){ delete dac; dac = nullptr; }
    if (adc!=nullptr){ delete adc; adc = nullptr; }
    if (eep!=nullptr){ delete eep; eep = nullptr; }
    if (calib!=nullptr){ delete calib; calib = nullptr; }
    if (ubloxI2c!=nullptr){ delete ubloxI2c; ubloxI2c = nullptr; }
    if (oled!=nullptr){ delete oled; oled = nullptr; }
    pigHandler.clear();
}

void Daemon::connectToPigpiod(){
    const QVector<unsigned int> gpio_pins({ GPIO_PINMAP[TDC_INTB], GPIO_PINMAP[PREAMP_1], GPIO_PINMAP[PREAMP_2],
                                            GPIO_PINMAP[UBIAS_EN], GPIO_PINMAP[EVT_AND], GPIO_PINMAP[EVT_XOR],
                                            /*GPIO_PINMAP[ADC_READY],*/ GPIO_PINMAP[TIMEPULSE], GPIO_PINMAP[GAIN_HL] });
    pigHandler = new PigpiodHandler(gpio_pins);
    tdc7200 = new TDC7200(GPIO_PINMAP[TDC_INTB]);
    QThread *pigThread = new QThread();
    pigHandler->moveToThread(pigThread);
    tdc7200->moveToThread(pigThread);
    //pighandler <-> tdc
    connect(pigHandler, &PigpiodHandler::spiData, tdc7200, &TDC7200::onDataReceived);
    connect(pigHandler, &PigpiodHandler::signal, tdc7200, &TDC7200::onDataAvailable);
    connect(tdc7200, &TDC7200::readData, pigHandler, &PigpiodHandler::readSpi);
    connect(tdc7200, &TDC7200::writeData, pigHandler, &PigpiodHandler::writeSpi);

    //tdc <-> thread & daemon
    connect(tdc7200, &TDC7200::tdcEvent, this, [this](double usecs){
        checkRescaleHisto(tdc7200Histo,usecs);
        tdc7200Histo.fill(usecs);
    });
    connect(tdc7200, &TDC7200::statusUpdated, this, [this](bool isPresent){
       spiDevicePresent = isPresent;
       sendSpiStats();
    });
    connect(pigThread, &QThread::started, tdc7200, &TDC7200::initialise);
    connect(pigThread, &QThread::finished, tdc7200, &TDC7200::deleteLater);

    //pigHandler <-> thread & daemon
    connect(this, &Daemon::aboutToQuit, pigHandler, &PigpiodHandler::stop);
    connect(this, &Daemon::GpioSetOutput, pigHandler, &PigpiodHandler::setOutput);
    connect(this, &Daemon::GpioSetInput, pigHandler, &PigpiodHandler::setInput);
    connect(this, &Daemon::GpioSetPullUp, pigHandler, &PigpiodHandler::setPullUp);
    connect(this, &Daemon::GpioSetPullDown, pigHandler, &PigpiodHandler::setPullDown);
    connect(this, &Daemon::GpioSetState, pigHandler, &PigpiodHandler::setGpioState);
    connect(pigHandler, &PigpiodHandler::signal, this, &Daemon::sendGpioPinEvent);
    connect(pigHandler, &PigpiodHandler::samplingTrigger, this, &Daemon::sampleAdc0Event);
    connect(pigHandler, &PigpiodHandler::eventInterval, this, [this](quint64 nsecs) { eventIntervalHisto.fill(1e-6*nsecs); } );
    connect(pigHandler, &PigpiodHandler::eventInterval, this, [this](quint64 nsecs)
    { if (nsecs/1000<=eventIntervalShortHisto.getMax()) eventIntervalShortHisto.fill((double)nsecs/1000.); } );
    connect(pigHandler, &PigpiodHandler::timePulseDiff, this, [this](qint32 usecs)
    { 	checkRescaleHisto(tpTimeDiffHisto, usecs);
        tpTimeDiffHisto.fill((double)usecs);
        /*cout<<"TP time diff: "<<usecs<<" us"<<endl;*/
    } );
    pigHandler->setSamplingTriggerSignal(eventTrigger);
    connect(this, &Daemon::setSamplingTriggerSignal, pigHandler, &PigpiodHandler::setSamplingTriggerSignal);

    struct timespec ts_res;
    clock_getres(CLOCK_REALTIME, &ts_res);
    if (verbose) {
        cout<<"the timing resolution of the system clock is "<<ts_res.tv_nsec<<" ns"<<endl;
    }

    /* looks good but using QPointer should be safer
     * connect(pigHandler, &PigpiodHandler::destroyed, this, [this](){pigHandler = nullptr;});
    */
    // test if "aboutToQuit" is called everytime
    //connect(this, &Daemon::aboutToQuit, [this](){this->toConsole("aboutToQuit called and signal emitted\n");});
    connect(pigThread, &QThread::finished, pigHandler, &PigpiodHandler::deleteLater);
    timespec_get(&lastRateInterval, TIME_UTC);
    startOfProgram = lastRateInterval;
    connect(pigHandler, &PigpiodHandler::signal, this, [this](uint8_t gpio_pin){
        rateCounterIntervalActualisation();
        if (gpio_pin==GPIO_PINMAP[EVT_XOR]){
            xorCounts.back()++;
            //xorCounts.pop_back();
            //value++;
            //xorCounts.push_back(value);
        }
        if (gpio_pin==GPIO_PINMAP[EVT_AND]){
            //quint64 value = andCounts.back();
            andCounts.back()++;
            //andCounts.pop_back();
            //value++;
            //andCounts.push_back(value);
        }
    });
    pigThread->start();
    rateBufferReminder.setInterval(rateBufferInterval);
    rateBufferReminder.setSingleShot(false);
    connect(&rateBufferReminder, &QTimer::timeout, this, &Daemon::onRateBufferReminder);
    rateBufferReminder.start();
    emit GpioSetOutput(GPIO_PINMAP[UBIAS_EN]);
    emit GpioSetState(GPIO_PINMAP[UBIAS_EN], (HW_VERSION==1)?(biasON?1:0):(biasON?0:1));

    emit GpioSetOutput(GPIO_PINMAP[PREAMP_1]);
    emit GpioSetOutput(GPIO_PINMAP[PREAMP_2]);
    emit GpioSetOutput(GPIO_PINMAP[GAIN_HL]);
    emit GpioSetState(GPIO_PINMAP[PREAMP_1],preampStatus[0]);
    emit GpioSetState(GPIO_PINMAP[PREAMP_2],preampStatus[1]);
    emit GpioSetState(GPIO_PINMAP[GAIN_HL],gainSwitch);
}

void Daemon::connectToGps() {
	// before connecting to gps we have to make sure all other programs are closed
    // and serial echo is off
	if (gpsdevname.isEmpty()) {
		return;
	}
	QProcess prepareSerial;
	QString command = "stty";
	QStringList args = { "-F", "/dev/ttyAMA0", "-echo", "-onlcr" };
	prepareSerial.start(command, args, QIODevice::ReadWrite);
	prepareSerial.waitForFinished();

	// here is where the magic threading happens look closely
    qtGps = new QtSerialUblox(gpsdevname, gpsTimeout, baudrate, dumpRaw, verbose, showout, showin);
    QThread *gpsThread = new QThread();
	qtGps->moveToThread(gpsThread);
    // connect all signals about quitting
    connect(this, &Daemon::aboutToQuit, qtGps, &QtSerialUblox::deleteLater);
    connect(gpsThread, &QThread::finished, gpsThread, &QThread::deleteLater);
	// connect all signals not coming from Daemon to gps
	connect(qtGps, &QtSerialUblox::toConsole, this, &Daemon::gpsToConsole);
	connect(gpsThread, &QThread::started, qtGps, &QtSerialUblox::makeConnection);
	connect(qtGps, &QtSerialUblox::gpsRestart, this, &Daemon::connectToGps);
	// connect all command signals for ublox module here
	connect(this, &Daemon::UBXSetCfgPrt, qtGps, &QtSerialUblox::UBXSetCfgPrt);
	connect(this, &Daemon::UBXSetCfgMsgRate, qtGps, &QtSerialUblox::UBXSetCfgMsgRate);
	connect(this, &Daemon::UBXSetCfgRate, qtGps, &QtSerialUblox::UBXSetCfgRate);
	connect(this, &Daemon::sendPollUbxMsgRate, qtGps, &QtSerialUblox::pollMsgRate);
	connect(this, &Daemon::sendPollUbxMsg, qtGps, &QtSerialUblox::pollMsg);
	connect(this, &Daemon::sendUbxMsg, qtGps, &QtSerialUblox::enqueueMsg);
	connect(qtGps, &QtSerialUblox::UBXReceivedAckNak, this, &Daemon::UBXReceivedAckNak);
	connect(qtGps, &QtSerialUblox::UBXreceivedMsgRateCfg, this, &Daemon::UBXReceivedMsgRateCfg);
    connect(qtGps, &QtSerialUblox::gpsPropertyUpdatedGeodeticPos, this, &Daemon::onGpsPropertyUpdatedGeodeticPos);
    connect(qtGps, &QtSerialUblox::gpsPropertyUpdatedGnss, this, &Daemon::onGpsPropertyUpdatedGnss);
    connect(qtGps, &QtSerialUblox::gpsPropertyUpdatedUint32, this, &Daemon::gpsPropertyUpdatedUint32);
    connect(qtGps, &QtSerialUblox::gpsPropertyUpdatedInt32, this, &Daemon::gpsPropertyUpdatedInt32);
    connect(qtGps, &QtSerialUblox::gpsPropertyUpdatedUint8, this, &Daemon::gpsPropertyUpdatedUint8);
    connect(qtGps, &QtSerialUblox::gpsMonHW, this, &Daemon::onGpsMonHWUpdated);
    connect(qtGps, &QtSerialUblox::gpsMonHW2, this, &Daemon::onGpsMonHW2Updated);
    connect(qtGps, &QtSerialUblox::gpsVersion, this, &Daemon::UBXReceivedVersion);
	connect(qtGps, &QtSerialUblox::UBXCfgError, this, &Daemon::toConsole);
    connect(qtGps, &QtSerialUblox::UBXReceivedGnssConfig, this, &Daemon::onUBXReceivedGnssConfig);
    connect(qtGps, &QtSerialUblox::UBXReceivedTP5, this, &Daemon::onUBXReceivedTP5);
    connect(qtGps, &QtSerialUblox::UBXReceivedTxBuf, this, &Daemon::onUBXReceivedTxBuf);
    connect(qtGps, &QtSerialUblox::UBXReceivedRxBuf, this, &Daemon::onUBXReceivedRxBuf);
	connect(this, &Daemon::UBXSetDynModel, qtGps, &QtSerialUblox::setDynamicModel);
	connect(this, &Daemon::resetUbxDevice, qtGps, &QtSerialUblox::UBXReset);
	connect(this, &Daemon::setGnssConfig, qtGps, &QtSerialUblox::onSetGnssConfig);
	connect(this, &Daemon::UBXSetCfgTP5, qtGps, &QtSerialUblox::UBXSetCfgTP5);
	connect(this, &Daemon::UBXSetMinMaxSVs, qtGps, &QtSerialUblox::UBXSetMinMaxSVs);
	connect(this, &Daemon::UBXSetMinCNO, qtGps, &QtSerialUblox::UBXSetMinCNO);
	connect(this, &Daemon::UBXSetAopCfg, qtGps, &QtSerialUblox::UBXSetAopCfg);
	connect(this, &Daemon::UBXSaveCfg, qtGps, &QtSerialUblox::UBXSaveCfg);
    connect(qtGps, &QtSerialUblox::UBXReceivedTimeTM2, this, &Daemon::onUBXReceivedTimeTM2);

	connect(qtGps, &QtSerialUblox::UBXReceivedDops, this, [this](const UbxDopStruct& dops){
		currentDOP=dops;
		emit logParameter(LogParameter("positionDOP", QString::number(dops.pDOP/100.), LogParameter::LOG_AVERAGE));
		emit logParameter(LogParameter("timeDOP", QString::number(dops.tDOP/100.), LogParameter::LOG_AVERAGE));
	});

    // connect fileHandler related stuff
    if (fileHandler != nullptr){
        connect(qtGps, &QtSerialUblox::timTM2, fileHandler, &FileHandler::writeToDataFile);
    }
	// after thread start there will be a signal emitted which starts the qtGps makeConnection function
	gpsThread->start();
}

void Daemon::incomingConnection(qintptr socketDescriptor) {
	if (verbose > 4) {
		cout << "incomingConnection" << endl;
	}
	QThread *thread = new QThread();
	TcpConnection *tcpConnection = new TcpConnection(socketDescriptor, verbose);
	tcpConnection->moveToThread(thread);
    // connect all signals about quitting
    connect(this, &Daemon::aboutToQuit, tcpConnection, &TcpConnection::closeThisConnection);
    connect(this, &Daemon::closeConnection, tcpConnection, &TcpConnection::closeConnection);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    // connect all other signals
    connect(thread, &QThread::started, tcpConnection, &TcpConnection::receiveConnection);
    connect(this, &Daemon::sendTcpMessage, tcpConnection, &TcpConnection::sendTcpMessage);
	connect(tcpConnection, &TcpConnection::receivedTcpMessage, this, &Daemon::receivedTcpMessage);
	connect(tcpConnection, &TcpConnection::toConsole, this, &Daemon::toConsole);
//	connect(tcpConnection, &TcpConnection::madeConnection, this, [this](QString, quint16, QString , quint16) { emit sendPollUbxMsg(UBX_MON_VER); });
	connect(tcpConnection, &TcpConnection::madeConnection, this, &Daemon::onMadeConnection);
	connect(tcpConnection, &TcpConnection::connectionTimeout, this, &Daemon::onStoppedConnection);
	thread->start();

/*	
	emit sendPollUbxMsg(UBX_MON_VER);
	emit sendPollUbxMsg(UBX_CFG_GNSS);
	emit sendPollUbxMsg(UBX_CFG_NAV5);
	emit sendPollUbxMsg(UBX_CFG_TP5);
	emit sendPollUbxMsg(UBX_CFG_NAVX5);

	sendBiasStatus();
	sendBiasVoltage();
	sendDacThresh(0);
	sendDacThresh(1);
	sendPcaChannel();
	sendEventTriggerSelection();
*/

	pollAllUbxMsgRate();
}


void Daemon::setupHistos() {
	geoHeightHisto=Histogram("geoHeight",200,0.,199.);
	geoHeightHisto.setUnit("m");
	geoLonHisto=Histogram("geoLongitude",200,0.,0.003);
	geoLonHisto.setUnit("deg");
	geoLatHisto=Histogram("geoLatitude",200,0.,0.003);
	geoLatHisto.setUnit("deg");
	weightedGeoHeightHisto=Histogram("weightedGeoHeight",200,0.,199.);
	weightedGeoHeightHisto.setUnit("m");
    pulseHeightHisto=Histogram("pulseHeight",500,0.,3.8);
	pulseHeightHisto.setUnit("V");
    adcSampleTimeHisto=Histogram("adcSampleTime",500,0.,49.9);
	adcSampleTimeHisto.setUnit("ms");
	ubxTimeLengthHisto=Histogram("UbxEventLength",100,50.,149.);
	ubxTimeLengthHisto.setUnit("ns");
	eventIntervalHisto=Histogram("gpioEventInterval",400,0.,1100.);
	eventIntervalHisto.setUnit("ms");
	eventIntervalShortHisto=Histogram("gpioEventIntervalShort",50,0.,49.);
	eventIntervalShortHisto.setUnit("us");
	ubxTimeIntervalHisto=Histogram("UbxEventInterval",200,0.,1100.);
	ubxTimeIntervalHisto.setUnit("ms");
	tpTimeDiffHisto=Histogram("TPTimeDiff",200,-999.,1000.);
	tpTimeDiffHisto.setUnit("us");
    tdc7200Histo=Histogram("Time-to-Digital Time Diff",400, 0., 1e6);
    tdc7200Histo.setUnit("ns");
}

void Daemon::clearHisto(QString histoName){
    if (histoName=="geoHeight"){
        geoHeightHisto.clear();
        emit sendHistogram(geoHeightHisto);
    }
    if (histoName=="geoLongitude"){
        geoLonHisto.clear();
        emit sendHistogram(geoLonHisto);
    }
    if (histoName=="geoLatHisto"){
        geoLatHisto.clear();
        emit sendHistogram(geoLatHisto);
    }
    if (histoName=="weightedGeoHeight"){
        weightedGeoHeightHisto.clear();
        emit sendHistogram(weightedGeoHeightHisto);
    }
    if (histoName=="pulseHeight"){
        pulseHeightHisto.clear();
        emit sendHistogram(pulseHeightHisto);
    }
    if (histoName=="adcSampleTime"){
        adcSampleTimeHisto.clear();
        emit sendHistogram(adcSampleTimeHisto);
    }
    if (histoName=="UbxEventLength"){
        ubxTimeLengthHisto.clear();
        emit sendHistogram(ubxTimeLengthHisto);
    }
    if (histoName=="gpioEventInterval"){
        eventIntervalHisto.clear();
        emit sendHistogram(eventIntervalHisto);
    }
    if (histoName=="gpioEventIntervalShort"){
        eventIntervalShortHisto.clear();
        emit sendHistogram(eventIntervalShortHisto);
    }
    if (histoName=="UbxEventInterval"){
        ubxTimeIntervalHisto.clear();
        emit sendHistogram(ubxTimeIntervalHisto);
    }
    if (histoName=="TPTimeDiff"){
        tpTimeDiffHisto.clear();
        emit sendHistogram(tpTimeDiffHisto);
    }
    if (histoName=="Time-to-Digital Time Diff"){
        tdc7200.clear();
        emit sendHistogram(tdc7200Histo);
    }
}

void Daemon::rescaleHisto(Histogram& hist, double center, double width) {
	hist.setMin(center-width/2.);
	hist.setMax(center+width/2.);
	hist.clear();
}

void Daemon::rescaleHisto(Histogram& hist, double center) {
	double width=hist.getMax()-hist.getMin();
	rescaleHisto(hist, center, width);
}

void Daemon::checkRescaleHisto(Histogram& hist, double newValue) {
	// Strategy: check if more than 10% of all entries in underflow/overflow
	// set new center to old mean
	// set center to newValue if histo empty or only underflow/overflow filled
	// histo will not be filled with supplied value, it has to be done externally
	double entries=hist.getEntries();
	// do nothing if histo is empty
	if (entries<1.) {
		return;
		rescaleHisto(hist, newValue);
	}
	double ufl=hist.getUnderflow();
	double ofl=hist.getOverflow();
	entries-=ufl+ofl;
	if (ufl>0. && ofl>0. && (ufl+ofl)>0.05*entries) {
		// range is too small, underflow and overflow have more than 5% of all entries
		double range=hist.getMax()-hist.getMin();
		rescaleHisto(hist, hist.getMean(), 1.1*range);
	} else if (ufl>0.05*entries) {
//		if (entries<1.) rescaleHisto(hist, hist.getMin()-(hist.getMax()-hist.getMin())/2.);
		if (entries<1.) rescaleHisto(hist, newValue);
		else rescaleHisto(hist, hist.getMean());
	} else if (ofl>0.05*entries) {
//		if (entries<1.) rescaleHisto(hist, hist.getMax()+(hist.getMax()-hist.getMin())/2.);
		if (entries<1.) rescaleHisto(hist, newValue);
		else rescaleHisto(hist, hist.getMean());
	}
}

// ALL FUNCTIONS ABOUT TCPMESSAGE SENDING AND RECEIVING
void Daemon::receivedTcpMessage(TcpMessage tcpMessage) {
    quint16 msgID = tcpMessage.getMsgID();
    if (msgID == threshSig) {
        uint8_t channel;
        float threshold;
        *(tcpMessage.dStream) >> channel >> threshold;
        if (threshold<0.005)
			cout<<"Warning: setting DAC "<<channel<<" to 0!"<<endl;
        else setDacThresh(channel, threshold);
        sendDacThresh(DAC_TH1);
        sendDacThresh(DAC_TH2);
        return;
	}
    if (msgID == threshRequestSig){
        sendDacThresh(DAC_TH1);
        sendDacThresh(DAC_TH2);
        return;
    }
    if (msgID == biasVoltageSig){
        float voltage;
        *(tcpMessage.dStream) >> voltage;
        setBiasVoltage(voltage);
        pulseHeightHisto.clear();
        sendBiasVoltage();
        return;
    }
    if (msgID == biasVoltageRequestSig){
        sendBiasVoltage();
        return;
    }
    if (msgID == biasSig){
        bool status;
        *(tcpMessage.dStream) >> status;
        setBiasStatus(status);
        pulseHeightHisto.clear();
        sendBiasStatus();
        return;
    }
    if (msgID == biasRequestSig){
        sendBiasStatus();
    }
    if (msgID == preampSig){
        quint8 channel;
        bool status;
        *(tcpMessage.dStream) >> channel >> status;
        if (channel==0) {
			preampStatus[0]=status;
            emit GpioSetState(GPIO_PINMAP[PREAMP_1], status);
			emit logParameter(LogParameter("preampSwitch1", QString::number((int)preampStatus[0]), LogParameter::LOG_EVERY));
			pulseHeightHisto.clear();
		} else if (channel==1) {
            preampStatus[1]=status;
            emit GpioSetState(GPIO_PINMAP[PREAMP_2], status);
			emit logParameter(LogParameter("preampSwitch2", QString::number((int)preampStatus[1]), LogParameter::LOG_EVERY));
		}
        sendPreampStatus(0);
        sendPreampStatus(1);
        return;
    }
    if (msgID == preampRequestSig){
        sendPreampStatus(0);
        sendPreampStatus(1);
    }
    if (msgID == gainSwitchSig){
        bool status;
        *(tcpMessage.dStream) >> status;
        gainSwitch=status;
        emit GpioSetState(GPIO_PINMAP[GAIN_HL], status);
		pulseHeightHisto.clear();
		emit logParameter(LogParameter("gainSwitch", QString::number((int)gainSwitch), LogParameter::LOG_EVERY));
		sendGainSwitchStatus();
		return;
    }
    if (msgID == gainSwitchRequestSig){
        sendGainSwitchStatus();
    }
    if (msgID == ubxMsgRateRequest) {
		sendUbxMsgRates();
        return;
	}
    if (msgID == ubxResetSig) {
		uint32_t resetFlags = QtSerialUblox::RESET_WARM | QtSerialUblox::RESET_SW;
		emit resetUbxDevice(resetFlags);
		pollAllUbxMsgRate();
        return;
	}
    if (msgID == ubxConfigureDefaultSig) {
		configGps();
		pollAllUbxMsgRate();
        return;
	}
    if (msgID == ubxMsgRate){
        QMap<uint16_t, int> ubxMsgRates;
        *(tcpMessage.dStream) >> ubxMsgRates;
        setUbxMsgRates(ubxMsgRates);
    }
    if (msgID == pcaChannelSig){
        quint8 portMask;
        *(tcpMessage.dStream) >> portMask;
        setPcaChannel((uint8_t)portMask);
        sendPcaChannel();
        ubxTimeLengthHisto.clear();
        return;
    }
    if (msgID == pcaChannelRequestSig){
        sendPcaChannel();
        return;
    }
    if (msgID == eventTriggerSig){
        unsigned int signal;
        *(tcpMessage.dStream) >> signal;
        setEventTriggerSelection((GPIO_PIN)signal);
        usleep(1000);
        sendEventTriggerSelection();
        return;
    }
    if (msgID == eventTriggerRequestSig){
        sendEventTriggerSelection();
        return;
    }
    if (msgID == gpioRateRequestSig){
        quint8 whichRate;
        quint16 number;
        *(tcpMessage.dStream) >> number >> whichRate;
        sendGpioRates(number, whichRate);
    }
    if (msgID == resetRateSig){
        clearRates();
        return;
    }
	if (msgID == dacRequestSig){
		quint8 channel;
		*(tcpMessage.dStream) >> channel;
		MCP4728::DacChannel channelData;
		if (!dac->devicePresent()) return;
		dac->readChannel(channel, channelData);
		float voltage = MCP4728::code2voltage(channelData);
		sendDacReadbackValue(channel, voltage);
    }
    if (msgID == adcSampleRequestSig){
        quint8 channel;
        *(tcpMessage.dStream) >> channel;
        sampleAdcEvent(channel);
    }
    if (msgID == temperatureRequestSig){
        getTemperature();
    }
    if (msgID == i2cStatsRequestSig){
        sendI2cStats();
    }
        if (msgID == i2cScanBusRequestSig){
        scanI2cBus();
        sendI2cStats();
    }
    if (msgID == spiStatsRequestSig){
        sendSpiStats();
    }
    if (msgID == calibRequestSig){
        sendCalib();
    }
    if (msgID == calibWriteEepromSig){
        if (calib!=nullptr) calib->writeToEeprom();
        sendCalib();
    }
    if (msgID == calibSetSig){
        std::vector<CalibStruct> calibs;
        quint8 nrEntries=0;
        *(tcpMessage.dStream) >> nrEntries;
        for (int i=0; i<nrEntries; i++) {
			CalibStruct item;
			*(tcpMessage.dStream) >> item;
			calibs.push_back(item);
		}
		receivedCalibItems(calibs);
    }
    if (msgID == gnssConfigSig){
        std::vector<GnssConfigStruct> configs;
        int nrEntries=0;
        *(tcpMessage.dStream) >> nrEntries;
        for (int i=0; i<nrEntries; i++) {
			GnssConfigStruct config;
			*(tcpMessage.dStream) >> config.gnssId >> config.resTrkCh >>
                config.maxTrkCh >> config.flags;
			configs.push_back(config);
		}
		emit setGnssConfig(configs);
		usleep(150000L);
		emit sendPollUbxMsg(UBX_CFG_GNSS);
    }
    if (msgID == gpsCfgTP5Sig){
        UbxTimePulseStruct tp;
        *(tcpMessage.dStream) >> tp;
        emit UBXSetCfgTP5(tp);
        emit sendPollUbxMsg(UBX_CFG_TP5);
        return;
    }
    if (msgID == ubxSaveCfgSig){
        emit UBXSaveCfg();
        emit sendPollUbxMsg(UBX_CFG_TP5);
		emit sendPollUbxMsg(UBX_CFG_GNSS);
        return;
    }
    if (msgID == quitConnectionSig){
        QString closeAddress;
        *(tcpMessage.dStream) >> closeAddress;
        emit closeConnection(closeAddress);
    }
    if (msgID == dacSetEepromSig){
        saveDacValuesToEeprom();
    }
    if (msgID == histogramClearSig){
        QString histoName;
        *(tcpMessage.dStream) >> histoName;
        clearHisto(histoName);
    }
}

void Daemon::scanI2cBus() {
	for (uint8_t addr=1; addr<0x7f; addr++)
	{
		bool alreadyThere = false;
		for (uint8_t i=0; i<i2cDevice::getGlobalDeviceList().size(); i++) {
			if (addr==i2cDevice::getGlobalDeviceList()[i]->getAddress()) {
				alreadyThere=true;
				break;
			}
		}
		if (alreadyThere) continue;
		i2cDevice* dev = new i2cDevice(addr);
		if (!dev->devicePresent()) delete dev;
	}
}

void Daemon::sendI2cStats() {
	TcpMessage tcpMessage(i2cStatsSig);
	quint8 nrDevices=i2cDevice::getGlobalDeviceList().size();
	quint32 bytesRead = i2cDevice::getGlobalNrBytesRead();
	quint32 bytesWritten = i2cDevice::getGlobalNrBytesWritten();
	*(tcpMessage.dStream) << nrDevices << bytesRead << bytesWritten;

	for (uint8_t i=0; i<i2cDevice::getGlobalDeviceList().size(); i++)
	{
		uint8_t addr = i2cDevice::getGlobalDeviceList()[i]->getAddress();
		QString title = QString::fromStdString(i2cDevice::getGlobalDeviceList()[i]->getTitle());
		i2cDevice::getGlobalDeviceList()[i]->devicePresent();
		uint8_t status = i2cDevice::getGlobalDeviceList()[i]->getStatus();
		*(tcpMessage.dStream) << addr << title << status;
	}
	emit sendTcpMessage(tcpMessage);
}

void Daemon::sendSpiStats() {
    TcpMessage tcpMessage(spiStatsSig);
    *(tcpMessage.dStream) << spiDevicePresent;
    emit sendTcpMessage(spiDevicePresent);
}

void Daemon::sendCalib() {
	TcpMessage tcpMessage(calibSetSig);
	bool valid=calib->isValid();
	bool eepValid=calib->isEepromValid();
    quint16 nrPars = calib->getCalibList().size();
    quint64 id = calib->getSerialID();
    *(tcpMessage.dStream) << valid << eepValid << id << nrPars;
    for (int i=0; i<nrPars; i++) {
		*(tcpMessage.dStream) << calib->getCalibItem(i);
	}
	emit sendTcpMessage(tcpMessage);
}

void Daemon::receivedCalibItems(const std::vector<CalibStruct>& newCalibs) {
    for (unsigned int i=0; i<newCalibs.size(); i++) {
		calib->setCalibItem(newCalibs[i].name, newCalibs[i]);
	}
}


void Daemon::onGpsPropertyUpdatedGeodeticPos(GeodeticPos pos){
    TcpMessage tcpMessage(geodeticPosSig);
    (*tcpMessage.dStream) << pos.iTOW << pos.lon << pos.lat
                          << pos.height << pos.hMSL << pos.hAcc
                          << pos.vAcc;
    emit sendTcpMessage(tcpMessage);
    
	emit logParameter(LogParameter("geoLongitude", QString::number(1e-7*pos.lon,'f',5)+" deg", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("geoLatitude", QString::number(1e-7*pos.lat,'f',5)+" deg", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("geoHeightMSL", QString::number(1e-3*pos.hMSL,'f',2)+" m", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("meanGeoHeightMSL", QString::number(geoHeightHisto.getMean(),'f',2)+" m", LogParameter::LOG_LATEST));
	emit logParameter(LogParameter("geoHorAccuracy", QString::number(1e-3*pos.hAcc,'f',2)+" m", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("geoVertAccuracy", QString::number(1e-3*pos.vAcc,'f',2)+" m", LogParameter::LOG_AVERAGE));
		
	if (1e-3*pos.vAcc<100.) {
		checkRescaleHisto(geoHeightHisto, 1e-3*pos.hMSL);
		geoHeightHisto.fill(1e-3*pos.hMSL /*, heightWeight */);
		this->sendHistogram(geoHeightHisto);
		if (currentDOP.vDOP>0) {
			double heightWeight=100./currentDOP.vDOP;
			checkRescaleHisto(weightedGeoHeightHisto, 1e-3*pos.hMSL);
			weightedGeoHeightHisto.fill(1e-3*pos.hMSL , heightWeight );
			this->sendHistogram(weightedGeoHeightHisto);
		}
	}
	if (1e-3*pos.hAcc<100.) {
		checkRescaleHisto(geoLonHisto, 1e-7*pos.lon);
		geoLonHisto.fill(1e-7*pos.lon /*, heightWeight */);
		checkRescaleHisto(geoLatHisto, 1e-7*pos.lat);
		geoLatHisto.fill(1e-7*pos.lat /*, heightWeight */);
		this->sendHistogram(geoLonHisto);
		this->sendHistogram(geoLatHisto);
	}

}

void Daemon::sendHistogram(const Histogram& hist){
    TcpMessage tcpMessage(histogramSig);
    (*tcpMessage.dStream) << hist;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendUbxMsgRates() {
	TcpMessage tcpMessage(ubxMsgRate);
    *(tcpMessage.dStream) << msgRateCfgs;
	emit sendTcpMessage(tcpMessage);
}

void Daemon::sendDacThresh(uint8_t channel) {
    if (channel > 1){ return; }
    TcpMessage tcpMessage(threshSig);
    *(tcpMessage.dStream) << (quint8)channel << dacThresh[(int)channel];
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendDacReadbackValue(uint8_t channel, float voltage) {
    if (channel > 3){ return; }
    
    TcpMessage tcpMessage(dacReadbackSig);
    *(tcpMessage.dStream) << (quint8)channel << voltage;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendGpioPinEvent(uint8_t gpio_pin) {
	TcpMessage tcpMessage(gpioPinSig);
    unsigned int gpio_function=0;
    // reverse lookup of gpio function from given pin (first occurence)
    auto result=std::find_if(GPIO_PINMAP.begin(), GPIO_PINMAP.end(), [&gpio_pin](const std::pair<GPIO_PIN,unsigned int>& item)
					{ return item.second==gpio_pin; }
					);
	if (result!=GPIO_PINMAP.end()) {
//		*(tcpMessage.dStream) << (quint8)gpio_pin;
		*(tcpMessage.dStream) << (GPIO_PIN)result->first;
		emit sendTcpMessage(tcpMessage);
	}
}

void Daemon::sendBiasVoltage(){
    TcpMessage tcpMessage(biasVoltageSig);
    *(tcpMessage.dStream) << biasVoltage;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendBiasStatus(){
    TcpMessage tcpMessage(biasSig);
    *(tcpMessage.dStream) << biasON;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendGainSwitchStatus(){
    TcpMessage tcpMessage(gainSwitchSig);
    *(tcpMessage.dStream) << gainSwitch;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendPreampStatus(uint8_t channel) {
    if (channel > 1){ return; }
    TcpMessage tcpMessage(preampSig);
    *(tcpMessage.dStream) << (quint8)channel << preampStatus [channel];
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendPcaChannel(){
    TcpMessage tcpMessage(pcaChannelSig);
    *(tcpMessage.dStream) << (quint8)pcaPortMask;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::sendEventTriggerSelection(){
    if (pigHandler==nullptr) return;
    TcpMessage tcpMessage(eventTriggerSig);
    *(tcpMessage.dStream) << (GPIO_PIN)pigHandler->samplingTriggerSignal;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::rateCounterIntervalActualisation(){
    if (xorCounts.isEmpty()){
        xorCounts.push_back(0);
    }
    if (andCounts.isEmpty()){
        andCounts.push_back(0);
    }
    timespec now;
    timespec_get(&now, TIME_UTC);
    int64_t diff = msecdiff(now,lastRateInterval);
    while(diff>1000){
        xorCounts.push_back(0);
        andCounts.push_back(0);
        while (xorCounts.size()>(rateBufferTime)){
            xorCounts.pop_front();
        }
        while (andCounts.size()>(rateBufferTime)){
            andCounts.pop_front();
        }
        lastRateInterval.tv_sec += 1;
        diff = msecdiff(now,lastRateInterval);
    }
}

void Daemon::clearRates(){
    xorCounts.clear();
    xorCounts.push_back(0);
    andCounts.clear();
    andCounts.push_back(0);
    xorRatePoints.clear();
    andRatePoints.clear();
}

qreal Daemon::getRateFromCounts(quint8 which_rate){
    rateCounterIntervalActualisation();
    QList<quint64> *counts;
    if (which_rate==XOR_RATE){
        counts = &xorCounts;
    }else if( which_rate == AND_RATE){
        counts = &andCounts;
    }else{
        return -1.0;
    }
    quint64 sum = 0;
    for (auto count : *counts){
        sum += count;
    }
    timespec now;
    timespec_get(&now, TIME_UTC);
    qreal timeInterval = ((qreal)(1000*(counts->size()-1)))+(qreal)msecdiff(now,lastRateInterval); // in ms
    qreal rate = sum/timeInterval*1000;
    return (rate);
}

void Daemon::onRateBufferReminder(){
    qreal secsSinceStart = 0.001*(qreal)msecdiff(lastRateInterval,startOfProgram);
    qreal xorRate = getRateFromCounts(XOR_RATE);
    qreal andRate = getRateFromCounts(AND_RATE);
    QPointF xorPoint(secsSinceStart, xorRate);
    QPointF andPoint(secsSinceStart, andRate);
    xorRatePoints.append(xorPoint);
    andRatePoints.append(andPoint);
    emit logParameter(LogParameter("rateXOR", QString::number(xorRate)+" Hz", LogParameter::LOG_AVERAGE));
    emit logParameter(LogParameter("rateAND", QString::number(andRate)+" Hz", LogParameter::LOG_AVERAGE));
    while (xorRatePoints.size()>rateMaxShowInterval/rateBufferInterval){
        xorRatePoints.pop_front();
    }
    while (andRatePoints.size()>rateMaxShowInterval/rateBufferInterval){
        andRatePoints.pop_front();
    }
}

void Daemon::sendGpioRates(int number, quint8 whichRate){
    if (pigHandler==nullptr){
        return;
    }
    TcpMessage tcpMessage(gpioRateSig);
    QVector<QPointF> *ratePoints;
    if (whichRate==XOR_RATE){
         ratePoints = &xorRatePoints;
    }else if(whichRate==AND_RATE){
        ratePoints = &andRatePoints;
    }else{
        return;
    }
    QVector<QPointF> someRates;
    if (number >= ratePoints->size() || number == 0){
        number = ratePoints->size()-1;
    }
    if (!ratePoints->isEmpty()){
        for (int i = 0; i<number; i++){
            someRates.push_front(ratePoints->at(ratePoints->size()-1-i));
        }
    }
    *(tcpMessage.dStream) << whichRate << someRates;
    emit sendTcpMessage(tcpMessage);
}
void Daemon::sampleAdc0Event(){
    const uint8_t channel=0;
    if (adc==nullptr){
        return;
    }
    if (adc->getStatus() & i2cDevice::MODE_UNREACHABLE) return;
    TcpMessage tcpMessage(adcSampleSig);
    float value = adc->readVoltage(channel);
    *(tcpMessage.dStream) << (quint8)channel << value;
    emit sendTcpMessage(tcpMessage);
    pulseHeightHisto.fill(value);
	emit logParameter(LogParameter("adcSamplingTime", QString::number(adc->getLastConvTime())+" ms", LogParameter::LOG_AVERAGE));
	checkRescaleHisto(adcSampleTimeHisto, adc->getLastConvTime());
	adcSampleTimeHisto.fill(adc->getLastConvTime());
    currentAdcSampleIndex=0;
}

void Daemon::sampleAdc0TraceEvent(){
    const uint8_t channel=0;
    if (adc==nullptr){
        return;
    }
    if (adc->getStatus() & i2cDevice::MODE_UNREACHABLE) return;
    float value = adc->readVoltage(channel);
    adcSamplesBuffer.push_back(value);
    if (adcSamplesBuffer.size()>ADC_SAMPLEBUFFER_SIZE) adcSamplesBuffer.pop_front();
    if (currentAdcSampleIndex>=0) {
        currentAdcSampleIndex++;
        if (currentAdcSampleIndex >= ADC_SAMPLEBUFFER_SIZE-ADC_PRETRIGGER) {
            TcpMessage tcpMessage(adcTraceSig);
            *(tcpMessage.dStream) << (quint16) adcSamplesBuffer.size();
            for (int i=0; i<adcSamplesBuffer.size(); i++)
                *(tcpMessage.dStream) << adcSamplesBuffer[i];
            emit sendTcpMessage(tcpMessage);
            currentAdcSampleIndex = -1;
            //qDebug()<<"adc trace sent";
        }
    }
    emit logParameter(LogParameter("adcSamplingTime", QString::number(adc->getLastConvTime())+" ms", LogParameter::LOG_AVERAGE));
    checkRescaleHisto(adcSampleTimeHisto, adc->getLastConvTime());
    adcSampleTimeHisto.fill(adc->getLastConvTime());
}

void Daemon::sampleAdcEvent(uint8_t channel){
    if (adc==nullptr){
        return;
    }
    if (adc->getStatus() & i2cDevice::MODE_UNREACHABLE) return;
    TcpMessage tcpMessage(adcSampleSig);
    float value = adc->readVoltage(channel);
    *(tcpMessage.dStream) << (quint8)channel << value;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::getTemperature(){
    if (lm75==nullptr){
        return;
    }
    TcpMessage tcpMessage(temperatureSig);
    if (lm75->getStatus() & i2cDevice::MODE_UNREACHABLE) return;
    float value = lm75->getTemperature();
    *(tcpMessage.dStream) << value;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::setEventTriggerSelection(GPIO_PIN signal) {
	if (pigHandler==nullptr) return;
    auto it=GPIO_PINMAP.find(signal);
    if (it==GPIO_PINMAP.end()) return;
	
    if (verbose > 1){
        qDebug() << "changed event selection to signal " << (unsigned int)signal;
    }
    emit setSamplingTriggerSignal(signal);
	emit logParameter(LogParameter("gpioTriggerSelection", "0x"+QString::number((int)pigHandler->samplingTriggerSignal,16), LogParameter::LOG_EVERY));
    //sendEventTriggerSelection();
}

// ALL FUNCTIONS ABOUT SETTINGS FOR THE I2C-DEVICES (DAC, ADC, PCA...)
void Daemon::setPcaChannel(uint8_t channel) {
	if (!pca || !pca->devicePresent()) {
		return;
	}
	if (channel > ((HW_VERSION==1)?3:7)) {
        cerr << "invalid PCA channel selected (ch " <<(int)channel<<")"<< endl;
		return;
	}
    if (verbose > 1){
        qDebug() << "changed pcaPortMask to " << channel;
    }
    pcaPortMask = channel;
    pca->setOutputState(channel);
	emit logParameter(LogParameter("ubxInputSwitch", "0x"+QString::number(pcaPortMask,16), LogParameter::LOG_EVERY));
    //sendPcaChannel();
}

void Daemon::setBiasVoltage(float voltage) {
    biasVoltage = voltage;
    if (verbose > 1){
        qDebug() << "change biasVoltage to " << voltage;
    }
    if (dac && dac->devicePresent()) {
		dac->setVoltage(DAC_BIAS, voltage);
		emit logParameter(LogParameter("biasDAC", QString::number(voltage)+" V", LogParameter::LOG_EVERY));
    }
    clearRates();
    //sendBiasVoltage();
}

void Daemon::setBiasStatus(bool status){
    biasON = status;
    if (verbose > 1){
        qDebug() << "change biasStatus to " << status;
    }
    //emit GpioSetState(UBIAS_EN, status);

    if (status) {
        emit GpioSetState(GPIO_PINMAP[UBIAS_EN], (HW_VERSION==1)?1:0);
    }
    else {
        emit GpioSetState(GPIO_PINMAP[UBIAS_EN], (HW_VERSION==1)?0:1);
    }
    emit logParameter(LogParameter("biasSwitch", QString::number(status), LogParameter::LOG_EVERY));
    clearRates();
    //sendBiasStatus();
}

void Daemon::setDacThresh(uint8_t channel, float threshold) {
    if (threshold < 0 || channel > 3) { return; }
    if (channel==2 || channel==3) {
        if (dac->devicePresent()) {
            dac->setVoltage(channel, threshold);
        }
        return;
    }
    if (threshold > 4.095){
        threshold = 4.095;
    }
    if (verbose > 1){
        qDebug() << "change dacThresh " << channel << " to " << threshold;
    }
    dacThresh[channel] = threshold;
    clearRates();
    if (dac->devicePresent()) {
		dac->setVoltage(channel, threshold);
		emit logParameter(LogParameter("thresh"+QString::number(channel), QString::number(dacThresh[channel])+" V", LogParameter::LOG_EVERY));
	}
    //sendDacThresh(channel);
}

void Daemon::saveDacValuesToEeprom(){
    for (int i=0; i<4; i++) {
        MCP4728::DacChannel dacChannel;
        dac->readChannel(i, dacChannel);
        dacChannel.eeprom=true;
        dac->writeChannel(i, dacChannel);
    }
}

bool Daemon::readEeprom()
{
	if (eep==nullptr) return false;
	if (eep->devicePresent()) {
		if (verbose>2) cout<<"eep device is present."<<endl;
	} else {
		cerr<<"eeprom device NOT present!"<<endl;
		return false;
	}
	uint16_t n=256;
	uint8_t buf[256];
	for (int i=0; i<n; i++) buf[i]=0;
	bool retval=(eep->readBytes(0,n,buf)==n);
	cout<<"*** EEPROM content ***"<<endl;
	for (int j=0; j<16; j++) {
		cout<<hex<<std::setfill ('0') << std::setw (2)<<j*16<<": ";
		for (int i=0; i<16; i++) {
			cout<<hex<<std::setfill ('0') << std::setw (2)<<(int)buf[j*16+i]<<" ";
		}
		cout<<endl;
	}
	return retval;
}

void Daemon::setUbxMsgRates(QMap<uint16_t, int>& ubxMsgRates){
    for (QMap<uint16_t, int>::iterator it = ubxMsgRates.begin(); it != ubxMsgRates.end(); it++) {
        emit UBXSetCfgMsgRate(it.key(),1,it.value());
        emit sendPollUbxMsgRate(it.key());
        waitingForAppliedMsgRate++;
    }
}

// ALL FUNCTIONS ABOUT UBLOX GPS MODULE
void Daemon::configGps() {
	// set up ubx as only outPortProtocol
	//emit UBXSetCfgPrt(1,1); // enables on UART port (1) only the UBX protocol
	emit UBXSetCfgPrt(1, PROTO_UBX);

	// set dynamic model: Stationary
	emit UBXSetDynModel(2);
	
	emit UBXSetAopCfg(true);
	
	emit sendPollUbxMsg(UBX_MON_VER);

	// deactivate all NMEA messages: (port 6 means ALL ports)
	// not needed because of deactivation of all NMEA messages with "UBXSetCfgPrt"
//    msgRateCfgs.insert(UBX_NMEA_DTM,0);
//    // msgRateCfgs.insert(UBX_NMEA_GBQ,0);
//    msgRateCfgs.insert(UBX_NMEA_GBS,0);
//    msgRateCfgs.insert(UBX_NMEA_GGA,0);
//    msgRateCfgs.insert(UBX_NMEA_GLL,0);
//    // msgRateCfgs.insert(UBX_NMEA_GLQ,0);
//    // msgRateCfgs.insert(UBX_NMEA_GNQ,0);
//    msgRateCfgs.insert(UBX_NMEA_GNS,0);
//    // msgRateCfgs.insert(UBX_NMEA_GPQ,0);
//    msgRateCfgs.insert(UBX_NMEA_GRS,0);
//    msgRateCfgs.insert(UBX_NMEA_GSA,0);
//    msgRateCfgs.insert(UBX_NMEA_GST,0);
//    msgRateCfgs.insert(UBX_NMEA_GSV,0);
//    msgRateCfgs.insert(UBX_NMEA_RMC,0);
//    // msgRateCfgs.insert(UBX_NMEA_TXT,0);
//    msgRateCfgs.insert(UBX_NMEA_VLW,0);
//    msgRateCfgs.insert(UBX_NMEA_VTG,0);
//    msgRateCfgs.insert(UBX_NMEA_ZDA,0);
//    msgRateCfgs.insert(UBX_NMEA_POSITION,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_DTM,6,0);
//    // has no output msg UBX_NMEA_GBQ
//    emit UBXSetCfgMsgRate(UBX_NMEA_GBS,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_GGA,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_GLL,6,0);
//    // has no output msg UBX_NMEA_GLQ
//    // has no output msg UBX_NMEA_GNQ
//    emit UBXSetCfgMsgRate(UBX_NMEA_GNS,6,0);
//    // has no output msg UBX_NMEA_GPQ
//    emit UBXSetCfgMsgRate(UBX_NMEA_GRS,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_GSA,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_GST,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_GSV,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_RMC,6,0);
//    // is not configured through UBX_CFG_MSG but through UBX-CFG-INF!!!  (UBX_NMEA_TXT)
//    //emit UBXSetCfgMsgRate(UBX_NMEA_VLW,6,0); don't know why this does not work, probably not supported anymore
//    emit UBXSetCfgMsgRate(UBX_NMEA_VTG,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_ZDA,6,0);
//    emit UBXSetCfgMsgRate(UBX_NMEA_POSITION,6,0);

	// set protocol configuration for ports
	// msgRateCfgs: -1 means unknown, 0 means off, some positive value means update time
    int measrate = 10;
    // msgRateCfgs.insert(UBX_CFG_RATE, measrate);
    // msgRateCfgs.insert(UBX_TIM_TM2, 1);
    // msgRateCfgs.insert(UBX_TIM_TP, 51);
    // msgRateCfgs.insert(UBX_NAV_TIMEUTC, 20);
    // msgRateCfgs.insert(UBX_MON_HW, 47);
	// msgRateCfgs.insert(UBX_NAV_SAT, 59);
    // msgRateCfgs.insert(UBX_NAV_TIMEGPS, 61);
    // msgRateCfgs.insert(UBX_NAV_SOL, 67);
    // msgRateCfgs.insert(UBX_NAV_STATUS, 71);
    // msgRateCfgs.insert(UBX_NAV_CLOCK, 89);
    // msgRateCfgs.insert(UBX_MON_TXBUF, 97);
    // msgRateCfgs.insert(UBX_NAV_SBAS, 255);
    // msgRateCfgs.insert(UBX_NAV_DOP, 101);
    // msgRateCfgs.insert(UBX_NAV_SVINFO, 49);
    emit UBXSetCfgRate(1000/measrate, 1); // UBX_RATE

	//emit sendPollUbxMsg(UBX_MON_VER);
	emit UBXSetCfgMsgRate(UBX_TIM_TM2, 1, 1);	// TIM-TM2
	emit UBXSetCfgMsgRate(UBX_TIM_TP, 1, 0);	// TIM-TP
	emit UBXSetCfgMsgRate(UBX_NAV_TIMEUTC, 1, 131);	// NAV-TIMEUTC
	emit UBXSetCfgMsgRate(UBX_MON_HW, 1, 47);	// MON-HW
	emit UBXSetCfgMsgRate(UBX_MON_HW2, 1, 49);	// MON-HW
	emit UBXSetCfgMsgRate(UBX_NAV_POSLLH, 1, 127);	// MON-POSLLH
	// probably also configured with UBX-CFG-INFO...
	emit UBXSetCfgMsgRate(UBX_NAV_TIMEGPS, 1, 0);	// NAV-TIMEGPS
	emit UBXSetCfgMsgRate(UBX_NAV_SOL, 1, 0);	// NAV-SOL
	emit UBXSetCfgMsgRate(UBX_NAV_STATUS, 1, 71);	// NAV-STATUS
	emit UBXSetCfgMsgRate(UBX_NAV_CLOCK, 1, 189);	// NAV-CLOCK
	emit UBXSetCfgMsgRate(UBX_MON_RXBUF, 1, 53);	// MON-TXBUF
	emit UBXSetCfgMsgRate(UBX_MON_TXBUF, 1, 51);	// MON-TXBUF
	emit UBXSetCfgMsgRate(UBX_NAV_SBAS, 1, 0);	// NAV-SBAS
	emit UBXSetCfgMsgRate(UBX_NAV_DOP, 1, 254);	// NAV-DOP
	// this poll is for checking the port cfg (which protocols are enabled etc.)
	emit sendPollUbxMsg(UBX_CFG_PRT);
	emit sendPollUbxMsg(UBX_MON_VER);
	emit sendPollUbxMsg(UBX_MON_VER);
	emit sendPollUbxMsg(UBX_MON_VER);
    emit sendPollUbxMsg(UBX_CFG_GNSS);
	//emit UBXSetMinCNO(5);
	emit sendPollUbxMsg(UBX_CFG_NAVX5);
	emit sendPollUbxMsg(UBX_CFG_ANT);
	emit sendPollUbxMsg(UBX_CFG_TP5);

	configGpsForVersion();
}

void Daemon::configGpsForVersion() {
	if (QtSerialUblox::getProtVersion()<=0.1) return;
	if (QtSerialUblox::getProtVersion()>15.0) {
		if (std::find(allMsgCfgID.begin(), allMsgCfgID.end(), UBX_NAV_SAT)==allMsgCfgID.end()) {
			allMsgCfgID.push_back(UBX_NAV_SAT);
		}
		emit UBXSetCfgMsgRate(UBX_NAV_SAT, 1, 69);	// NAV-SAT 
		emit UBXSetCfgMsgRate(UBX_NAV_SVINFO, 1, 0);
	} else emit UBXSetCfgMsgRate(UBX_NAV_SVINFO, 1, 69);	// NAV-SVINFO
	//cout<<"prot Version: "<<QtSerialUblox::getProtVersion()<<endl;
}

void Daemon::pollAllUbxMsgRate() {
	for (const auto& elem : allMsgCfgID) {
		emit sendPollUbxMsgRate(elem);
	}
}

void Daemon::UBXReceivedAckNak(uint16_t ackedMsgID, uint16_t ackedCfgMsgID) {
	// the value was already set correctly before by either poll or set,
	// if not acknowledged or timeout we set the value to -1 (unknown/undefined)
	switch (ackedMsgID) {
	case UBX_CFG_MSG:
		msgRateCfgs.insert(ackedCfgMsgID, -1);
		break;
	default:
		break;
	}
}

void Daemon::UBXReceivedMsgRateCfg(uint16_t msgID, uint8_t rate) {
	msgRateCfgs.insert(msgID, rate);
    waitingForAppliedMsgRate--;
    if (waitingForAppliedMsgRate<0){
        waitingForAppliedMsgRate = 0;
    }
    if (waitingForAppliedMsgRate==0){
        sendUbxMsgRates();
    }
}

void Daemon::onGpsMonHWUpdated(uint16_t noise, uint16_t agc, uint8_t antStatus, uint8_t antPower, uint8_t jamInd, uint8_t flags)
{
    TcpMessage tcpMessage(gpsMonHWSig);
    (*tcpMessage.dStream) << (quint16)noise << (quint16)agc << (quint8) antStatus
    << (quint8)antPower << (quint8)jamInd << (quint8)flags;
    emit sendTcpMessage(tcpMessage);
	emit logParameter(LogParameter("preampNoise", QString::number(-noise)+" dBHz", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("preampAGC", QString::number(agc), LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("antennaStatus", QString::number(antStatus), LogParameter::LOG_LATEST));
	emit logParameter(LogParameter("antennaPower", QString::number(antPower), LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("jammingLevel", QString::number(jamInd/2.55,'f',1)+" %", LogParameter::LOG_AVERAGE));
}

void Daemon::onGpsMonHW2Updated(int8_t ofsI, uint8_t magI, int8_t ofsQ, uint8_t magQ, uint8_t cfgSrc)
{
    TcpMessage tcpMessage(gpsMonHW2Sig);
    (*tcpMessage.dStream) << (qint8)ofsI << (quint8)magI << (qint8)ofsQ
    << (quint8)magQ << (quint8)cfgSrc;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::onGpsPropertyUpdatedGnss(const std::vector<GnssSatellite>& sats,
	std::chrono::duration<double> lastUpdated) {
	vector<GnssSatellite> visibleSats = sats;
	std::sort(visibleSats.begin(), visibleSats.end(), GnssSatellite::sortByCnr);
	while (visibleSats.size() > 0 && visibleSats.back().getCnr() == 0) visibleSats.pop_back();

	if (verbose > 3) {
		cout << std::chrono::system_clock::now()
			- std::chrono::duration_cast<std::chrono::microseconds>(lastUpdated)
			<< "Nr of satellites: " << visibleSats.size() <<" (out of "<< sats.size() << endl;
		// read nrSats property without evaluation to prevent separate display of this property
		// in the common message poll below
		GnssSatellite::PrintHeader(true);
		for (unsigned int i = 0; i < sats.size(); i++) {
			sats[i].Print(i, false);
		}
	}
	int N=sats.size();
	TcpMessage tcpMessage(gpsSatsSig);
	(*tcpMessage.dStream) << N;
	for (int i=0; i<N; i++) {
		(*tcpMessage.dStream)<< sats [i];
	}
	emit sendTcpMessage(tcpMessage);
	nrSats=QVariant(N);
	nrVisibleSats=QVariant(visibleSats.size());
	
	int usedSats=0, maxCnr=0;
	if (visibleSats.size()) {
		for (auto sat : visibleSats){
			if (sat.fUsed) usedSats++;
			if (sat.fCnr>maxCnr) maxCnr=sat.fCnr;
		}
	}
        //qDebug() << "received satlist ok, size=" << satlist.size();
	emit logParameter(LogParameter("sats",QString("%1").arg(visibleSats.size()), LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("usedSats",QString("%1").arg(usedSats), LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("maxCNR",QString("%1").arg(maxCnr), LogParameter::LOG_AVERAGE));
}

void Daemon::onUBXReceivedGnssConfig(uint8_t numTrkCh, const std::vector<GnssConfigStruct>& gnssConfigs) {
	if (verbose > 2) {
		// put some verbose output here
	}
    int N=gnssConfigs.size();
    TcpMessage tcpMessage(gnssConfigSig);
    (*tcpMessage.dStream) << (int)numTrkCh << N;
    for (int i=0; i<N; i++) {
		(*tcpMessage.dStream)<<gnssConfigs[i].gnssId<<gnssConfigs[i].resTrkCh<<
		gnssConfigs[i].maxTrkCh<<gnssConfigs[i].flags;
	}
    emit sendTcpMessage(tcpMessage);
}

void Daemon::onUBXReceivedTP5(const UbxTimePulseStruct& tp) {
	if (verbose > 2) {
		// put some verbose output here
	}
    TcpMessage tcpMessage(gpsCfgTP5Sig);
    (*tcpMessage.dStream) << tp;
    emit sendTcpMessage(tcpMessage);
}

void Daemon::onUBXReceivedTxBuf(uint8_t txUsage, uint8_t txPeakUsage) {
	TcpMessage* tcpMessage;
	if (verbose>2) {
		cout << "TX buf usage: " << (int)txUsage << " %" << endl;
		cout << "TX buf peak usage: " << (int)txPeakUsage << " %" << endl;
	}
	tcpMessage = new TcpMessage(gpsTxBufSig);
	*(tcpMessage->dStream) << (quint8)txUsage << (quint8)txPeakUsage;
	emit sendTcpMessage(*tcpMessage);
	delete tcpMessage;
	emit logParameter(LogParameter("TXBufUsage", QString::number(txUsage)+" %", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("maxTXBufUsage", QString::number(txPeakUsage)+" %", LogParameter::LOG_LATEST));
}

void Daemon::onUBXReceivedRxBuf(uint8_t rxUsage, uint8_t rxPeakUsage) {
	TcpMessage* tcpMessage;
	if (verbose>2) {
		cout << "RX buf usage: " << (int)rxUsage << " %" << endl;
		cout << "RX buf peak usage: " << (int)rxPeakUsage << " %" << endl;
	}
	tcpMessage = new TcpMessage(gpsRxBufSig);
	*(tcpMessage->dStream) << (quint8)rxUsage << (quint8)rxPeakUsage;
	emit sendTcpMessage(*tcpMessage);
	delete tcpMessage;
	emit logParameter(LogParameter("RXBufUsage", QString::number(rxUsage)+" %", LogParameter::LOG_AVERAGE));
	emit logParameter(LogParameter("maxRXBufUsage", QString::number(rxPeakUsage)+" %", LogParameter::LOG_LATEST));
}

void Daemon::gpsPropertyUpdatedUint8(uint8_t data, std::chrono::duration<double> updateAge,
	char propertyName) {
	TcpMessage* tcpMessage;
	switch (propertyName) {
	case 's':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "Nr of available satellites: " << (int)data << endl;
		break;
	case 'e':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "quant error: " << (int)data << " ps" << endl;
		break;
	/*
	case 'b':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "TX buf usage: " << (int)data << " %" << endl;
		tcpMessage = new TcpMessage(gpsTxBufSig);
		*(tcpMessage->dStream) << (quint8)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("TXBufUsage", QString::number(data)+" %", LogParameter::LOG_LATEST));
		break;
	case 'p':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "TX buf peak usage: " << (int)data << " %" << endl;
		tcpMessage = new TcpMessage(gpsTxBufPeakSig);
		*(tcpMessage->dStream) << (quint8)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("maxTXBufUsage", QString::number(data)+" %", LogParameter::LOG_LATEST));
		break;
	*/
	case 'f':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "Fix value: " << (int)data << endl;
		tcpMessage = new TcpMessage(gpsFixSig);
		*(tcpMessage->dStream) << (quint8)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("fixStatus", QString::number(data), LogParameter::LOG_LATEST));
		fixStatus=QVariant(data);
		break;
	default:
		break;
	}
}

void Daemon::gpsPropertyUpdatedUint32(uint32_t data, chrono::duration<double> updateAge,
	char propertyName) {
	TcpMessage* tcpMessage;
	switch (propertyName) {
	case 'a':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "time accuracy: " << data << " ns" << endl;
		tcpMessage = new TcpMessage(gpsTimeAccSig);
		*(tcpMessage->dStream) << (quint32)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("timeAccuracy", QString::number(data)+" ns", LogParameter::LOG_AVERAGE));
		break;
	case 'f':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "frequency accuracy: " << data << " ps/s" << endl;
		tcpMessage = new TcpMessage(gpsFreqAccSig);
		*(tcpMessage->dStream) << (quint32)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("freqAccuracy", QString::number(data)+" ps/s", LogParameter::LOG_AVERAGE));
		break;
	case 'u':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "Ublox uptime: " << data << " s" << endl;
		tcpMessage = new TcpMessage(gpsUptimeSig);
		*(tcpMessage->dStream) << (quint32)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		emit logParameter(LogParameter("ubloxUptime", QString::number(data)+" s", LogParameter::LOG_LATEST));
		break;
	case 'c':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "rising edge counter: " << data << endl;
		tcpMessage = new TcpMessage(gpsIntCounterSig);
		*(tcpMessage->dStream) << (quint32)data;
		emit sendTcpMessage(*tcpMessage);
		delete tcpMessage;
		break;
	default:
		break;
	}
}

void Daemon::gpsPropertyUpdatedInt32(int32_t data, std::chrono::duration<double> updateAge,
	char propertyName) {
	switch (propertyName) {
	case 'd':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "clock drift: " << data << " ns/s" << endl;
		logParameter(LogParameter("clockDrift", QString::number(data)+" ns/s", LogParameter::LOG_AVERAGE));
		break;
	case 'b':
		if (verbose>2)
			cout << std::chrono::system_clock::now()
				- std::chrono::duration_cast<std::chrono::microseconds>(updateAge)
				<< "clock bias: " << data << " ns" << endl;
		emit logParameter(LogParameter("clockBias", QString::number(data)+" ns", LogParameter::LOG_AVERAGE));
		break;
	default:
		break;
	}
}


void Daemon::UBXReceivedVersion(const QString& swString, const QString& hwString, const QString& protString)
{
    static bool initialVersionInfo = true;
    TcpMessage tcpMessage(gpsVersionSig);
    (*tcpMessage.dStream) << swString << hwString << protString;
    emit sendTcpMessage(tcpMessage);
	logParameter(LogParameter("UBX_SW_Version", swString, LogParameter::LOG_ONCE));
	logParameter(LogParameter("UBX_HW_Version", hwString, LogParameter::LOG_ONCE));
	logParameter(LogParameter("UBX_Prot_Version", protString, LogParameter::LOG_ONCE));
	if (initialVersionInfo) {
		configGpsForVersion();
	}
	initialVersionInfo = false;
}

void Daemon::toConsole(const QString &data) {
	cout << data << endl;
}

void Daemon::gpsToConsole(const QString &data) {
	cout << data << flush;
}

void Daemon::gpsConnectionError() {

}


// ALL OTHER UTITLITY FUNCTIONS
void Daemon::onMadeConnection(QString remotePeerAddress, quint16 remotePeerPort, QString localAddress, quint16 localPort) {
	if (verbose>3) cout << "established connection with " << remotePeerAddress << ":" << remotePeerPort << endl;

	emit sendPollUbxMsg(UBX_MON_VER);
	emit sendPollUbxMsg(UBX_CFG_GNSS);
	emit sendPollUbxMsg(UBX_CFG_NAV5);
	emit sendPollUbxMsg(UBX_CFG_TP5);
	emit sendPollUbxMsg(UBX_CFG_NAVX5);

	sendBiasStatus();
	sendBiasVoltage();
	sendDacThresh(0);
	sendDacThresh(1);
	sendPcaChannel();
	sendEventTriggerSelection();
}

void Daemon::onStoppedConnection(QString remotePeerAddress, quint16 remotePeerPort, QString localAddress, quint16 localPort,
		quint32 timeoutTime, quint32 connectionDuration) {
	if (verbose>3) {
		cout << "stopped connection with " << remotePeerAddress << ":" << remotePeerPort << endl;
		cout << "connection timeout at " << timeoutTime << "  connection lasted " << connectionDuration << "s" << endl;
	}
}

void Daemon::displayError(QString message)
{
	cout << "Daemon: " << message << endl;
}

void Daemon::displaySocketError(int socketError, QString message)
{
	switch (socketError) {
	case QAbstractSocket::HostNotFoundError:
		cout << tr("The host was not found. Please check the "
			"host and port settings.\n");
		break;
	case QAbstractSocket::ConnectionRefusedError:
		cout << tr("The connection was refused by the peer. "
			"Make sure the server is running, "
			"and check that the host name and port "
			"settings are correct.\n");
		break;
	default:
		cout << tr("The following error occurred: %1.\n").arg(message);
	}
	flush(cout);
}

void Daemon::delay(int millisecondsWait)
{
	QEventLoop loop;
	QTimer t;
	t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
	t.start(millisecondsWait);
	loop.exec();
}

void Daemon::printTimestamp()
{
	std::chrono::time_point<std::chrono::system_clock> timestamp = std::chrono::system_clock::now();
	std::chrono::microseconds mus = std::chrono::duration_cast<std::chrono::microseconds>(timestamp.time_since_epoch());
	std::chrono::seconds secs = std::chrono::duration_cast<std::chrono::seconds>(mus);
	std::chrono::microseconds subs = mus - secs;


	// 	t1 = std::chrono::system_clock::now();
	// 	t2 = std::chrono::duration_cast<std::chrono::seconds>(t1);
		//double subs=timestamp-(long int)timestamp;
	cout << secs.count() << "." << setw(6) << setfill('0') << subs.count() << " " << setfill(' ');
}

// some signal handling stuff
void Daemon::hupSignalHandler(int)
{
	char a = 1;
	::write(sighupFd[0], &a, sizeof(a));
}

void Daemon::termSignalHandler(int)
{
	char a = 1;
	::write(sigtermFd[0], &a, sizeof(a));
}
void Daemon::intSignalHandler(int) {
	char a = 1;
	::write(sigintFd[0], &a, sizeof(a));
}

void Daemon::logBiasValues()
{
	double v1=0.,v2=0.;
	if (adc && (!(adc->getStatus() & i2cDevice::MODE_UNREACHABLE)) && (adc->getStatus() & (i2cDevice::MODE_NORMAL | i2cDevice::MODE_FORCE))) {
		v1=adc->readVoltage(2);
		v2=adc->readVoltage(3);
		if (calib && calib->getCalibItem("VDIV").name=="VDIV") {
			CalibStruct vdivItem=calib->getCalibItem("VDIV");
			std::istringstream istr(vdivItem.value);
			double vdiv;
			istr >> vdiv;
			vdiv/=100.;
			logParameter(LogParameter("calib_vdiv", QString::number(vdiv), LogParameter::LOG_ONCE));
//			istr=std::istringstream(calib->getCalibItem("RSENSE").value);
			istr.clear();
			istr.str(calib->getCalibItem("RSENSE").value);
			double rsense;
			istr >> rsense;
            if (verbose>2){
                cout<<"rsense:"<<calib->getCalibItem("RSENSE").value<<" ("<<rsense<<")"<<endl;
            }
            rsense /= 10.*1000.; // yields Rsense in MOhm
            logParameter(LogParameter("calib_rsense", QString::number(rsense*1000.)+" kOhm", LogParameter::LOG_ONCE));
//			logParameter(LogParameter("vbias1", QString::number(v1*vdiv)+" V", LogParameter::LOG_AVERAGE));
//			logParameter(LogParameter("vbias2", QString::number(v2*vdiv)+" V", LogParameter::LOG_AVERAGE));
            double ubias=v2*vdiv;
			logParameter(LogParameter("vbias", QString::number(ubias)+" V", LogParameter::LOG_AVERAGE));
			double usense=(v1-v2)*vdiv;
			logParameter(LogParameter("vsense", QString::number(usense)+" V", LogParameter::LOG_AVERAGE));
			
			CalibStruct flagItem=calib->getCalibItem("CALIB_FLAGS");
			int calFlags=0;
//			istr=std::istringstream(flagItem.value);
			
			istr.clear();
			istr.str(flagItem.value);
            istr >> calFlags;
            if (verbose>2){
                cout<<"cal flags:"<<flagItem.value<<" ("<<(int)calFlags<<dec<<")"<<endl;
            }
            if (calFlags & CalibStruct::CALIBFLAGS_CURRENT_COEFFS) {
				double islope,ioffs;
//				istr=std::istringstream(calib->getCalibItem("COEFF2").value);
				istr.clear();
				istr.str(calib->getCalibItem("COEFF2").value);
				istr >> ioffs;
				logParameter(LogParameter("calib_coeff2", QString::number(ioffs), LogParameter::LOG_ONCE));
//				istr=std::istringstream(calib->getCalibItem("COEFF3").value);
				istr.clear();
				istr.str(calib->getCalibItem("COEFF3").value);
				istr >> islope;
				logParameter(LogParameter("calib_coeff3", QString::number(islope), LogParameter::LOG_ONCE));
				double icorr = ubias*islope+ioffs;
				double ibias = usense/rsense-icorr;
				logParameter(LogParameter("ibias", QString::number(ibias)+" uA", LogParameter::LOG_AVERAGE));
			}
		} else {
			logParameter(LogParameter("vadc3", QString::number(v1)+" V", LogParameter::LOG_AVERAGE));
			logParameter(LogParameter("vadc4", QString::number(v2)+" V", LogParameter::LOG_AVERAGE));
		}
	}
}

void Daemon::onLogParameterPolled(){
    // connect to the regular log timer signal to log several non-regularly polled parameters
    /*
    double xorRate = 0.0;
    if (!xorRatePoints.isEmpty()){
        xorRate = xorRatePoints.back().y();
    }
    logParameter(LogParameter("rateXOR", QString::number(xorRate)+" Hz"));
    double andRate = 0.0;
    if (!andRatePoints.isEmpty()){
        andRate = andRatePoints.back().y();
    }
    logParameter(LogParameter("rateAND", QString::number(andRate)+" Hz"));
    */
    emit logParameter(LogParameter("biasSwitch", QString::number(biasON), LogParameter::LOG_ON_CHANGE));
    emit logParameter(LogParameter("preampSwitch1", QString::number((int)preampStatus[0]), LogParameter::LOG_ON_CHANGE));
    emit logParameter(LogParameter("preampSwitch2", QString::number((int)preampStatus[1]), LogParameter::LOG_ON_CHANGE));
    emit logParameter(LogParameter("gainSwitch", QString::number((int)gainSwitch), LogParameter::LOG_ON_CHANGE));
    if (lm75 && lm75->devicePresent()) emit logParameter(LogParameter("temperature", QString::number(lm75->getTemperature())+" degC", LogParameter::LOG_AVERAGE));

    if (dac && dac->devicePresent()) {
        emit logParameter(LogParameter("thresh1", QString::number(dacThresh[0])+" V", LogParameter::LOG_ON_CHANGE));
        emit logParameter(LogParameter("thresh2", QString::number(dacThresh[1])+" V", LogParameter::LOG_ON_CHANGE));
        emit logParameter(LogParameter("biasDAC", QString::number(biasVoltage)+" V", LogParameter::LOG_ON_CHANGE));
    }

    if (pca && pca->devicePresent()) emit logParameter(LogParameter("ubxInputSwitch", "0x"+QString::number(pcaPortMask,16), LogParameter::LOG_ON_CHANGE));
    if (pigHandler!=nullptr) emit logParameter(LogParameter("gpioTriggerSelection", "0x"+QString::number((int)pigHandler->samplingTriggerSignal,16), LogParameter::LOG_ON_CHANGE));
    logBiasValues();
    if (adc && !(adc->getStatus() & i2cDevice::MODE_UNREACHABLE)) {
/*
        emit logParameter(LogParameter("adcSamplingTime", QString::number(adc->getLastConvTime())+" ms", LogParameter::LOG_ON_CHANGE));
        checkRescaleHisto(adcSampleTimeHisto, adc->getLastConvTime());
        adcSampleTimeHisto.fill(adc->getLastConvTime());
*/
        sendHistogram(adcSampleTimeHisto);
        sendHistogram(pulseHeightHisto);
    }
    sendHistogram(ubxTimeLengthHisto);
    sendHistogram(eventIntervalHisto);
    sendHistogram(eventIntervalShortHisto);
    sendHistogram(ubxTimeIntervalHisto);
    sendHistogram(tpTimeDiffHisto);
    sendHistogram(tdc7200Histo);

//		updateOledDisplay();
}

void Daemon::onUBXReceivedTimeTM2(timespec rising, timespec falling, uint32_t accEst, bool valid, uint8_t timeBase, bool utcAvailable)
{
	long double dts=(falling.tv_sec-rising.tv_sec)*1e9;
	dts+=(falling.tv_nsec-rising.tv_nsec);
	if (dts>0.) {
		checkRescaleHisto(ubxTimeLengthHisto, dts);
		ubxTimeLengthHisto.fill(dts);
	}
	long double interval=(rising.tv_sec-lastTimestamp.tv_sec)*1e9;
	interval+=(rising.tv_nsec-lastTimestamp.tv_nsec);
	ubxTimeIntervalHisto.fill(1e-6*interval);
	lastTimestamp=rising;
}

void Daemon::updateOledDisplay() {
	if (!oled->devicePresent()) return;
	oled->clearDisplay();
	oled->setCursor(0,2);
	oled->print("*Cosmic Shower Det.*\n");
//	oled->printf("rate (XOR) %4.2f 1/s\n", getRateFromCounts(XOR_RATE));
//	oled->printf("rate (AND) %4.2f 1/s\n", getRateFromCounts(AND_RATE));
	oled->printf("Rates %4.1f %4.1f /s\n", getRateFromCounts(AND_RATE), getRateFromCounts(XOR_RATE));
//	oled->printf("temp %4.2f %cC\n", lm75->lastTemperatureValue(), DEGREE_CHARCODE);
	oled->printf("temp %4.2f %cC\n", lm75->getTemperature(), DEGREE_CHARCODE);
	oled->printf("%d(%d) Sats ", nrVisibleSats().toInt(), nrSats().toInt(), DEGREE_CHARCODE);
	oled->printf("%s\n", FIX_TYPE_STRINGS[fixStatus().toInt()].toStdString().c_str());
	oled->display();
}
