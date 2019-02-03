#include <cmath>
#include "gpssatsform.h"
#include "ui_gpssatsform.h"

const QVector<QString> FIX_TYPE_STRINGS = { "No Fix", "Dead Reck." , "2D-Fix", "3D-Fix", "GPS+Dead Reck.", "Time Only"  };
const QString GNSS_ID_STRING[] = { " GPS","SBAS"," GAL","BEID","IMES","QZSS","GLNS"," N/A" };

// helper function to format human readable numbers with common suffixes (k(ilo), M(ega), m(illi) etc.)
QString printReadableFloat(double value, int prec=2, int lowOrderInhibit=-9, int highOrderInhibit=9) {
    QString str="";
    QString suffix="";
    double order=std::log10(std::fabs(value));
    if (order>=lowOrderInhibit && order<=highOrderInhibit) {
    if (order>9) { value*=1e-9; suffix="G"; }
    else if (order>6) { value*=1e-6; suffix="M"; }
    else if (order>3) { value*=1e-3; suffix="k"; }
    else if (order>0) { suffix=""; }
    //else if (order>-2) { value*=100.; suffix="c"; }
    else if (order>-3) { value*=1000.; suffix="m"; }
    else if (order>-6) { value*=1e6; suffix="u"; }
    else if (order>-9) { value*=1e9; suffix="n"; }
    }
    char fmtChar='f';
    double newOrder = std::log10(std::fabs(value));
    if (fabs(newOrder)>3.) { fmtChar='g'; }
    else { prec=prec-(int)newOrder - 1;  }
    if (prec<0) prec=0;
    return QString::number(value,fmtChar,prec)+suffix;
}


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

    int nrGoodSats = 0;
    for (auto it=satlist.begin(); it!=satlist.end(); it++)
        if (it->fCnr>0) nrGoodSats++;

    ui->nrSatsLabel->setText(QString::number(nrGoodSats));

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
        QTableWidgetItem *newItem6 = new QTableWidgetItem(printReadableFloat(newlist[i].fPrRes,2,0));
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
        /*
        QTableWidgetItem *newItem12 = new QTableWidgetItem();
        newItem12->setCheckState(Qt::CheckState::Unchecked);
        if (newlist[i].fSmoothed) newItem12->setCheckState(Qt::CheckState::Checked);
        newItem12->setFlags(newItem12->flags() & (~Qt::ItemIsUserCheckable)); // disables checkbox edit from user
        newItem12->setFlags(newItem12->flags() & (~Qt::ItemIsEditable));
        newItem12->setSizeHint(QSize(20,24));
        ui->satsTableWidget->setItem(i, 11, newItem12);
        */
    }
    //ui->satsTableWidget->resizeColumnsToContents();
    //ui->satsTableWidget->resizeRowsToContents();
}

void GpsSatsForm::onTimeAccReceived(quint32 acc)
{
    double tAcc=acc*1e-9;
    ui->timePrecisionLabel->setText(printReadableFloat(tAcc)+"s");
//    ui->timePrecisionLabel->setText(QString::number(acc)+" ns");
}

void GpsSatsForm::onIntCounterReceived(quint32 cnt)
{
    ui->intCounterLabel->setText(QString::number(cnt));
}

void GpsSatsForm::onGpsMonHWReceived(quint16 noise, quint16 agc, quint8 antStatus, quint8 antPower, quint8 jamInd, quint8 flags)
{
    ui->lnaNoiseLabel->setText(QString::number(-noise)+" dBHz");
    ui->lnaAgcLabel->setText(QString::number(agc));
    QString str;
    switch (antStatus) {
        case 0: str="init";
                ui->antStatusLabel->setStyleSheet("QLabel { background-color : yellow }");
                break;
        case 2: str="OK";
            ui->antStatusLabel->setStyleSheet("QLabel { background-color : Window }");
            break;
        case 3: str="short";
                ui->antStatusLabel->setStyleSheet("QLabel { background-color : red }");
                break;
        case 4: str="open";
                ui->antStatusLabel->setStyleSheet("QLabel { background-color : red }");
                break;
        case 1:
        default:
                str="unknown";
                ui->antStatusLabel->setStyleSheet("QLabel { background-color : yellow }");
    }
    ui->antStatusLabel->setText(str);
    switch (antPower) {
        case 0: str="off";
                break;
        case 1: str="on";
                break;
        case 2:
        default:
                str="unknown";
    }
    ui->antPowerLabel->setText(str);
    ui->jammingProgressBar->setValue(jamInd/2.55);
}

void GpsSatsForm::onGpsVersionReceived(const QString &swString, const QString &hwString, const QString& protString)
{
    ui->ubxHwVersionLabel->setText(hwString);
    ui->ubxSwVersionLabel->setText(swString);
    ui->UBXprotLabel->setText(protString);
}

void GpsSatsForm::onGpsFixReceived(quint8 val)
{
    QString fixType = "N/A";
    if (val<FIX_TYPE_STRINGS.size()) fixType=FIX_TYPE_STRINGS[val];
    ui->fixTypeLabel->setText(fixType);
}

void GpsSatsForm::onGeodeticPosReceived(GeodeticPos pos){

    QString str;
    str=printReadableFloat(pos.hAcc/1000.,2,0)+"m/"+printReadableFloat(pos.vAcc/1000.,2,0)+"m";
/*    str=QString::number((float)pos.hAcc/1000.,'f',3)+"m";
    str+="/"+QString::number((float)pos.vAcc/1000.,'f',3)+"m";
*/    ui->xyzResLabel->setText(str);
}

void GpsSatsForm::onUiEnabledStateChange(bool connected)
{
    //
}
