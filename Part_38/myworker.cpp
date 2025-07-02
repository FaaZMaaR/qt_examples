#include "myworker.h"

MyWorker::MyWorker(QObject* pobj) : QObject(pobj), m_nValue(10){
    m_ptimer=new QTimer(this);
    connect(m_ptimer,&QTimer::timeout,this,&MyWorker::setNextValue);
}

void MyWorker::slotDoWork(){
    m_ptimer->start(1000);
}

void MyWorker::setNextValue(){
    emit valueChanged(--m_nValue);
    if(!m_nValue){
        m_ptimer->stop();
        emit finished();
    }
}