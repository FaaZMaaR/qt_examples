#include "webbrowser.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    WebBrowser webBrowser;
    webBrowser.show();
    return app.exec();
}