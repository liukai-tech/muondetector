#include <qtserialublox.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <QEventLoop>
#include <ublox_messages.h>

using namespace std;

#define MAX_SEND_RETRIES 5

string QtSerialUblox::fProtVersionString = "";


std::string QtSerialUblox::toStdString(unsigned char* data, int dataSize) {
	std::stringstream tempStream;
	for (int i = 0; i < dataSize; i++) {
		tempStream << data[i];
	}
	return tempStream.str();
}

QtSerialUblox::QtSerialUblox(const QString serialPortName, int newTimeout, int baudRate,
	bool newDumpRaw, int newVerbose, bool newShowout, bool newShowin, QObject *parent) : QObject(parent)
{
	_portName = serialPortName;
	_baudRate = baudRate;
	verbose = newVerbose;
	dumpRaw = newDumpRaw;
	showout = newShowout;
	showin = newShowin;
	timeout = newTimeout;
}

void QtSerialUblox::makeConnection() {
	// this function gets called with a signal from client-thread
	// (QtSerialUblox runs in a separate thread only communicating with main thread through messages)
	if (verbose > 3) {
		emit toConsole(QString("gps running in thread " + QString("0x%1\n").arg((int)this->thread())));
	}
    if (!serialPort.isNull()) {
        serialPort.clear();
	}
	serialPort = new QSerialPort(_portName);
	serialPort->setBaudRate(_baudRate);
	if (!serialPort->open(QIODevice::ReadWrite)) {
		emit gpsConnectionError();
		emit toConsole(QObject::tr("Failed to open port %1, error: %2\ntrying again in %3 seconds\n")
			.arg(_portName)
			.arg(serialPort->errorString())
			.arg(timeout));
        serialPort.clear();
		delay(timeout);
		emit gpsRestart();
		this->deleteLater();
		return;
	}
	ackTimer = new QTimer();
	connect(ackTimer, &QTimer::timeout, this, &QtSerialUblox::ackTimeout);
	connect(serialPort, &QSerialPort::readyRead, this, &QtSerialUblox::onReadyRead);
	serialPort->clear(QSerialPort::AllDirections);
	if (verbose == 1) {
		emit toConsole("rising               falling               accEst valid timebase utc\n");
	}
}

void QtSerialUblox::sendQueuedMsg(bool afterTimeout) {
	if (afterTimeout) {
        if (msgWaitingForAck==nullptr) {
			return;
		}
		if (++sendRetryCounter >= MAX_SEND_RETRIES) {
			sendRetryCounter=0;
			ackTimer->stop();
            delete msgWaitingForAck;
            msgWaitingForAck = nullptr;
			if (verbose > 1) emit toConsole("sendQueuedMsg: deleted message after 5 timeouts\n");
			sendQueuedMsg();
			return;
		}
		ackTimer->start(timeout);
		sendUBX(*msgWaitingForAck);
		if (verbose > 1) emit toConsole("sendQueuedMsg: repeated resend after timeout\n");
		return;
	}
	if (outMsgBuffer.empty()) { return; }
	if (msgWaitingForAck) {
		if (verbose > 1) {
			emit toConsole("tried to send queued message but ack for previous message not yet received\n");
		}
		return;
	}
	msgWaitingForAck = new UbxMessage;
	*msgWaitingForAck = outMsgBuffer.front();
	ackTimer->setSingleShot(true);
	ackTimer->start(timeout);
	sendUBX(*msgWaitingForAck);
	if (verbose > 2) emit toConsole("sendQueuedMsg: sent fresh message\n");
	outMsgBuffer.pop();
}

