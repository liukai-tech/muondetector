#ifndef PLOTCUSTOM_H
#define PLOTCUSTOM_H
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

class PlotCustom : public QwtPlot
{
public:
    PlotCustom(QWidget *parent = 0) : QwtPlot(parent){ initialize();}
    PlotCustom(const QwtText &title, QWidget *parent = 0) : QwtPlot(title, parent){ initialize();}
    ~PlotCustom();
    void initialize();
    QwtPlotGrid *grid = nullptr;
    QwtPlotCurve *xorCurve = nullptr;
    QwtPlotCurve *andCurve = nullptr;
    QwtPointSeriesData *xorData = nullptr;
    QwtPointSeriesData *andData = nullptr;

    void plotXorSamples(QVector<QPointF>& xorSamples);
    void plotAndSamples(QVector<QPointF>& andSamples);
};

#endif // PLOTCUSTOM_H
