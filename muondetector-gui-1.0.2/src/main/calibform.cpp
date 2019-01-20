#include <QThread>
#include "calibform.h"
#include "ui_calibform.h"
#include <calib_struct.h>
#include <qwt_symbol.h>

#define calVoltMin 0.5
#define calVoltMax 2.5



inline static double sqr(double x) {
        return x*x;
}

/*
 linear regression algorithm
 taken from:
   http://stackoverflow.com/questions/5083465/fast-efficient-least-squares-fit-algorithm-in-c
 parameters:
  n = number of data points
  xarray,yarray  = arrays of data
  *offs = output intercept
  *slope  = output slope
 */
bool calcLinearCoefficients( const QVector<QPointF>& points,
        /*int n, double *xarray, double *yarray,
                */double *offs, double* slope)
{
   int n=points.size();
   if (n<3) return false;

   double   sumx = 0.0;                        /* sum of x                      */
   double   sumx2 = 0.0;                       /* sum of x**2                   */
   double   sumxy = 0.0;                       /* sum of x * y                  */
   double   sumy = 0.0;                        /* sum of y                      */
   double   sumy2 = 0.0;                       /* sum of y**2                   */

//   int ix=0;
//   double offsx=xarray[ix];
//   double offsy=yarray[ix];
   double offsx=0;
   double offsy=0;
//    long long int offsy=0;

   for (int i=0; i<n; i++) {
          sumx  += points[i].x()-offsx;
          sumx2 += sqr(points[i].x()-offsx);
          sumxy += (points[i].x()-offsx) * (points[i].y()-offsy);
          sumy  += (points[i].y()-offsy);
          sumy2 += sqr(points[i].y()-offsy);
   }


   double denom = (n * sumx2 - sqr(sumx));
   if (denom == 0) {
       // singular matrix. can't solve the problem.
       *slope = 0;
       *offs = 0;
//       if (r) *r = 0;
       return false;
   }

   double m = (n * sumxy  -  sumx * sumy) / denom;
   double b = (sumy * sumx2  -  sumx * sumxy) / denom;

   *slope=m;
   *offs=b+offsy;
   return true;
//    *offs=b;
//   printf("offsI=%lld  offsF=%f\n", offsy, b);

}


CalibForm::CalibForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalibForm)
{
    ui->setupUi(this);
    ui->calibItemTableWidget->resizeColumnsToContents();

    ui->biasCalibPlot->addCurve("curve1", Qt::blue);
    ui->biasCalibPlot->curve("curve1").setStyle(QwtPlotCurve::NoCurve);
    QwtSymbol *sym=new QwtSymbol(QwtSymbol::Rect, QBrush(Qt::blue, Qt::SolidPattern),QPen(Qt::black),QSize(5,5));
    ui->biasCalibPlot->curve("curve1").setSymbol(sym);

    ui->biasCalibPlot->addCurve("curve2", Qt::red);
    ui->biasCalibPlot->curve("curve2").setStyle(QwtPlotCurve::NoCurve);
    QwtSymbol *sym2=new QwtSymbol(QwtSymbol::Rect, QBrush(Qt::red, Qt::SolidPattern),QPen(Qt::black),QSize(5,5));
    ui->biasCalibPlot->curve("curve2").setSymbol(sym2);

    ui->biasCalibPlot->addCurve("Fit1", Qt::blue);
    ui->biasCalibPlot->curve("Fit1").setStyle(QwtPlotCurve::Lines);
    ui->biasCalibPlot->addCurve("Fit2", Qt::red);
    ui->biasCalibPlot->curve("Fit2").setStyle(QwtPlotCurve::Lines);

    ui->biasCalibPlot->replot();
    ui->transferBiasCoeffsPushButton->setEnabled(false);

}

CalibForm::~CalibForm()
{
    delete ui;
}

void CalibForm::onCalibReceived(bool valid, bool eepromValid, quint64 id, const QVector<CalibStruct> & calibList)
{
    QString str = "invalid";
    if (eepromValid) str="valid";
    ui->eepromValidLabel->setText("EEPROM data: "+str);
    str = "invalid";
    if (valid) str="valid";
    ui->calibValidLabel->setText("Calib data: "+str);
    ui->idLineEdit->setText(QString::number(id,16));

    fCalibList.clear();
    for (int i=0; i<calibList.size(); i++)
    {
        fCalibList.push_back(calibList[i]);
    }
    updateCalibTable();
    emit updatedCalib();
}

void CalibForm::updateCalibTable()
{
    ui->calibItemTableWidget->setRowCount(fCalibList.size());
    for (int i=0; i<fCalibList.size(); i++)
    {
        QTableWidgetItem *newItem1 = new QTableWidgetItem(QString::fromStdString(fCalibList[i].name));
        newItem1->setSizeHint(QSize(90,20));
        ui->calibItemTableWidget->setItem(i, 0, newItem1);
        QString type = QString::fromStdString(fCalibList[i].type);
        QString numberstr = "";
        if (type=="FLOAT") {
            double val = QString::fromStdString(fCalibList[i].value).toDouble(NULL);
            numberstr = QString::number(val);
        } else {
            numberstr = QString::fromStdString(fCalibList[i].value);
        }

        QTableWidgetItem *newItem2 = new QTableWidgetItem(type);
        newItem2->setSizeHint(QSize(40,20));
        ui->calibItemTableWidget->setItem(i, 1, newItem2);
        QTableWidgetItem *newItem3 = new QTableWidgetItem(numberstr);
        newItem3->setSizeHint(QSize(60,20));
        ui->calibItemTableWidget->setItem(i, 2, newItem3);
        QTableWidgetItem *newItem4 = new QTableWidgetItem("0x"+QString("%1").arg(fCalibList[i].address, 2, 16, QChar('0')));
        newItem4->setSizeHint(QSize(20,20));
        ui->calibItemTableWidget->setItem(i, 3, newItem4);
    }
    //ui->calibItemTableWidget->resizeColumnsToContents();
    ui->calibItemTableWidget->resizeRowsToContents();
}


