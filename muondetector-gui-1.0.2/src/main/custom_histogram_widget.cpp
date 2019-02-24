#include <qwt_legend.h>
#include <qwt.h>
#include <qwt_scale_engine.h>
#include <qwt_samples.h>
#include <QMenu>
#include <numeric>
#include <histogram.h>

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
    const QPen grayPen(Qt::gray);
    grid->setPen(grayPen);
	grid->attach(this);
	fBarChart = new QwtPlotHistogram( title );
		//fBarChart = new QwtPlotBarChart( title );
		//fBarChart->setLayoutPolicy( QwtPlotBarChart::AutoAdjustSamples );
		//fBarChart->setSpacing( 0 );
		//fBarChart->setMargin( 3 );
	
	fBarChart->setBrush(QBrush(Qt::darkBlue, Qt::SolidPattern));
	fBarChart->attach( this );

    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(const QPoint &  )),this,SLOT(popUpMenu(const QPoint &)));

	replot();
	show();
}

int CustomHistogram::xValue2Bin(double value)
{
	double range=fMaxX-fMinX;
	if (range<=0.) return -1;	
	int bin=value/range*fNrBins+0.5;
	return bin;
}

void CustomHistogram::fill(double x, double mult)
{
	if (!isEnabled()) return;
	int bin=xValue2Bin(x);
	if (bin<0) {
		fUnderflow+=mult;
		return;
	} else if (bin>=fNrBins) {
		fOverflow+=mult;
		return;
	}
	fHistogramMap[bin]+=mult;
}

void CustomHistogram::setBinContent(int bin, double value)
{
	if (bin>=0 && bin<fNrBins) fHistogramMap[bin]=value;
}

double CustomHistogram::getBinContent(int bin) const
{
	if (bin>=0 && bin<fNrBins) return fHistogramMap[bin];
	else return double();
}

long int CustomHistogram::getEntries()
{
	double sum = fUnderflow+fOverflow;
	foreach (double value, fHistogramMap) sum+=value;	

/*
	// this should also work, but it doesn't compile. reason unclear
	for (const auto &entry : fHistogramMap) {
		sum+=entry.second;
	}

	// this should also work, but it doesn't compile. reason unclear
	sum += std::accumulate(fHistogramMap.begin(), fHistogramMap.end(), 0.,
                                          [](double previous, const QPair<const int, double>& p)
                                          { return previous + p.second; });
*/
	return (long int)sum;
}

void CustomHistogram::setData(const QVector<QPointF>& samples)
{
	if (!isEnabled()) return;
	//fBarChart->setSamples(samples);
	return;
/*
	const int N = samples.size();	
	QVector< QwtIntervalSample > intervals;
	intervals.clear();
	double rangeX=samples.last().x()-samples.first().x();
	double xBinSize = rangeX/(N-1);
	for (int i=0; i<N; i++) {
		QwtIntervalSample interval(samples[i].y(), samples[i].x()-xBinSize/2., samples[i].x()+xBinSize/2.);
		intervals.push_back(interval);
	}
	fBarChart->setSamples(intervals);
//	fBarChart->setSamples(samples);
	long int max=0;
	for (int i=0; i<samples.size(); i++) {
		if (samples[i].y()>max) max=samples[i].y();
	}
	if (fLogY) {
		setAxisScale(QwtPlot::yLeft,0.1, 1.5*max);
	}
	replot();
*/
}

void CustomHistogram::setData(const Histogram &hist)
{
    fHistogramMap.clear();
    fNrBins = hist.getNrBins();
    fMinX=hist.getMin();
    fMaxX=hist.getMax();
    fUnderflow=hist.getUnderflow();
    fOverflow=hist.getOverflow();
    for (int i=0; i<fNrBins; i++) fHistogramMap[i]=hist.getBinContent(i);
    update();
}

