#include <qt6/QtWidgets/QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QLabel lbl("Hello, world!");
    lbl.show();
    return app.exec();
}