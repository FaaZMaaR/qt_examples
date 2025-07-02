#include <QtWidgets>

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
    QFile file("simple.qss");
    file.open(QFile::ReadOnly);
    QString strCSS=QLatin1String(file.readAll());
    qApp->setStyleSheet(strCSS);
    wgt.show();
    return app.exec();
}