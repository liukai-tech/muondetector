#include <plotcustom.h>
#include <qwt_legend.h>
#include <qwt.h>

PlotCustom::~PlotCustom(){
    if (xorCurve!=nullptr) { delete xorCurve; xorCurve=nullptr;}
    if (andCurve!=nullptr) { delete andCurve; andCurve=nullptr;}
    if (grid!=nullptr) { delete grid; grid=nullptr;}
}

void PlotCustom::initialize(){
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       setStyleSheet("background-color: white; border: 0px;");
       setAutoReplot(false);
       enableAxis(QwtPlot::yLeft,false);
       enableAxis(QwtPlot::yRight,true);
       setAxisAutoScale(QwtPlot::xBottom,false);
       setAxisAutoScale(QwtPlot::yRight,true);

       grid = new QwtPlotGrid();
       const QPen blackPen(Qt::black);
       grid->setPen(blackPen);
       grid->attach(this);

       xorCurve = new QwtPlotCurve();
       xorCurve->setYAxis(QwtPlot::yRight);
       xorCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       //xorCurve->setStyle(QwtPlotCurve::Steps);
       QColor xorCurveColor = Qt::darkGreen;
       xorCurveColor.setAlphaF(0.3);
       const QPen greenPen(xorCurveColor);
       xorCurve->setPen(greenPen);
       xorCurve->setBrush(xorCurveColor);
       xorCurve->attach(this);

       andCurve = new QwtPlotCurve();
       andCurve->setYAxis(QwtPlot::yRight);
       andCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       //xorCurve->setStyle(QwtPlotCurve::Steps);
       QColor andCurveColor = Qt::darkBlue;
       andCurveColor.setAlphaF(0.3);
       const QPen bluePen(andCurveColor);
       andCurve->setPen(bluePen);
       andCurve->setBrush(andCurveColor);
       andCurve->attach(this);
       replot();
       show();
}

void PlotCustom::plotXorSamples(QVector<QPointF>& xorSamples){
    
	if (!isEnabled()) return;
	if (xorCurve == nullptr){
		return;
	}
    QVector<QPointF> samples;
    for (auto sample : xorSamples){
        samples.push_back(sample);
        samples.last().setX(sample.x() - xorSamples.at(xorSamples.size()-1).x());
    }
    double xMin = samples.first().x();
    double xMax = 0;
    double step = (xMax-xMin)/6;
    setAxisScale(QwtPlot::xBottom,xMin,xMax,step);
    QwtPointSeriesData *data = new QwtPointSeriesData(samples);
    xorCurve->setData(data);
    replot();
}

void PlotCustom::plotAndSamples(QVector<QPointF>& andSamples){
	if (!isEnabled()) return;
    if (andCurve==nullptr){
        return;
    }
    QVector<QPointF> samples;
    for (auto sample : andSamples){
        samples.push_back(sample);
        samples.last().setX(sample.x() - andSamples.at(andSamples.size()-1).x());
    }
    double xMin = samples.first().x();
    double xMax = 0;
    double step = (double)(int)((xMax-xMin)/6);
    setAxisScale(QwtPlot::xBottom,xMin,xMax,step);
    QwtPointSeriesData *data = new QwtPointSeriesData(samples);
    andCurve->setData(data);
    replot();
}

void PlotCustom::setStatusEnabled(bool status){
    if (xorCurve == nullptr || andCurve == nullptr){
        return;
    }
    if (status==true){
        xorCurve->attach(this);
        andCurve->attach(this);
        setTitle(title);
        replot();
    }else{
        xorCurve->detach();
        andCurve->detach();
        setTitle("");
        replot();
    }
}

