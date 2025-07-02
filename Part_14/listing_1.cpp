#include <QtWidgets>
#include <mouse_observer.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    MouseObserver wgt;
    wgt.resize(250,130);
    wgt.show();
    return app.exec();
}