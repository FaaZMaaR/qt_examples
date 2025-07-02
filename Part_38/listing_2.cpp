#include <QtWidgets>
#include "myworker.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QLCDNumber lcd;
    QThread thread;
    MyWorker worker;
    QObject::connect(&worker,&MyWorker::valueChanged,&lcd,qOverload<int>(&QLCDNumber::display));
    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220,90);
    lcd.show();
    worker.moveToThread(&thread);
    QObject::connect(&thread,&QThread::started,&worker,&MyWorker::slotDoWork);
    QObject::connect(&worker,&MyWorker::finished,&app,&QApplication::quit);
    thread.start();
    int nResult=app.exec();
    thread.quit();
    thread.wait();
    return nResult;
}