#include <QtWidgets>
#include <custom_widget.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    CustomWidget* pcw=new CustomWidget;
    QScrollBar* phsb=new QScrollBar(Qt::Horizontal);
    phsb->setRange(0,100);
    QObject::connect(phsb,&QScrollBar::valueChanged,pcw,&CustomWidget::slotSetProgress);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(pcw);
    pvbx->addWidget(phsb);
    wgt.setLayout(pvbx);
    wgt.show();
    return app.exec();
}