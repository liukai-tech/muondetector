#ifndef STATUS_H
#define STATUS_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QPointF>

namespace Ui {
class Status;
}

class Status : public QWidget
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = nullptr);
    ~Status();

public slots:
    void onGpioRatesReceived(quint8 whichrate, QVector<QPointF> rates);
    void onAdcSamplesReceived(float adc1, float adc2);
    void onUiEnabledStateChange(bool connected);
    void updatePulseHeightHistogram();
private:
    Ui::Status *statusUi;
    QVector<QPointF> xorSamples;
    QVector<QPointF> andSamples;
    QMap<int, int> fPulseHeightHistogramMap;
};

#endif // STATUS_H
