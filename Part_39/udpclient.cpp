#include <QDateTime>
#include "udpclient.h"

UdpClient::UdpClient(QWidget* pwgt) : QTextEdit(pwgt){
    setWindowTitle("UdpClient");
    m_pudp=new QUdpSocket(this);
    m_pudp->bind(2424);
    connect(m_pudp,&QUdpSocket::readyRead,this,&UdpClient::slotProcessDatagrams);
}

void UdpClient::slotProcessDatagrams(){
    QByteArray baDatagram;
    do{
        baDatagram.resize(m_pudp->pendingDatagramSize());
        m_pudp->readDatagram(baDatagram.data(),baDatagram.size());
    }
    while(m_pudp->hasPendingDatagrams());
    QDateTime dateTime;
    QDataStream in(&baDatagram,QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_6_4);
    in >> dateTime;
    append("Received: "+dateTime.toString());
}