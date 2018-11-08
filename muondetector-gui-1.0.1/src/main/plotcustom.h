#ifndef PLOTCUSTOM_H
#define PLOTCUSTOM_H
#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>
//#include <qwt_scale_engine.h>
//#include <qwt_date_scale_draw.h>
//#include <qwt_date_scale_engine.h>

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
    void setStatusEnabled(bool status);

    // for other plots: subclass "PlotCustom" and put all specific functions (like below) to the new class
    void plotXorSamples(QVector<QPointF>& xorSamples);
    void plotAndSamples(QVector<QPointF>& andSamples);

    const QString title = "Rate Statistics";
};

#endif // PLOTCUSTOM_H
