#ifndef HISTOGRAMDATAFORM_H
#define HISTOGRAMDATAFORM_H

#include <QWidget>

class Histogram;

namespace Ui {
class histogramDataForm;
}

class histogramDataForm : public QWidget
{
    Q_OBJECT

public:
    explicit histogramDataForm(QWidget *parent = 0);
    ~histogramDataForm();
public slots:
    void onHistogramReceived(const Histogram& h);

private:
    Ui::histogramDataForm *ui;
};

#endif // HISTOGRAMDATAFORM_H
