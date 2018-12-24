#ifndef CUSTOMHISTOGRAM_H
#define CUSTOMHISTOGRAM_H
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_series_data.h>
#include <qwt_plot_barchart.h>

class QwtPlotBarChart;

class CustomHistogram : public QwtPlot
{
	Q_OBJECT
public:
    CustomHistogram(QWidget *parent = 0) : QwtPlot(parent){ initialize();}
    CustomHistogram(const QwtText &title, QWidget *parent = 0) : QwtPlot(title, parent){ initialize();}
    ~CustomHistogram();
    void initialize();
    QwtPlotGrid *grid = nullptr;
    void setStatusEnabled(bool status);
    void setLogX(bool);
    void setLogY(bool);
    
    void setData(const QVector<QPointF>&);

    QString title = "Histogram";
protected:
	QwtPlotBarChart* fBarChart;
private:
	bool fLogY=false;
	bool fLogX=false;
};

#endif // CUSTOMHISTOGRAM_H
