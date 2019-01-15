#include "gpssatsform.h"
#include "ui_gpssatsform.h"

const QString GNSS_ID_STRING[] = { " GPS","SBAS"," GAL","BEID","IMES","QZSS","GLNS"," N/A" };

GpsSatsForm::GpsSatsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GpsSatsForm)
{
    ui->setupUi(this);
    ui->satsTableWidget->resizeColumnsToContents();
    //ui->satsTableWidget->resizeRowsToContents();
}

GpsSatsForm::~GpsSatsForm()
{
    delete ui;
}

void GpsSatsForm::onSatsReceived(const QVector<GnssSatellite> &satlist)
{
    QVector<GnssSatellite> newlist;
    QString str;
    QColor color;

    for (int i=0; i<satlist.size(); i++)
    {
        if (ui->visibleSatsCheckBox->isChecked()) {
            if (satlist[i].fCnr>0) newlist.push_back(satlist[i]);
        } else newlist.push_back(satlist[i]);
    }

    int N=newlist.size();
    ui->satsTableWidget->setRowCount(N);
    for (int i=0; i<N; i++)
    {
        QTableWidgetItem *newItem1 = new QTableWidgetItem(QString::number(newlist[i].fSatId));
        newItem1->setSizeHint(QSize(25,24));
        ui->satsTableWidget->setItem(i, 0, newItem1);
//        QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::number(satlist[i].fGnssId));
        QTableWidgetItem *newItem2 = new QTableWidgetItem(GNSS_ID_STRING[newlist[i].fGnssId]);
        newItem2->setSizeHint(QSize(50,24));
        ui->satsTableWidget->setItem(i, 1, newItem2);
        QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(newlist[i].fCnr));
        newItem3->setSizeHint(QSize(70,24));
        ui->satsTableWidget->setItem(i, 2, newItem3);
        QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(newlist[i].fAzim));
        newItem4->setSizeHint(QSize(100,24));
        ui->satsTableWidget->setItem(i, 3, newItem4);
        QTableWidgetItem *newItem5 = new QTableWidgetItem(QString::number(newlist[i].fElev));
        newItem5->setSizeHint(QSize(100,24));
        ui->satsTableWidget->setItem(i, 4, newItem5);
        QTableWidgetItem *newItem6 = new QTableWidgetItem(QString::number(newlist[i].fPrRes));
        newItem6->setSizeHint(QSize(60,24));
        ui->satsTableWidget->setItem(i, 5, newItem6);
        QTableWidgetItem *newItem7 = new QTableWidgetItem(QString::number(newlist[i].fQuality));
        color=Qt::green;
        float transp=0.166*(newlist[i].fQuality-1);
        if (transp<0.) transp=0.;
        if (transp>1.) transp=1.;
        color.setAlphaF(transp);
        newItem7->setBackgroundColor(color);

        newItem7->setSizeHint(QSize(25,24));
        ui->satsTableWidget->setItem(i, 6, newItem7);
        if (newlist[i].fHealth==0) { str="N/A"; color=Qt::lightGray; }
        else if (newlist[i].fHealth==1) { str="good"; color=Qt::green; }
        else if (newlist[i].fHealth>=2) { str="bad"; color=Qt::red; }
        QTableWidgetItem *newItem8 = new QTableWidgetItem(str);
        //newItem8->setBackgroundColor(color);
        newItem8->setSizeHint(QSize(25,24));
        ui->satsTableWidget->setItem(i, 7, newItem8);
        QTableWidgetItem *newItem9 = new QTableWidgetItem(QString::number(newlist[i].fOrbitSource));
        newItem9->setSizeHint(QSize(50,24));
        ui->satsTableWidget->setItem(i, 8, newItem9);
        QTableWidgetItem *newItem10 = new QTableWidgetItem();
        newItem10->setCheckState(Qt::CheckState::Unchecked);
        if (newlist[i].fUsed) newItem10->setCheckState(Qt::CheckState::Checked);
        newItem10->setFlags(newItem10->flags() & (~Qt::ItemIsUserCheckable)); // disables checkbox edit from user
        newItem10->setFlags(newItem10->flags() & (~Qt::ItemIsEditable));
        newItem10->setSizeHint(QSize(20,24));
        ui->satsTableWidget->setItem(i, 9, newItem10);
        QTableWidgetItem *newItem11 = new QTableWidgetItem();
        newItem11->setCheckState(Qt::CheckState::Unchecked);
        if (newlist[i].fDiffCorr) newItem11->setCheckState(Qt::CheckState::Checked);
        newItem11->setFlags(newItem11->flags() & (~Qt::ItemIsUserCheckable)); // disables checkbox edit from user
        newItem11->setFlags(newItem11->flags() & (~Qt::ItemIsEditable));
        newItem11->setSizeHint(QSize(20,24));
        ui->satsTableWidget->setItem(i, 10, newItem11);
        QTableWidgetItem *newItem12 = new QTableWidgetItem();
        newItem12->setCheckState(Qt::CheckState::Unchecked);
        if (newlist[i].fSmoothed) newItem12->setCheckState(Qt::CheckState::Checked);
        newItem12->setFlags(newItem12->flags() & (~Qt::ItemIsUserCheckable)); // disables checkbox edit from user
        newItem12->setFlags(newItem12->flags() & (~Qt::ItemIsEditable));
        newItem12->setSizeHint(QSize(20,24));
        ui->satsTableWidget->setItem(i, 11, newItem12);
    }
    //ui->satsTableWidget->resizeColumnsToContents();
    //ui->satsTableWidget->resizeRowsToContents();
}
