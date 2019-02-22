#include "histogramdataform.h"
#include "ui_histogramdataform.h"
#include <histogram.h>

histogramDataForm::histogramDataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histogramDataForm)
{
    ui->setupUi(this);
}

histogramDataForm::~histogramDataForm()
{
    delete ui;
}

void histogramDataForm::onHistogramReceived(const Histogram &h)
{
//
    ui->histoWidget->setData(h);
    //ui->histoWidget->setTitle(QString::fromStdString(h.getName()));
}
