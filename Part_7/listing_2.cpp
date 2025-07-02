#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QPixmap pix;
    pix.load("image.png");
    QLabel lbl;
    lbl.resize(pix.size());
    lbl.setPixmap(pix);
    lbl.show();
    return app.exec();
}