void QtSerialUblox::ackTimeout() {
    if (msgWaitingForAck==nullptr) {
		return;
	}
	if (verbose > 1) {
		std::stringstream tempStream;
		tempStream << "ack timeout, trying to resend message 0x" << std::setfill('0') << std::setw(2) << hex
			<< ((msgWaitingForAck->msgID & 0xff00) >> 8) << " 0x" << std::setfill('0') << std::setw(2) << hex << (msgWaitingForAck->msgID & 0x00ff);
		for (unsigned int i = 0; i < msgWaitingForAck->data.length(); i++) {
			tempStream << " 0x" << std::setfill('0') << std::setw(2) << hex << (int)(msgWaitingForAck->data[i]);
		}
		tempStream << endl;
		emit toConsole(QString::fromStdString(tempStream.str()));
	}
	sendQueuedMsg(true);
}

void QtSerialUblox::onReadyRead() {
	// this function gets called when the serial port emits readyRead signal
	//cout << "\nstart readyread" <<endl;
    if (serialPort.isNull()){
        return;
    }
	QByteArray temp = serialPort->readAll();
	if (dumpRaw) {
		emit toConsole(QString(temp));
		// if put std::string to console it gets stuck!?
		//emit stdToConsole(temp.toStdString());
	}
	//buffer += temp.toStdString();
//	buffer += QString::fromLocal8Bit(temp.data()).toStdString();
	for (int i=0; i<temp.size(); i++) {
		buffer+=temp.data()[i];
	}
	//buffer += std::string(temp.constData());
	//cout<<"buffer: "<<buffer;
	//cout << QString(temp).toStdString();
	UbxMessage message;
	while (scanUnknownMessage(buffer, message)) {
		// so it found a message therefore we can now process the message
		if (showin) {
			std::stringstream tempStream;
			tempStream << " in: ";
			int classID = (int)((message.msgID & 0xff00) >> 8);
			int msgID = (int)(message.msgID & 0xff);
			tempStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << classID;
			tempStream << " 0x" << std::setfill('0') << std::setw(2) << std::hex << msgID << " ";
			for (std::string::size_type i = 0; i < message.data.length(); i++) {
				tempStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)(message.data[i]) << " ";
			}
			tempStream << "\n";
			emit toConsole(QString::fromStdString(tempStream.str()));
		}
		processMessage(message);
	}
}

bool QtSerialUblox::scanUnknownMessage(string &buffer, UbxMessage &message)
{   // gets the (maybe not finished) buffer and checks for messages in it that make sense
	if (buffer.size() < 9) return false;
	std::string refstr = "";
	// refstr are the first two hex numbers defining the header of an ubx message
	refstr += 0xb5; refstr += 0x62;
	std::string::size_type found = buffer.find(refstr);
	std::string mess = "";
	if (found != string::npos)
	{
		mess = buffer.substr(found, buffer.size());
		// discard everything before start of the message
		buffer.erase(0, found);
	}
	else {
		// discard everything before the start of a NMEA message, too
		// to ensure that buffer won't grow too big
		if (discardAllNMEA) {
			std::string beginNMEA = "$";
			size_t found = 0;
			while (found != string::npos) {
				found = buffer.find(beginNMEA);
				if (found == string::npos) {
					break;
				}
				buffer.erase(0, found + 1);
			}
		}
		return false;
	}
	// message.classID = (uint8_t)mess[2];
	// message.messageID = (uint8_t)mess[3];
	message.msgID = (uint16_t)mess[2] << 8;
	message.msgID += (uint16_t)mess[3];
	if (mess.size() < 8) return false;
	int len = (int)(mess[4]);
	len += ((int)(mess[5])) << 8;
	if (((long int)mess.size() - 8) < len) {
		std::string::size_type found = buffer.find(refstr, 2);
		if (found != string::npos) {
			if (verbose > 1) {
				std::stringstream tempStream;
				tempStream << "received faulty UBX string:\n " << dec;
				for (std::string::size_type i = 0; i < found; i++) tempStream
					<< setw(2) << hex << "0x" << (int)buffer[i] << " ";
				tempStream << endl;
				emit toConsole(QString::fromStdString(tempStream.str()));
			}
			buffer.erase(0, found);
		}
		return false;
	}
	buffer.erase(0, len + 8);

	unsigned char chkA;
	unsigned char chkB;
	calcChkSum(mess.substr(0, len + 6), &chkA, &chkB);
	if (mess[len + 6] == chkA && mess[len + 7] == chkB)
	{
		message.data = mess.substr(6, len);
		return true;
	}

	return false;
}

