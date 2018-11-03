#ifndef PLOTCUSTOM_H
#define PLOTCUSTOM_H
#include <qwt_plot.h>

class PlotCustom : public QwtPlot
{
public:
    PlotCustom(QWidget *parent = 0) : QwtPlot(parent){ initialize();}
    PlotCustom(const QwtText &title, QWidget *parent = 0) : QwtPlot(title, parent){ initialize();}
    void initialize();
};

#endif // PLOTCUSTOM_H
