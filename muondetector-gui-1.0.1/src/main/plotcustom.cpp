#include <plotcustom.h>
#include <qwt_legend.h>
#include <qwt.h>
void PlotCustom::initialize(){
    // Show a title
       setTitle( "This is an Example" );
       setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
       setAutoReplot(true);
       replot();
       show();
}
