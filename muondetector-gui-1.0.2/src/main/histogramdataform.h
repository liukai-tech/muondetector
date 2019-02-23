#ifndef HISTOGRAMDATAFORM_H
#define HISTOGRAMDATAFORM_H

#include <QWidget>
#include <QMap>
#include <QString>

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

private slots:
    void updateHistoTable();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::histogramDataForm *ui;
    QMap<QString, Histogram> fHistoMap;
};

#endif // HISTOGRAMDATAFORM_H
