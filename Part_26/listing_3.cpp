#include <QtWidgets>
#include <custom_style.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QPushButton* pcmdA=new QPushButton("Button 1");
    QPushButton* pcmdB=new QPushButton("Button 2");
    QPushButton* pcmdC=new QPushButton("Button 3");
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(pcmdA);
    pvbx->addWidget(pcmdB);
    pvbx->addWidget(pcmdC);
    wgt.setLayout(pvbx);
    app.setStyle(new CustomStyle);
    wgt.show();
    return app.exec();
}