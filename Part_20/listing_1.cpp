#include <QtWidgets>

class ElidedText : public QWidget{
    protected:
        virtual void paintEvent(QPaintEvent*){
            QString str="This is a long text. Please, resize the window";
            QString strElided=fontMetrics().elidedText(str,Qt::ElideMiddle,width());
            QPainter painter(this);
            painter.drawText(rect(),strElided);
        }

        public:
            ElidedText(QWidget* pwgt=nullptr) : QWidget(pwgt){}
};

int main(int argc,char** argv){
    QApplication app(argc,argv);
    ElidedText et;
    et.resize(200,20);
    et.show();
    return app.exec();
}