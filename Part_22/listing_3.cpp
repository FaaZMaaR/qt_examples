#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QLabel lbl;
    lbl.setPixmap(QPixmap("img.jpg"));
    QGraphicsColorizeEffect effect;
    lbl.setGraphicsEffect(&effect);
    QPropertyAnimation anim(&effect,"color");
    anim.setStartValue(QColor(Qt::gray));
    anim.setKeyValueAt(0.25f,QColor(Qt::green));
    anim.setKeyValueAt(0.5f,QColor(Qt::blue));
    anim.setKeyValueAt(0.75f,QColor(Qt::red));
    anim.setEndValue(QColor(Qt::black));
    anim.setDuration(3000);
    anim.setLoopCount(-1);
    anim.start();
    lbl.show();
    return app.exec();
}