bool QtSerialUblox::sendUBX(uint16_t msgID, const std::string& payload, uint16_t nBytes)
{
	//    std::cout << "0x"<< std::setfill('0') << std::setw(2) << std::hex << ((msgID & 0xff00) >> 8)
	//                     << std::setfill('0') << std::setw(2) << std::hex << (msgID & 0xff);
	//    for (int i = 0; i<nBytes; i++){
	//        std::cout << " 0x" << std::setfill('0') << std::setw(2) << std::hex << (int)payload[i];
	//    }
	//    std::cout<<std::endl;
	std::string s = "";
	s += 0xb5; s += 0x62;
	s += (unsigned char)((msgID & 0xff00) >> 8);
	s += (unsigned char)(msgID & 0xff);
	s += (unsigned char)(nBytes & 0xff);
	s += (unsigned char)((nBytes & 0xff00) >> 8);
	for (int i = 0; i < nBytes; i++) s += payload[i];
	unsigned char chkA, chkB;
	calcChkSum(s, &chkA, &chkB);
	s += chkA;
	s += chkB;
	//   cout<<endl<<endl;
	//   cout<<"write UBX string: ";
	//   for (int i=0; i<s.size(); i++) cout<<hex<<(int)s[i]<<" ";
	//   cout<<endl<<endl;
	//if (s.size() == WriteBuffer(s)) return true;
	//QByteArray block;
	//block.append(QString::fromStdString(s));
    if (!serialPort.isNull()) {
		QByteArray block(s.c_str(), s.size());
		if (serialPort->write(block)) {
			if (serialPort->waitForBytesWritten(timeout)) {
				if (showout) {
					std::stringstream tempStream;
					tempStream << "out: ";
					for (std::string::size_type i = 2; i < s.length(); i++) {
						tempStream << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)s[i] << " ";
					}
					tempStream << "\n";
					emit toConsole(QString::fromStdString(tempStream.str()));
				}
				return true;
			}
			else {
				emit toConsole("wait for bytes written timeout while trying to write to serialPort");
			}
		}
		else {
			emit toConsole("error writing to serialPort");
		}
	}
	else {
		emit toConsole("error: serialPort not instantiated");
	}
	return false;
}

bool QtSerialUblox::sendUBX(uint16_t msgID, unsigned char* payload, uint16_t nBytes) {
	std::stringstream payloadStream;
	std::string payloadString;
	for (int i = 0; i < nBytes; i++) {
		payloadStream << payload[i];
	}
	payloadString = payloadStream.str();
	return sendUBX(msgID, payloadString, nBytes);
}

bool QtSerialUblox::sendUBX(UbxMessage &msg) {
	return sendUBX(msg.msgID, msg.data, msg.data.size());
}

void QtSerialUblox::calcChkSum(const std::string& buf, unsigned char* chkA, unsigned char* chkB)
{
	// calc Fletcher checksum, ignore the message header (b5 62)
	*chkA = 0;
	*chkB = 0;
	for (std::string::size_type i = 2; i < buf.size(); i++)
	{
		*chkA += buf[i];
		*chkB += *chkA;
	}
}

