#include <QtWidgets>
#include <printer.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    Printer* pprinter=new Printer;
    QPushButton* pcmd=new QPushButton("Print");
    QObject::connect(pcmd,&QPushButton::clicked,pprinter,&Printer::slotPrint);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->setContentsMargins(0,0,0,0);
    pvbx->setSpacing(0);
    pvbx->addWidget(pprinter);
    pvbx->addWidget(pcmd);
    wgt.setLayout(pvbx);
    wgt.resize(250,320);
    wgt.show();
    return app.exec();
}