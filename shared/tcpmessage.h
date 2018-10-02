#ifndef TCPMESSAGE_H
#define TCPMESSAGE_H
#include <QByteArray>
#include <QDataStream>

// how is a message coded in TcpMessage?
// in the data QByteArray:
// at pos 0: length of message (quint16) -> length of QByteArray - length of this number (sizeof(quint16))
// at pos 1: tcpMsgID (quint16), shows what kind of message it is

class TcpMessage
{
public:
	TcpMessage(quint16 tcpMsgID = 0);
	TcpMessage(QByteArray& rawdata);
    //~TcpMessage();
    QDataStream *dStream = nullptr;
	void setMsgID(quint16 tcpMsgID);
	void setData(QByteArray& data);
    QByteArray &getData();
    quint16 getMsgID();
    QByteArray data;
    quint16 msgID, byteCount;
};

#endif // TCPMESSAGE_H
