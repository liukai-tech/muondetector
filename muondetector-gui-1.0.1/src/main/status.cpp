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
    curve1->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
    //curve1->setStyle(QwtPlotCurve::Steps);
    QColor curve1Color = Qt::darkGreen;
    curve1->setPen(curve1Color,1);
    curve1Color.setAlphaF(0.3);
    curve1->setBrush(curve1Color);

    QwtPlotCurve *curve2 = new QwtPlotCurve();
    curve2->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
    //curve1->setStyle(QwtPlotCurve::Steps);
    QColor curve2Color = Qt::darkBlue;
    curve2->setPen(curve2Color,1);
    curve2Color.setAlphaF(0.3);
    curve2->setBrush(curve2Color);

    QwtPointSeriesData *andData = new QwtPointSeriesData();
    QVector<QPointF>* andSamples = new QVector<QPointF>;
    andSamples->push_back(QPointF(1,0.5));
    andSamples->push_back(QPointF(2,0.7));
    andSamples->push_back(QPointF(3,1.2));
    andSamples->push_back(QPointF(4,2.5));
    andData->setSamples(*andSamples);

    QwtPointSeriesData *xorData = new QwtPointSeriesData();
    QVector<QPointF>* xorSamples = new QVector<QPointF>;
    xorSamples->push_back(QPointF(1.0,1.0));
    xorSamples->push_back(QPointF(2.0,2.0));
    xorSamples->push_back(QPointF(3.0,3.0));
    xorSamples->push_back(QPointF(4.0,5.0));
    xorData->setSamples(*xorSamples);

    curve1->setData(xorData);
    curve1->attach(statusUi->ratePlot);
    curve2->setData(andData);
    curve2->attach(statusUi->ratePlot);
    statusUi->ratePlot->replot();
}

Status::~Status()
{
    delete statusUi;
}
