#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QLabel lbl("This app will be closed in 60 seconds");
    QTimer::singleShot(60*1000,&app,&QApplication::quit);
    lbl.show();
    return app.exec();
}