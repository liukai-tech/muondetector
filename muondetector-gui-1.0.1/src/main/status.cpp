#include <status.h>
#include <ui_status.h>
#include <plotcustom.h>

static const int rateSecondsBuffered = 60*120; // 120 min
Status::Status(QWidget *parent) :
    QWidget(parent),
    statusUi(new Ui::Status)
{
    statusUi->setupUi(this);
}

void Status::onGpioRatesReceived(quint8 whichrate, QVector<QPointF> rates){
    if (whichrate==0){
        if (xorSamples.size()>0){
            for (int k = rates.size()-1; k>=0; k--){
                bool foundK = false; // if foundK it has found an index k where the x values of the input points
                // are smaller or equal to the x values of the already existing points -> overlap
                for (int i = xorSamples.size()-1; i>=xorSamples.size()-1-rates.size(); i--){
                    if (rates.at(k).x()<=xorSamples.at(i).x()){
                        foundK = true;
                    }
                }
                if (foundK && k<rates.size()){
                    // if there is an overlap, remove all points from input rate points that are already existing
                    rates.remove(0,k+1);
                    break;
                }
            }
        }
        for (auto rate : rates){
            xorSamples.append(rate);
        }
        while (xorSamples.first().x()<rates.last().x()-rateSecondsBuffered){
            xorSamples.pop_front();
        }
        statusUi->ratePlot->plotXorSamples(xorSamples);
    }
    if (whichrate==1){
        if (andSamples.size()>0){
            for (int k = rates.size()-1; k>=0; k--){
                bool foundK = false; // if foundK it has found an index k where the x values of the input points
                // are smaller or equal to the x values of the already existing points -> overlap
                for (int i = andSamples.size()-1; i>=andSamples.size()-1-rates.size(); i--){
                    if (rates.at(k).x()<=andSamples.at(i).x()){
                        foundK = true;
                    }
                }
                if (foundK && k<rates.size()){
                    // if there is an overlap, remove all points from input rate points that are already existing
                    rates.remove(0,k+1);
                    break;
                }
            }
        }
        for (auto rate : rates){
            andSamples.append(rate);
        }
        while (andSamples.first().x()<rates.last().x()-rateSecondsBuffered){
            andSamples.pop_front();
        }
        statusUi->ratePlot->plotAndSamples(andSamples);
    }
}

void Status::onUiEnabledStateChange(bool connected){
    if (connected){
        statusUi->ratePlot->setStatusEnabled(true);
        this->setEnabled(true);
    }else{
        andSamples.clear();
        xorSamples.clear();
        statusUi->ratePlot->setStatusEnabled(false);
        this->setDisabled(true);
    }
}

Status::~Status()
{
    delete statusUi;
}
