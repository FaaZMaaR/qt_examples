#include <QtWidgets>

QWidget* styleWidget(QStyle* pstyle){
    QGroupBox* pgr=new QGroupBox(pstyle->metaObject()->className());
    QScrollBar* psbr=new QScrollBar(Qt::Horizontal);
    QCheckBox* pchk=new QCheckBox("Check Box");
    QSlider* psld=new QSlider(Qt::Horizontal);
    QRadioButton* prad=new QRadioButton("Radio Button");
    QPushButton* pcmd=new QPushButton("Push Button");
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(psbr);
    pvbx->addWidget(pchk);
    pvbx->addWidget(psld);
    pvbx->addWidget(prad);
    pvbx->addWidget(pcmd);
    pgr->setLayout(pvbx);
    QList<QWidget*> pwgtList=pgr->findChildren<QWidget*>();
    foreach(QWidget* pwgt,pwgtList){
        pwgt->setStyle(pstyle);
    }
    return pgr;
}

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QHBoxLayout* phbx=new QHBoxLayout;
    foreach(QString str,QStyleFactory::keys()){
        phbx->addWidget(styleWidget(QStyleFactory::create(str)));
    }
    wgt.setLayout(phbx);
    wgt.show();
    return app.exec();
}