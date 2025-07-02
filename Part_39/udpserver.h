#pragma once

#include <QTextEdit>
#include <QUdpSocket>

class UdpServer : public QTextEdit{
    Q_OBJECT

    private:
        QUdpSocket* m_pudp;

    public:
        UdpServer(QWidget* pwgt=nullptr);

    private slots:
        void slotSendDatagram();
};