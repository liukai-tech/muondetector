#include <status.h>
#include <ui_status.h>
#include <plotcustom.h>
#include <QDebug>

static const int maxSamples = 100;
Status::Status(QWidget *parent) :
    QWidget(parent),
    statusUi(new Ui::Status)
{
    statusUi->setupUi(this);
}

void Status::onGpioRatesReceived(quint8 whichrate, QVector<QPointF> rates){
    if (whichrate==0){
        if (xorSamples.size()>0){
            for (QVector<QPointF>::iterator ratesIt = rates.begin();
                 ratesIt != rates.end(); ratesIt++){
                int j=0;
                for (int i = xorSamples.size()-1; i>=0; i--){
                    if (ratesIt->x()==xorSamples.at(i).x()){
                        rates.removeAt(ratesIt-rates.begin());
                    }
                    j++;
                    if (j>rates.size()){
                        break;
                    }
                }
            }
        }
        xorSamples.append(rates);
        while (xorSamples.size()>maxSamples){
            xorSamples.pop_front();
        }
        statusUi->ratePlot->plotXorSamples(xorSamples);
    }
    if (whichrate==1){
        if (andSamples.size()>0){
            for (QVector<QPointF>::iterator ratesIt = rates.begin();
                 ratesIt != rates.end(); ratesIt++){
                int j=0;
                for (int i = andSamples.size()-1; i>=0; i--){
                    if (ratesIt->x()==andSamples.at(i).x()){
                        rates.removeAt(ratesIt-rates.begin());
                    }
                    j++;
                    if (j>rates.size()){
                        break;
                    }
                }
            }
        }
        andSamples.append(rates);
        while (andSamples.size()>maxSamples){
            andSamples.pop_front();
        }
        statusUi->ratePlot->plotAndSamples(andSamples);
    }
    qDebug() << whichrate << rates;
}

Status::~Status()
{
    delete statusUi;
}
