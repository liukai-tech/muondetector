#ifndef CALIBFORM_H
#define CALIBFORM_H

#include <QWidget>
#include <QVector>
#include <string>

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
    void setBiasDacVoltage(float val);
    void updatedCalib();

public slots:
    void onCalibReceived(bool valid, bool eepromValid, quint64 id, const QVector<CalibStruct>& calibList);
    void onAdcSampleReceived(uint8_t channel, float value);
    QString getCalibParameter(const QString& name);

private slots:
    void on_readCalibPushButton_clicked();
    void on_writeEepromPushButton_clicked();
    void on_doBiasCalibPushButton_clicked();
    void doFit();
    void on_transferBiasCoeffsPushButton_clicked();

    void setCalibParameter(const std::string& name, const std::string& value);

    void updateCalibTable();

private:
    Ui::CalibForm *ui;
    QVector<CalibStruct> fCalibList;
    bool fCalibRunning=false;
    float fCurrBias=0.;
    QVector<QPointF> fPoints1, fPoints2;
    double fSlope1=0.,fOffs1=0.;
    double fSlope2=0.,fOffs2=0.;


};

#endif // CALIBFORM_H
