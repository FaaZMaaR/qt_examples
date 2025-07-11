#pragma once

#include <QtWidgets>
#include <QtNetwork>

class MyClient : public QWidget{
    Q_OBJECT

    private:
        QTcpSocket* m_pTcpSocket;
        QTextEdit* m_ptxtInfo;
        QLineEdit* m_ptxtInput;
        quint16 m_nNextBlockSize;

    public:
        MyClient(const QString& strHost,int nPort,QWidget* pwgt=nullptr);

    private slots:
        void slotReadyRead();
        void slotError(QAbstractSocket::SocketError);
        void slotSendToServer();
        void slotConnected();
};