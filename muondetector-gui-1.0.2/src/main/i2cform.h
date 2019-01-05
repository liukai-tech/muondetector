#ifndef I2CFORM_H
#define I2CFORM_H

#include <QWidget>
#include <QVector>
#include <QString>

struct I2cDeviceEntry {
	uint8_t address;	
	QString name;
	bool online;
};

namespace Ui {
class I2cForm;
}

class I2cForm : public QWidget
{
    Q_OBJECT

public:
    explicit I2cForm(QWidget *parent = nullptr);
    ~I2cForm();

signals:

public slots:
	void onI2cStatsReceived(quint32 bytesRead, quint32 bytesWritten, const QVector<I2cDeviceEntry>& deviceList);

private:
    Ui::I2cForm *ui;
};

#endif // I2CFORM_H