void QtSerialUblox::UBXSetCfgRate(uint16_t measRate, uint16_t navRate)
{
	if (verbose > 3) {
		emit toConsole(QString("Ublox UBXsetCfgRate running in thread " + QString("0x%1\n")
			.arg((int)this->thread())));
	}
	unsigned char data[6];
	// initialise all contents from data as 0 first!
	for (int i = 0; i < 6; i++) {
		data[i] = 0;
	}
	if (measRate < 10 || navRate < 1 || navRate>127) {
		emit UBXCfgError("measRate <10 || navRate<1 || navRate>127 error");
	}
	data[0] = measRate & 0xff;
	data[1] = (measRate & 0xff00) >> 8;
	data[2] = navRate & 0xff;
	data[3] = (navRate & 0xff00) >> 8;
	data[4] = 0;
	data[5] = 0;

	enqueueMsg(UBX_CFG_RATE, toStdString(data, 6));
	
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_RATE;
	newMessage.data = toStdString(data, 6);
	outMsgBuffer.push(newMessage);
	if (!msgWaitingForAck) {
		sendQueuedMsg();
	}
*/
	// sendUBX(UBX_CFG_RATE, data, sizeof(data));
	/* Ack check has to be done differently, asynchronously
	if (waitAck(UBX_CFG_RATE, 10000))
	{
		emit toConsole("Set CFG successful");
	}
	else {
		emit UBXCfgError("Set CFG timeout");
	}*/
}

void QtSerialUblox::UBXSetCfgPrt(uint8_t port, uint8_t outProtocolMask) {
	if (verbose > 3) {
		emit toConsole(QString("Ublox UBXSetCfgPort running in thread " + QString("0x%1\n")
			.arg((int)this->thread())));
	}
	unsigned char data[20];
	// initialise all contents from data as 0 first!
	for (int i = 0; i < 20; i++) {
		data[i] = 0;
	}
	if (port > 6) {
		emit UBXCfgError("port > 5 is not possible");
	}
	if (port == 1) {
		// port 1 is UART port, payload for other ports may differ
		// setup payload. Bit masks are set up byte wise from lowest to highest byte
		data[0] = port; // set port (1 Byte)
		data[1] = 0; // reserved
		data[2] = 0;
		data[3] = 0; // txReady options (not used)
		// mode option:
		data[4] = 0b11000000; // charLen option (first 2 bits): 11 means 8 bit character length.
							  // (10 means 7 bit character length only with parity enabled)
		data[5] = 0b00001000; // first 2 bits unimportant. 00 -> 1 stop bit. 100 -> no parity. last bit unimportant.
		data[6] = 0;
		data[7] = 0; //part of mode option but no meaning

		// baudrate: (check if it works)
		data[8] = (uint8_t)(((uint16_t)_baudRate) & 0x00ff);
		data[9] = (uint8_t)((((uint16_t)_baudRate) & 0xff00) >> 8);
		data[10] = 0;
		data[11] = 0; //not needed because baudRate will never be over 65536 (2^16)

		// inProtoMask enables/disables possible protocols for sending messages to the gps module:
		data[12] = 0b00100111; // () () (RTCM3) () () (RTCM) (NMEA) (UBX)
		data[13] = 0; //has no meaning but part of inProtoMask

		// outProtoMask enables/disables protocols for receiving messages from the gps module:
		//data[14] = 0b00100011; // () () (RTCM3) () () () (NMEA) (UBX) FOR EXAMPLE
		data[14] = outProtocolMask;

		data[15] = 0; //has no meaning but part of outProtoMask

		data[16] = 0;
		data[17] = 0; // extendedTxTimeout not needed
		data[18] = 0;
		data[19] = 0; // reserved
	}
	// sendUBX(UBX_CFG_PRT, data, 20);
	enqueueMsg(UBX_CFG_PRT, toStdString(data, 20));
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_PRT;
	newMessage.data = toStdString(data, 20);
	outMsgBuffer.push(newMessage);
	if (!msgWaitingForAck) {
		sendQueuedMsg();
	}
*/
}

