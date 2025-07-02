#include <qt6/QtWidgets/QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QPixmap pix("skull.png");
    QCursor cur(pix);
    wgt.setCursor(cur);
    wgt.resize(180,100);
    wgt.show();
    return app.exec();
}