#include <qwt_legend.h>
#include <qwt.h>
#include <qwt_scale_engine.h>
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
//       setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine());
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
       
       replot();
       show();
}


void CustomHistogram::setData(const QVector<QPointF>& samples)
{
	fBarChart->setSamples(samples);
    long int max=0;
    for (int i=0; i<samples.size(); i++) {
		if (samples[i].y()>max) max=samples[i].y();
	}
    if (fLogY) setAxisScale(QwtPlot::yLeft,0.1, 1.5*max);
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
//        setTitle("");
        replot();
    }
}

void CustomHistogram::setLogY(bool logscale){
	if (logscale) {
       setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine());
       setAxisAutoScale(QwtPlot::yLeft,false);
       fLogY=true;
	} else {
       setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine());
       setAxisAutoScale(QwtPlot::yLeft,true);
       fLogY=false;
	}
}
