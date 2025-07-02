#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QToolBox tbx;
    QStringList lst;
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str,lst){
        tbx.addItem(new QLabel(str,&tbx),QPixmap(str+".jpg"),str);
    }
    tbx.resize(100,80);
    tbx.show();
    return app.exec();
}