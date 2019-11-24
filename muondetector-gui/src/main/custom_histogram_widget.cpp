#include <qwt_legend.h>
#include <qwt.h>
#include <qwt_scale_engine.h>
#include <qwt_samples.h>
#include <qwt_plot_renderer.h>
#include <QMenu>
#include <QFileDialog>
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
    fName = hist.getName();
    fUnit = hist.getUnit();
    fNrBins = hist.getNrBins();
    fMin=hist.getMin();
    fMax=hist.getMax();
    fUnderflow=hist.getUnderflow();
    fOverflow=hist.getOverflow();
    fHistogramMap.clear();
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

    QAction action3("&Export", this);
    connect(&action3, &QAction::triggered, this, &CustomHistogram::exportToFile );
    contextMenu.addAction(&action3);

    contextMenu.exec(mapToGlobal(pos));
//    contextMenu.popup(mapToGlobal(pos));
}

void CustomHistogram::exportToFile() {
    QPixmap qPix = QPixmap::grabWidget(this);
    if(qPix.isNull()){
        qDebug("Failed to capture the plot for saving");
        return;
    }
    QString types(	"JPEG file (*.jpeg);;"				// Set up the possible graphics formats
            "Portable Network Graphics file (*.png);;"
            "Bitmap file (*.bmp);;"
            "Portable Document Format (*.pdf);;"
            "Scalable Vector Graphics Format (*.svg);;"
            "ASCII raw data (*.txt)");
    QString filter;							// Type of filter
    QString jpegExt=".jpeg", pngExt=".png", tifExt=".tif", bmpExt=".bmp", tif2Ext="tiff";		// Suffix for the files
    QString pdfExt=".pdf", svgExt=".svg";
    QString txtExt=".txt";
    QString suggestedName="";
    QString fn = QFileDialog::getSaveFileName(this,tr("Export Histogram"),
                                                  suggestedName,types,&filter);

    if ( !fn.isEmpty() ) {						// If filename is not null
        if (fn.contains(jpegExt)) {				// Remove file extension if already there
            fn.remove(jpegExt);
        } else if (fn.contains(pngExt)) {
            fn.remove(pngExt);
        } else if (fn.contains(bmpExt)) {
            fn.remove(bmpExt);
        } else if (fn.contains(pdfExt)) {
            fn.remove(pdfExt);
        } else if (fn.contains(svgExt)) {
            fn.remove(svgExt);
        } else if (fn.contains(txtExt)) {
            fn.remove(txtExt);
        }

        if (filter.contains(jpegExt)) {				// OR, Test to see if jpeg and save
            fn+=jpegExt;
            qPix.save( fn, "JPEG" );
        }
        else if (filter.contains(pngExt)) {			// OR, Test to see if png and save
            fn+=pngExt;
            qPix.save( fn, "PNG" );
        }
        else if (filter.contains(bmpExt)) {			// OR, Test to see if bmp and save
            fn+=bmpExt;
            qPix.save( fn, "BMP" );
        }
        else if (filter.contains(pdfExt)) {
            fn+=pdfExt;
            QwtPlotRenderer renderer(this);
            renderer.renderDocument(this, fn, "pdf", QSizeF(297/2,210/2),72);
        }
        else if (filter.contains(svgExt)) {
            fn+=svgExt;
            QwtPlotRenderer renderer(this);
            renderer.renderDocument(this, fn, "svg", QSizeF(297/2,210/2),72);
        }
        if (filter.contains(txtExt)) {
            fn+=txtExt;
            // export histo in asci raw data format
            QFile file(fn);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
            QTextStream out(&file);

            for (int i=0; i<fNrBins; i++) {
                out << bin2Value(i) << "  " << fHistogramMap[i] << "\n";
            }
        }
    }
}

void CustomHistogram::update()
{
	//QwtPlot::replot();
	//return;
	if (!isEnabled()) return;
    if (fHistogramMap.empty() || fNrBins<=1) { fBarChart->detach(); QwtPlot::replot(); return; }
    fBarChart->attach(this);
	QVector<QwtIntervalSample> intervals;
    double rangeX=fMax-fMin;
	double xBinSize = rangeX/(fNrBins-1);
	double max=0;
	for (int i=0; i<fNrBins; i++) {
		if (fHistogramMap[i]>max) max=fHistogramMap[i];
        double xval=bin2Value(i);
		QwtIntervalSample interval(fHistogramMap[i]+1e-12, xval-xBinSize/2., xval+xBinSize/2.);
		intervals.push_back(interval);
	}
	if (intervals.size() && fBarChart != nullptr) fBarChart->setSamples(intervals);
	if (fLogY) {
		setAxisScale(QwtPlot::yLeft,0.1, 1.5*max);
	}
	replot();
}

void CustomHistogram::clear()
{
	fHistogramMap.clear();
	fOverflow=fUnderflow=0;
    emit histogramCleared(QString::fromStdString(fName));
//    qDebug()<<"sent signal CustomHistogram::histogramCleared("<<QString::fromStdString(fName)<<")";
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
    fMin = val;
	rescalePlot();
}

void CustomHistogram::setXMax(double val)
{
    fMax = val;
	rescalePlot();
}

void CustomHistogram::rescalePlot()
{
    double margin = 0.05*(fMax	- fMin);
    setAxisScale(QwtPlot::xBottom,fMin-margin, fMax+margin);
}
