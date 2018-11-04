#include <plotcustom.h>
#include <qwt_legend.h>
#include <qwt.h>
void PlotCustom::initialize(){
    // Show a title
       setTitle( "Rate Statistics" );
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       grid = new QwtPlotGrid();
       grid->setPen(QColor::QColor("black"), 0.1, Qt::SolidLine);
       grid->attach(this);
       setStyleSheet("background-color: white; border: 0px;");
       replot();
       show();
}
