#include <status.h>
#include <ui_status.h>
#include <plotcustom.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

Status::Status(QWidget *parent) :
    QWidget(parent),
    statusUi(new Ui::Status)
{
    statusUi->setupUi(this);
    QwtPlotCurve *curve1 = new QwtPlotCurve();
    QwtPointSeriesData *data = new QwtPointSeriesData();
    QVector<QPointF>* samples = new QVector<QPointF>;
    samples->push_back(QPointF(1.0,1.0));
    samples->push_back(QPointF(2.0,2.0));
    samples->push_back(QPointF(3.0,3.0));
    samples->push_back(QPointF(4.0,5.0));
    data->setSamples(*samples);
    curve1->setData(data);
    curve1->attach(statusUi->widget);
    statusUi->widget->replot();
}

Status::~Status()
{
    delete statusUi;
}
