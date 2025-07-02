#include <QApplication>
#include <ogldraw.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    OGLDraw oglDraw;
    oglDraw.resize(400,200);
    oglDraw.show();
    return app.exec();
}