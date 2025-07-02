#pragma once

#include <QtWidgets>
#include <QtNetwork>

class MyServer : public QWidget{
    Q_OBJECT

    private:
        QTcpServer* m_ptcpServer;
        QTextEdit* m_ptxt;
        quint16 m_nNextBlockSize;

        void sendToClient(QTcpSocket* pSocket,const QString& str);

    public:
        MyServer(int nPort,QWidget* pwgt=nullptr);

    public slots:
        virtual void slotNewConnection();
        void slotReadClient();
};