void CustomHistogram::popUpMenu(const QPoint & pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction action1("&Log Y", this);
    action1.setCheckable(true);
    action1.setChecked(getLogY());
    connect(&action1, &QAction::toggled, this, [this](bool checked){ this->setLogY(checked); this->update(); } );
    contextMenu.addAction(&action1);
    contextMenu.addSeparator();
    QAction action2("&Clear", this);
//    connect(&action2, &QAction::triggered, this, &CustomHistogram::clear );
    connect(&action2, &QAction::triggered, this,  [this](bool checked){ this->clear(); this->update(); });
    contextMenu.addAction(&action2);

    contextMenu.exec(mapToGlobal(pos));
//    contextMenu.popup(mapToGlobal(pos));
}

void CustomHistogram::update()
{
	//QwtPlot::replot();
	//return;
	if (!isEnabled()) return;
    if (fHistogramMap.empty() || fNrBins<=1) { fBarChart->detach(); QwtPlot::replot(); return; }
    fBarChart->attach(this);
	QVector<QwtIntervalSample> intervals;
	double rangeX=fMaxX-fMinX;
	double xBinSize = rangeX/(fNrBins-1);
	double max=0;
	for (int i=0; i<fNrBins; i++) {
		if (fHistogramMap[i]>max) max=fHistogramMap[i];
		double xval = fMinX+(fMaxX-fMinX)*i/(fNrBins-1);
		QwtIntervalSample interval(fHistogramMap[i]+1e-12, xval-xBinSize/2., xval+xBinSize/2.);
		intervals.push_back(interval);
	}
	if (intervals.size() && fBarChart != nullptr) fBarChart->setSamples(intervals);
	if (fLogY) {
		setAxisScale(QwtPlot::yLeft,0.1, 1.5*max);
	}
	replot();
}

/*
void CustomHistogram::update()
{
	//QwtPlot::replot();
	//return;
	if (!isEnabled()) return;
	if (fHistogramMap->empty() || fNrBins<=1) { QwtPlot::replot(); return; } 
	QVector<QPointF> points;
	points.clear();
	//intervals.clear();
	double rangeX=fMaxX-fMinX;
	double xBinSize = rangeX/(fNrBins-1);
	double max=0;
	for (int i=0; i<fNrBins; i++) {
		if ((*fHistogramMap)[i]>max) max=(*fHistogramMap)[i];
		double xval = fMinX+(fMaxX-fMinX)*i/fNrBins;
		QPointF point;
		point.rx()=xval;
		point.ry()=(double)((*fHistogramMap)[i])+1e-12;
		points.push_back(point);
	}
//	if (points.size() && fBarChart != nullptr) fBarChart->setSamples(points);
	if (points.size() && fBarChart != nullptr) setData(points);
//	fBarChart->setSamples(samples);
	if (fLogY) {
		setAxisScale(QwtPlot::yLeft,0.1, 1.5*max);
	}
//	QwtPlot::replot();
	replot();
}
*/

void CustomHistogram::clear()
{
	fHistogramMap.clear();
	fOverflow=fUnderflow=0;
    update();
}

void CustomHistogram::setStatusEnabled(bool status){
    if (status==true){
        const QPen blackPen(Qt::black);
        grid->setPen(blackPen);
        fBarChart->attach(this);
        setTitle(title);
        update();
    }else{
        const QPen grayPen(Qt::gray);
        grid->setPen(grayPen);
        fBarChart->detach();
        setTitle("");
        update();
    }
}

void CustomHistogram::setLogY(bool logscale){
	if (logscale) {
		setAxisScaleEngine(QwtPlot::yLeft, new QwtLogScaleEngine());
		setAxisAutoScale(QwtPlot::yLeft,false);
		fBarChart->setBaseline(1e-12);
		fLogY=true;
	} else {
		setAxisScaleEngine(QwtPlot::yLeft, new QwtLinearScaleEngine());
		setAxisAutoScale(QwtPlot::yLeft,true);
		fBarChart->setBaseline(0);
		fLogY=false;
	}
}

void CustomHistogram::setXMin(double val)
{
	fMinX = val;
	rescalePlot();
}

void CustomHistogram::setXMax(double val)
{
	fMaxX = val; 
	rescalePlot();
}

void CustomHistogram::rescalePlot()
{
	double margin = 0.05*(fMaxX	- fMinX);
	setAxisScale(QwtPlot::xBottom,fMinX-margin, fMaxX+margin);
}

