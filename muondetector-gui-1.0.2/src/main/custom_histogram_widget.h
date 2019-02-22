#ifndef CUSTOMHISTOGRAM_H
#define CUSTOMHISTOGRAM_H
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_series_data.h>
#include <qwt_plot_histogram.h>

class QwtPlotHistogram;
class Histogram;

class CustomHistogram : public QwtPlot
{
	Q_OBJECT
public:
    CustomHistogram(QWidget *parent = 0) : QwtPlot(parent){ initialize();}
    CustomHistogram(const QwtText &title, QWidget *parent = 0) : QwtPlot(title, parent){ initialize();}
    ~CustomHistogram();
    void initialize();
    QwtPlotGrid *grid = nullptr;
	//virtual void replot();
	void update();
	void clear();
	void setStatusEnabled(bool status);
	void setNrBins(int bins) { fNrBins = bins; clear(); }
	int getNrBins() const;
	void setXMin(double val);
	double getXMin() const { return fMinX; }
	void setXMax(double val);
	double getXMax() const { return fMaxX; }
	// log X scale not implemented yet	
	void setLogX(bool);
	bool getLogX() const { return fLogX; }
    void setLogY(bool);
	bool getLogY() const { return fLogY; }
	void rescalePlot();
	void fill(double x, double mult = 1.);
	void setBinContent(int bin, double value);
	double getBinContent(int bin) const;
	double getUnderflow() const { return fUnderflow; }
	double getOverflow() const { return fOverflow; }
	long int getEntries();

	QwtPlotHistogram* getHistogramPlot() { return fBarChart; }
    
    void setData(const QVector<QPointF>&);
    void setData(const Histogram& hist);

    QString title = "Histogram";
private:
//	QwtPlotBarChart* fBarChart;
	QwtPlotHistogram* fBarChart = nullptr;
	int xValue2Bin(double value);

	bool fLogY=false;
	bool fLogX=false;
	int fNrBins=100;
	double fMinX=0.0;
	double fMaxX=1.0;
	double fOverflow=0;
	double fUnderflow=0;
	QMap<int, double> fHistogramMap;
};

#endif // CUSTOMHISTOGRAM_H
