#ifndef STATUS_H
#define STATUS_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QPointF>
#include <QButtonGroup>

namespace Ui {
class Status;
}

class Status : public QWidget
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = nullptr);
    ~Status();

signals:
	void inputSwitchChanged(int id);
public slots:
    void onGpioRatesReceived(quint8 whichrate, QVector<QPointF> rates);
    void onAdcSampleReceived(uint8_t channel, float value);
    void onUiEnabledStateChange(bool connected);
    void updatePulseHeightHistogram();
   	void on_histoLogYCheckBox_clicked();
   	void onInputSwitchReceived(uint8_t id);
   	void onDacReadbackReceived(uint8_t channel, float value);

private:
    Ui::Status *statusUi;
    QVector<QPointF> xorSamples;
    QVector<QPointF> andSamples;
    QMap<int, int> fPulseHeightHistogramMap;
    QButtonGroup* fInputSwitchButtonGroup;
};

#endif // STATUS_H