void QtSerialUblox::UBXSetCfgMsgRate(uint16_t msgID, uint8_t port, uint8_t rate)
{ // set message rate on port. (rate 1 means every intervall the messages is sent)
	// if port = -1 set all ports
	if (verbose > 3) {
		emit toConsole(QString("Ublox UBXsetCfgMsg running in thread " + QString("0x%1\n")
			.arg((int)this->thread())));
	}
	unsigned char data[8];
	// initialise all contents from data as 0 first!
	for (int i = 0; i < 8; i++) {
		data[i] = 0;
	}
	if (port > 6) {
		emit UBXCfgError("port > 5 is not possible");
	}
	data[0] = (uint8_t)((msgID & 0xff00) >> 8);
	data[1] = msgID & 0xff;
	//   cout<<"data[0]="<<(int)data[0]<<" data[1]="<<(int)data[1]<<endl;
	if (port != 6) {
		data[2 + port] = rate;
	}
	else {
		for (int i = 2; i < 6; i++) {
			data[i] = rate;
		}
	}
	//sendUBX(UBX_CFG_MSG, data, 8);#

	enqueueMsg(UBX_CFG_MSG, toStdString(data, 8));
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_MSG;
	newMessage.data = toStdString(data, 8);
	outMsgBuffer.push(newMessage);
	if (!msgWaitingForAck) {
		sendQueuedMsg();
	}
*/
	/* Ack check has to be done differently, asynchronously
	if (waitAck(UBX_CFG_MSG, 12000)) {
		emit toConsole("Set CFG successful");
	}
	else {
		emit UBXCfgError("Set CFG timeout");
	}
	*/
}

void QtSerialUblox::UBXReset(uint32_t resetFlags)
{
	uint16_t navBbrMask = (resetFlags & 0xffff0000) >> 16;
	uint8_t resetMode = resetFlags & 0xff;
	unsigned char data[4];
	data[0]=navBbrMask & 0xff;
	data [1]=(navBbrMask & 0xff00)>>8;
	data[2]=resetMode;
	data[3]=0;
	
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_RST;
	newMessage.data = toStdString(data, 4);
	sendUBX(newMessage);
}

void QtSerialUblox::UBXSetMinMaxSVs(uint8_t minSVs, uint8_t maxSVs)
{
	uint16_t mask1 = 0x04;
	unsigned char data[40];
	data[2]=0x04; // MinMax flag in mask 1
	data[3]=0x00; // all other flags are zero
	data[4]=0; data[5]=0; data[6]=0; data[7]=0;
	data[10]=minSVs;
	data[11]=maxSVs;
	
	enqueueMsg(UBX_CFG_NAVX5, toStdString(data, 40));
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_NAVX5;
	newMessage.data = toStdString(data, 40);
	sendUBX(newMessage);
*/
}

void QtSerialUblox::UBXSetMinCNO(uint8_t minCNO)
{
	unsigned char data[40];
	data[2]=0x08; // minCNO flag in mask 1
	data[3]=0x00; // all other flags are zero
	data[4]=0; data[5]=0; data[6]=0; data[7]=0;
	data[12]=minCNO;
	
	enqueueMsg(UBX_CFG_NAVX5, toStdString(data, 40));
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_NAVX5;
	newMessage.data = toStdString(data, 40);
	sendUBX(newMessage);
*/
}

void QtSerialUblox::UBXSetAopCfg(bool enable, uint16_t maxOrbErr)
{
	unsigned char data[40];
	data[2]=0x00; // aop flag in mask 2
	data[3]=0x40; // all other flags are zero
	data[4]=0; data[5]=0; data[6]=0; data[7]=0;

	data[27]=(uint8_t)enable;	
	data[30]=maxOrbErr & 0xff;
	data[31]=(maxOrbErr>>8) & 0xff;

	enqueueMsg(UBX_CFG_NAVX5, toStdString(data, 40));
/*
	UbxMessage newMessage;
	newMessage.msgID = UBX_CFG_NAVX5;
	newMessage.data = toStdString(data, 40);
	sendUBX(newMessage);
*/
}