void CalibForm::onAdcSampleReceived(uint8_t channel, float value)
{
    double ubias = 0.;
    if (channel>=2) {
        QString result = getCalibParameter("VDIV");
        if (result!="") {
            double vdiv = result.toDouble(NULL);
            ubias = vdiv*value/100.;
//            ui->biasVoltageLineEdit->setText(QString::number(ubias));
        }
    }
    if (channel == 3) {
        ui->biasAdcLineEdit->setText(QString::number(value));
        ui->biasVoltageLineEdit->setText(QString::number(ubias));
        if (fCalibRunning) {
            if (fCurrBias>calVoltMax) { on_doBiasCalibPushButton_clicked(); return; }
            QPointF p(fCurrBias, ubias);
            fCurrBias+=0.05;
            emit setBiasDacVoltage(fCurrBias);
            QThread::msleep(100);
            fPoints2.push_back(p);
            ui->biasCalibPlot->curve("curve2").setSamples(fPoints2);
            ui->biasCalibPlot->replot();
        }
    } else if (channel == 2) {
        if (fCalibRunning) {
            QPointF p(fCurrBias, ubias);
            fPoints1.push_back(p);
            ui->biasCalibPlot->curve("curve1").setSamples(fPoints1);
            ui->biasCalibPlot->replot();
            doFit();
        }
    }
}

void CalibForm::on_readCalibPushButton_clicked()
{
    // calib reread triggered
    emit calibRequest();
}


void CalibForm::on_writeEepromPushButton_clicked()
{
    // write eeprom clicked
    emit writeCalibToEeprom();
}


void CalibForm::on_doBiasCalibPushButton_clicked()
{
    // let's go
    if (fCalibRunning) {
        fCalibRunning=false;
        ui->doBiasCalibPushButton->setText("Start");
        return;
    }
    fCalibRunning=true;
    ui->doBiasCalibPushButton->setText("Stop");
    fPoints1.clear();
    fPoints2.clear();
    fCurrBias=calVoltMin;
    emit setBiasDacVoltage(fCurrBias);
}

void CalibForm::doFit()
{
//    double slope1=0.,offs1=0.;
//    double slope2=0.,offs2=0.;
    QVector<QPointF> goodPoints1,goodPoints2;

    ui->fitTextEdit->clear();

    std::copy_if(fPoints1.begin(), fPoints1.end(), std::back_inserter(goodPoints1), [](const QPointF& p)
            { return p.y()<27. && p.y()>6.; } );

    bool ok=calcLinearCoefficients(goodPoints1,&fOffs1,&fSlope1);
    if (!ok) return;
    QVector<QPointF> vec;
    QPointF p1,p2;
    p1.rx()=0.;
    p1.ry()=fOffs1;
    p2.rx()=2.1;
    p2.ry()=fOffs1+2.1*fSlope1;
    vec.push_back(p1);
    vec.push_back(p2);
    ui->biasCalibPlot->curve("Fit1").setSamples(vec);
    ui->biasCalibPlot->replot();
    ui->fitTextEdit->append("fit bias1: c0="+QString::number(fOffs1)+", c1="+QString::number(fSlope1));

    std::copy_if(fPoints2.begin(), fPoints2.end(), std::back_inserter(goodPoints2), [](const QPointF& p)
            { return p.y()<27. && p.y()>6.; } );
    ok=calcLinearCoefficients(goodPoints2,&fOffs2,&fSlope2);
    if (!ok) return;
    vec.clear();
    p1.rx()=0.;
    p1.ry()=fOffs2;
    p2.rx()=2.1;
    p2.ry()=fOffs2+2.1*fSlope2;
    vec.push_back(p1);
    vec.push_back(p2);
    ui->biasCalibPlot->curve("Fit2").setSamples(vec);
    ui->fitTextEdit->append("fit bias2: c0="+QString::number(fOffs2)+", c1="+QString::number(fSlope2));

    ui->biasCalibPlot->replot();
    ui->transferBiasCoeffsPushButton->setEnabled(true);

}

void CalibForm::on_transferBiasCoeffsPushButton_clicked()
{
    // transfer to calib
    if (ui->transferBiasCoeffsPushButton->isEnabled()) {
        std::string str=QString::number(fOffs1).toStdString();
        if (str.size()) setCalibParameter("COEFF0",str);
        str=QString::number(fSlope1).toStdString();
        if (str.size()) setCalibParameter("COEFF1",str);
        uint8_t flags=getCalibParameter("CALIB_FLAGS").toUInt();
        flags |= CalibStruct::CALIBFLAGS_VOLTAGE_COEFFS;
        setCalibParameter("CALIB_FLAGS",QString::number(flags).toStdString());
        updateCalibTable();
        emit updatedCalib();
    }
}

void CalibForm::setCalibParameter(const std::string &name, const std::string &value)
{
    if (!fCalibList.empty()) {
        auto result = std::find_if(fCalibList.begin(), fCalibList.end(), [&name](const CalibStruct& s){ return s.name==name; } );
        if (result != fCalibList.end()) {
            result->value=value;
        }
    }
}

QString CalibForm::getCalibParameter(const QString &name)
{
    if (!fCalibList.empty()) {
        auto result = std::find_if(fCalibList.begin(), fCalibList.end(), [&name](const CalibStruct& s){ return s.name==name.toStdString(); } );
        if (result != fCalibList.end()) {
            return QString::fromStdString(result->value);
        }
    }
    return "";
}

