#ifndef GPSSATSFORM_H
#define GPSSATSFORM_H

#include <QWidget>
#include <gnsssatellite.h>


namespace Ui {
class GpsSatsForm;
}

class GpsSatsForm : public QWidget
{
    Q_OBJECT

public:
    explicit GpsSatsForm(QWidget *parent = 0);
    ~GpsSatsForm();

public slots:
    void onSatsReceived(const QVector<GnssSatellite>& satlist);
    void onTimeAccReceived(quint32 acc);
    void onIntCounterReceived(quint32 cnt);
    void onGpsMonHWReceived(quint16 noise, quint16 agc, quint8 antStatus, quint8 antPower, quint8 jamInd, quint8 flags);

private:
    Ui::GpsSatsForm *ui;
};

#endif // GPSSATSFORM_H
