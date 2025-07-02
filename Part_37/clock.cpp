#include "clock.h"

Clock::Clock(QWidget* pwgt) : QLabel(pwgt){
    QTimer* ptimer=new QTimer(this);
    connect(ptimer,&QTimer::timeout,this,&Clock::slotUpdateDateTime);
    ptimer->start(500);
    slotUpdateDateTime();
}

void Clock::slotUpdateDateTime(){
    QString str=QDateTime::currentDateTime().toString(Qt::ISODate);
    setText("<H2><CENTER>"+str+"</CENTER></H2>");
}