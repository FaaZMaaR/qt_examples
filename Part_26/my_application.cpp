#include <QtWidgets>
#include <my_application.h>

MyApplication::MyApplication(QWidget* pwgt) : QWidget(pwgt){
    QComboBox* pcbo=new QComboBox;
    QSpinBox* pspb=new QSpinBox;
    QSlider* psld=new QSlider(Qt::Horizontal);
    QRadioButton* prad=new QRadioButton("Radio Button");
    QCheckBox* pchk=new QCheckBox("Check Box");
    QPushButton* pcmd=new QPushButton("Push Button");
    pcbo->addItems(QStyleFactory::keys());
    connect(pcbo,&QComboBox::textActivated,this,&MyApplication::slotChangeStyle);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(pcbo);
    pvbx->addWidget(pspb);
    pvbx->addWidget(psld);
    pvbx->addWidget(prad);
    pvbx->addWidget(pchk);
    pvbx->addWidget(pcmd);
    setLayout(pvbx);
}

void MyApplication::slotChangeStyle(const QString& str){
    QStyle* pstyle=QStyleFactory::create(str);
    QApplication::setStyle(pstyle);
}