void QtSerialUblox::UBXSaveCfg(uint8_t devMask)
{
	unsigned char data[13];
	// select the following sections to save:
	// ioPort, msgCfg, navCfg, rxmCfg, antConf
	uint32_t sectionMask=0x01 | 0x02 | 0x08 | 0x10 | 0x400;
	
	data[0]=data[1]=data[2]=data[3]=0x00; // clear mask is all zero
	data[8]=data[9]=data[10]=data[11]=0x00; // load mask is all zero
	data[4]=sectionMask & 0xff;
	data[5]=(sectionMask>>8) & 0xff;
	data[6]=(sectionMask>>16) & 0xff;
	data[7]=(sectionMask>>24) & 0xff;
	data[12]=devMask;

	enqueueMsg(UBX_CFG_CFG, toStdString(data, 13));
}

void QtSerialUblox::onRequestGpsProperties(){

}

void QtSerialUblox::delay(int millisecondsWait)
{
	QEventLoop loop;
	QTimer t;
	t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
	t.start(millisecondsWait);
	loop.exec();
}

void QtSerialUblox::handleError(QSerialPort::SerialPortError serialPortError)
{
	if (serialPortError == QSerialPort::ReadError) {
		emit toConsole(QObject::tr("An I/O error occurred while reading "
			"the data from port %1, error: %2\n")
			.arg(serialPort->portName())
			.arg(serialPort->errorString()));
	}
}
void QtSerialUblox::pollMsgRate(uint16_t msgID) {
	UbxMessage msg;
	unsigned char temp[2];
	temp[0] = (uint8_t)((msgID & 0xff00) >> 8);
	temp[1] = (uint8_t)(msgID & 0xff);
	enqueueMsg(UBX_CFG_MSG, toStdString(temp, 2));
/*	
	msg.msgID = UBX_CFG_MSG;
	msg.data = toStdString(temp, 2);
	outMsgBuffer.push(msg);
	if (!msgWaitingForAck) {
		sendQueuedMsg();
	}
*/
}

void QtSerialUblox::pollMsg(uint16_t msgID) {
	UbxMessage msg;
	unsigned char temp[1];
	switch (msgID) {
	case UBX_CFG_PRT: // CFG-PRT
		// in this special case "rate" is the port ID
		temp[0] = 1;
		msg.msgID = msgID;
		msg.data = toStdString(temp, 1);
		outMsgBuffer.push(msg);
		if (!msgWaitingForAck) {
			sendQueuedMsg();
		}
		break;
	case UBX_MON_VER:
		// the VER message apparently does not confirm reception with an ACK
		msg.msgID = msgID;
		msg.data = "";
		sendUBX(msg);
		break;
	
	default:
		// for most messages the poll msg is just the message without payload
		msg.msgID = msgID;
		msg.data = "";
		enqueueMsg(msgID, "");
/*
		outMsgBuffer.push(msg);
		if (!msgWaitingForAck) {
			sendQueuedMsg();
		}
*/
//		sendUBX(msg);
		break;
	}
}

float QtSerialUblox::getProtVersion() { 
		//QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
		/*QLocale english(QLocale(QLocale::English, QLocale::UnitedStates));
		return english.toFloat(fProtVersionString); */
		//return 0.;
		double verValue = 0.;
		try {
			verValue = std::stod(fProtVersionString);
		} catch (std::exception& e)
    {
//        emit toConsole("Exception catched : " + QString(e.what()));
    }
		return verValue;
}

void QtSerialUblox::enqueueMsg(uint16_t msgID, const std::string& payload)
{ 
		//sendUBX(msgID, payload, nrBytes);
		UbxMessage newMessage;
		newMessage.msgID = msgID;
		newMessage.data = payload;
//		enqueueMsg(newMessage);
		outMsgBuffer.push(newMessage);
		if (!msgWaitingForAck) {
			sendQueuedMsg();
		}
}

/*
void QtSerialUblox::enqueueMsg(const UbxMessage& msg)
{
		outMsgBuffer.push(msg);
		if (!msgWaitingForAck) {
			sendQueuedMsg();
		}
}
*/
