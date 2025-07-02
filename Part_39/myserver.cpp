#include "myserver.h"

MyServer::MyServer(int nPort,QWidget* pwgt) : QWidget(pwgt), m_nNextBlockSize(0){
    m_ptcpServer=new QTcpServer(this);
    if(!m_ptcpServer->listen(QHostAddress::Any,nPort)){
        QMessageBox::critical(nullptr,"Server Error","Unable to start the server: "+m_ptcpServer->errorString());
        m_ptcpServer->close();
        return;
    }
    connect(m_ptcpServer,&QTcpServer::newConnection,this,&MyServer::slotNewConnection);
    m_ptxt=new QTextEdit(this);
    m_ptxt->setReadOnly(true);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(new QLabel("<H1>Server</H1>",this));
    pvbx->addWidget(m_ptxt);
    setLayout(pvbx);
}

void MyServer::slotNewConnection(){
    QTcpSocket* pClientSocket=m_ptcpServer->nextPendingConnection();
    connect(pClientSocket,&QTcpSocket::disconnected,pClientSocket,&QTcpSocket::deleteLater);
    connect(pClientSocket,&QTcpSocket::readyRead,this,&MyServer::slotReadClient);
    sendToClient(pClientSocket,"Server Response: Connected!");
}

void MyServer::slotReadClient(){
    QTcpSocket* pClientSocket=(QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_6_4);
    for(;;){
        if(!m_nNextBlockSize){
            if(pClientSocket->bytesAvailable()<sizeof(quint16)){
                break;
            }
            in >> m_nNextBlockSize;
        }
        if(pClientSocket->bytesAvailable()<m_nNextBlockSize){
            break;
        }
        QTime time;
        QString str;
        in >> time >> str;
        QString strMessage=time.toString()+" "+"Client has sent - "+str;
        m_ptxt->append(strMessage);
        m_nNextBlockSize=0;
        sendToClient(pClientSocket,"Server Response: Received \""+str+"\"");
    }
}

void MyServer::sendToClient(QTcpSocket* pSocket,const QString& str){
    QByteArray arrBlock;
    QDataStream out(&arrBlock,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(arrBlock.size()-sizeof(quint16));
    pSocket->write(arrBlock);
}