#ifndef PLOTCUSTOM_H
#define PLOTCUSTOM_H
#include <qwt_plot.h>
#include <qwt_plot_grid.h>

class PlotCustom : public QwtPlot
{
public:
    PlotCustom(QWidget *parent = 0) : QwtPlot(parent){ initialize();}
    PlotCustom(const QwtText &title, QWidget *parent = 0) : QwtPlot(title, parent){ initialize();}
    void initialize();
    QwtPlotGrid *grid = nullptr;
};

#endif // PLOTCUSTOM_H
