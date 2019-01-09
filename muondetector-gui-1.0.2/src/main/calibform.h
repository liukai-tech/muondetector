#ifndef CALIBFORM_H
#define CALIBFORM_H

#include <QWidget>
#include <QVector>

struct CalibStruct;

namespace Ui {
class CalibForm;
}

class CalibForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalibForm(QWidget *parent = 0);
    ~CalibForm();
signals:
    void calibRequest();
    void writeCalibToEeprom();

public slots:
    void onCalibReceived(bool valid, bool eepromValid, quint64 id, const QVector<CalibStruct>& calibList);
    void onAdcSampleReceived(uint8_t channel, float value);

private slots:
    void on_readCalibPushButton_clicked();

    void on_writeEepromPushButton_clicked();

private:
    Ui::CalibForm *ui;
    QVector<CalibStruct> fCalibList;
};

#endif // CALIBFORM_H
