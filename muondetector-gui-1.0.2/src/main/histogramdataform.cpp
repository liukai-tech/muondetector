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
    int oldMapSize=fHistoMap.size();
    QString name=QString::fromStdString(h.getName());
    fHistoMap[name]=h;
    int newMapSize=fHistoMap.size();
//    if (newMapSize!=oldMapSize)
        updateHistoTable();
    ui->nrHistosLabel->setText(QString::number(fHistoMap.size()));
/*
    ui->histoWidget->setTitle(name);
    ui->histoWidget->setData(fHistoMap.first());
*/
}

void histogramDataForm::updateHistoTable()
{
    ui->tableWidget->setRowCount(fHistoMap.size());
    int i=0;
    for (auto it=fHistoMap.begin(); it!=fHistoMap.end(); it++)
    {
        QTableWidgetItem *newItem1 = new QTableWidgetItem(it.key());
        newItem1->setSizeHint(QSize(120,24));
        ui->tableWidget->setItem(i, 0, newItem1);
        QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::number(it.value().getEntries()));
        newItem2->setSizeHint(QSize(100,24));
        ui->tableWidget->setItem(i, 1, newItem2);
        i++;
    }
}

void histogramDataForm::on_tableWidget_cellClicked(int row, int column)
{
    QString name = ui->tableWidget->item(row,0)->text();
//    ui->nrHistosLabel->setText(name);
    auto it = fHistoMap.find(name);
    if (it!=fHistoMap.end()) {
        ui->histoWidget->setTitle(name);
        ui->histoWidget->setData(*it);
        ui->nrEntriesLabel->setText(QString::number(it->getEntries()));
        ui->underflowLabel->setText(QString::number(it->getUnderflow()));
        ui->overflowLabel->setText(QString::number(it->getOverflow()));
        ui->meanLabel->setText(QString::number(it->getMean()));
    }
}
