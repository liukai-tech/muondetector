#include <plotcustom.h>
#include <qwt_legend.h>
#include <qwt.h>

PlotCustom::~PlotCustom(){
    if (xorData!=nullptr) { delete xorData; xorData=nullptr;}
    if (andData!=nullptr) { delete andData; andData=nullptr;}
    if (xorCurve!=nullptr) { delete xorCurve; xorCurve=nullptr;}
    if (andCurve!=nullptr) { delete andCurve; andCurve=nullptr;}
}

void PlotCustom::initialize(){
    // Show a title
       setTitle( "Rate Statistics" );
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       grid = new QwtPlotGrid();
       grid->setPen(Qt::black, 0.1, Qt::SolidLine);
       grid->attach(this);
       setStyleSheet("background-color: white; border: 0px;");

       xorCurve = new QwtPlotCurve();
       xorCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       //xorCurve->setStyle(QwtPlotCurve::Steps);
       QColor xorCurveColor = Qt::darkGreen;
       xorCurve->setPen(xorCurveColor,1);
       xorCurveColor.setAlphaF(0.3);
       xorCurve->setBrush(xorCurveColor);
       xorCurve->attach(this);

       andCurve = new QwtPlotCurve();
       andCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       //xorCurve->setStyle(QwtPlotCurve::Steps);
       QColor andCurveColor = Qt::darkBlue;
       andCurve->setPen(andCurveColor,1);
       andCurveColor.setAlphaF(0.3);
       andCurve->setBrush(andCurveColor);
       andCurve->attach(this);

       xorData = new QwtPointSeriesData();
       andData = new QwtPointSeriesData();
       replot();
       show();
}

void PlotCustom::plotXorSamples(QVector<QPointF>& xorSamples){
    if (xorData==nullptr || xorCurve == nullptr){
        return;
    }
    xorData->setSamples(xorSamples);
    xorCurve->setData(xorData);
    replot();
    show();
}

void PlotCustom::plotAndSamples(QVector<QPointF>& andSamples){
    if (andData==nullptr || andCurve==nullptr){
        return;
    }
    andData->setSamples(andSamples);
    andCurve->setData(andData);
    replot();
    show();
}
