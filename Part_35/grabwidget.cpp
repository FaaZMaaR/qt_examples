#include "grabwidget.h"

GrabWidget::GrabWidget(QWidget* pwgt) : QWidget(pwgt){
    resize(640,480);
    m_plbl=new QLabel(this);
    QPushButton* pcmd=new QPushButton("Capture Screen",this);
    connect(pcmd,&QPushButton::clicked,this,&GrabWidget::slotGrabScreen);
    QVBoxLayout* pvbx=new QVBoxLayout(this);
    pvbx->addWidget(pcmd);
    pvbx->addWidget(m_plbl);
    setLayout(pvbx);
}

void GrabWidget::slotGrabScreen(){
    QScreen* pscreen=QApplication::primaryScreen();
    if(const QWindow* window=windowHandle()){
        pscreen=window->screen();
    }
    if(!pscreen){
        return;
    }
    m_pic=pscreen->grabWindow(0);
    //m_pic=QPixmap("img.jpg");
    m_plbl->setPixmap(m_pic.scaled(m_plbl->size()));
}