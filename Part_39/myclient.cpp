#include "myclient.h"

MyClient::MyClient(const QString& strHost,int nPort,QWidget* pwgt) : QWidget(pwgt), m_nNextBlockSize(0){
    m_pTcpSocket=new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost,nPort);
    connect(m_pTcpSocket,&QTcpSocket::connected,this,&MyClient::slotConnected);
    connect(m_pTcpSocket,&QTcpSocket::readyRead,this,&MyClient::slotReadyRead);
    connect(m_pTcpSocket,&QTcpSocket::errorOccurred,this,&MyClient::slotError);
    m_ptxtInfo=new QTextEdit(this);
    m_ptxtInput=new QLineEdit(this);
    m_ptxtInfo->setReadOnly(true);
    QPushButton* pcmd=new QPushButton("Send",this);
    connect(pcmd,&QPushButton::clicked,this,&MyClient::slotSendToServer);
    connect(m_ptxtInput,&QLineEdit::returnPressed,this,&MyClient::slotSendToServer);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(new QLabel("<H1>Client</H1>",this));
    pvbx->addWidget(m_ptxtInfo);
    pvbx->addWidget(m_ptxtInput);
    pvbx->addWidget(pcmd);
    setLayout(pvbx);
}

void MyClient::slotReadyRead(){
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_6_4);
    for(;;){
        if(!m_nNextBlockSize){
            if(m_pTcpSocket->bytesAvailable()<sizeof(quint16)){
                break;
            }
            in >> m_nNextBlockSize;
        }
        if(m_pTcpSocket->bytesAvailable()<m_nNextBlockSize){
            break;
        }
        QTime time;
        QString str;
        in >> time >> str;
        m_ptxtInfo->append(time.toString()+" "+str);
        m_nNextBlockSize=0;
    }
}

void MyClient::slotError(QAbstractSocket::SocketError err){
    QString strError="Error: "+(err==QAbstractSocket::HostNotFoundError ? "The host was not found." : err==QAbstractSocket::RemoteHostClosedError ? "The remote host is closed." : err==QAbstractSocket::ConnectionRefusedError ? "The connection was refused." : QString(m_pTcpSocket->errorString()));
    m_ptxtInfo->append(strError);
}

void MyClient::slotSendToServer(){
    QByteArray arrBlock;
    QDataStream out(&arrBlock,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_4);
    out << quint16(0) << QTime::currentTime() << m_ptxtInput->text();
    out.device()->seek(0);
    out << quint16(arrBlock.size()-sizeof(quint16));
    m_pTcpSocket->write(arrBlock);
    m_ptxtInput->setText("");
}

void MyClient::slotConnected(){
    m_ptxtInfo->append("Received the connected() signal");
}