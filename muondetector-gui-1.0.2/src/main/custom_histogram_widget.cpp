#include <qwt_legend.h>
#include <qwt.h>
#include "custom_histogram_widget.h"

CustomHistogram::~CustomHistogram(){
    if (grid!=nullptr) { delete grid; grid=nullptr;}
    if (fBarChart!=nullptr) { delete fBarChart; fBarChart=nullptr;}
    
}

void CustomHistogram::initialize(){
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       setStyleSheet("background-color: white; border: 0px;");
       setAutoReplot(true);
       enableAxis(QwtPlot::yLeft,true);
       enableAxis(QwtPlot::yRight,false);
       setAxisAutoScale(QwtPlot::xBottom,true);
       setAxisAutoScale(QwtPlot::yLeft,true);
       //setAxisAutoScale(QwtPlot::yRight,true);

       grid = new QwtPlotGrid();
       const QPen blackPen(Qt::black);
       grid->setPen(blackPen);
       grid->attach(this);
       
		fBarChart = new QwtPlotBarChart( title );
		fBarChart->setLayoutPolicy( QwtPlotBarChart::AutoAdjustSamples );
		fBarChart->setSpacing( 1 );
		fBarChart->setMargin( 3 );

		fBarChart->attach( this );
       

       //xorCurve = new QwtPlotCurve();
       //xorCurve->setYAxis(QwtPlot::yRight);
       //xorCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       ////xorCurve->setStyle(QwtPlotCurve::Steps);
       //QColor xorCurveColor = Qt::darkGreen;
       //xorCurveColor.setAlphaF(0.3);
       //const QPen greenPen(xorCurveColor);
       //xorCurve->setPen(greenPen);
       //xorCurve->setBrush(xorCurveColor);
       //xorCurve->attach(this);

       //andCurve = new QwtPlotCurve();
       //andCurve->setYAxis(QwtPlot::yRight);
       //andCurve->setRenderHint(QwtPlotCurve::RenderAntialiased, true);
       ////xorCurve->setStyle(QwtPlotCurve::Steps);
       //QColor andCurveColor = Qt::darkBlue;
       //andCurveColor.setAlphaF(0.3);
       //const QPen bluePen(andCurveColor);
       //andCurve->setPen(bluePen);
       //andCurve->setBrush(andCurveColor);
       //andCurve->attach(this);
       replot();
       show();
}


void CustomHistogram::setData(const QVector<QPointF>& samples)
{
	fBarChart->setSamples(samples);
	replot();
}



void CustomHistogram::setStatusEnabled(bool status){
    //if (xorCurve == nullptr){
        //return;
    //}
    if (status==true){
        //xorCurve->attach(this);
        setTitle(title);
        replot();
    }else{
        //xorCurve->detach();
        setTitle("");
        replot();
    }
}
