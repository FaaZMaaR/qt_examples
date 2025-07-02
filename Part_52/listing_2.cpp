#include <QtWidgets>
#include <QJSEngine>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget* pwgt=new QWidget;
    QLineEdit* ptxt=new QLineEdit;
    ptxt->setObjectName("lineedit");
    QLabel* plbl1=new QLabel("1");
    plbl1->setObjectName("label1");
    QLabel* plbl2=new QLabel("2");
    plbl2->setObjectName("label2");
    QLabel* plbl3=new QLabel("3");
    plbl3->setObjectName("label3");
    QLabel* plbl4=new QLabel("4");
    plbl4->setObjectName("label4");
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(ptxt);
    pvbx->addWidget(plbl1);
    pvbx->addWidget(plbl2);
    pvbx->addWidget(plbl3);
    pvbx->addWidget(plbl4);
    pwgt->setLayout(pvbx);
    pwgt->show();
    QJSEngine se;
    QFile file("script.js");
    if(file.open(QFile::ReadOnly)){
        QJSValue sw=se.newQObject(pwgt);
        se.globalObject().setProperty("wgt",sw);
        QList<QObject*> lst=pwgt->findChildren<QObject*>();
        foreach(QObject* pobj,lst){
            sw=se.newQObject(pobj);
            se.globalObject().setProperty(pobj->objectName(),sw);
        }
        QJSValue result=se.evaluate(QLatin1String(file.readAll()));
        if(result.isError()){
            QMessageBox::critical(0,"Evaluating error",result.toString(),QMessageBox::Yes);
        }
    }
    else{
        QMessageBox::critical(0,"File open error","Can not open the script file",QMessageBox::Yes);
    }
    return app.exec();
}