#include <QtWidgets>

class Window : public QLabel{
    private:
        QPoint m_ptPosition;

    protected:
        virtual void mousePressEvent(QMouseEvent* pe){
            m_ptPosition=pe->pos();
        }

        virtual void mouseMoveEvent(QMouseEvent* pe){
            move(pe->globalPos()-m_ptPosition);
        }

    public:
        Window(QWidget* pwgt=nullptr) : QLabel(pwgt,Qt::FramelessWindowHint | Qt::Window){}
};

int main(int argc,char** argv){
    QApplication app(argc,argv);
    Window wnd;
    wnd.setAttribute(Qt::WA_TranslucentBackground);
    wnd.setPixmap(QPixmap("image.png"));
    QPushButton* pcmdQuit=new QPushButton("X");
    pcmdQuit->setFixedSize(16,16);
    QObject::connect(pcmdQuit,&QPushButton::clicked,&app,&QApplication::quit);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(pcmdQuit);
    pvbx->addStretch(1);
    wnd.setLayout(pvbx);
    wnd.show();
    return app.exec(); 
}