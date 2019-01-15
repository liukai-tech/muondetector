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
private:
    Ui::GpsSatsForm *ui;
};

#endif // GPSSATSFORM_H
