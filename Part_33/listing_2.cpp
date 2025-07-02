#include "help_browser.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    HelpBrowser hb("/home/faazmaar/Загрузки/QCustomPlot/qcustomplot/documentation/html","index.html");
    hb.resize(450,350);
    hb.show();
    return app.exec();
}