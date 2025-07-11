#pragma once

#include <QTextEdit>
#include <QUdpSocket>

class UdpClient : public QTextEdit{
    Q_OBJECT

    private:
        QUdpSocket* m_pudp;

    public:
        UdpClient(QWidget* pwgt=nullptr);

    private slots:
        void slotProcessDatagrams();
};