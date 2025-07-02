#pragma once

#include <QObject>
#include <QtNetwork>

class Downloader : public QObject{
    Q_OBJECT

    private:
        QNetworkAccessManager* m_pnam;

    public:
        Downloader(QObject* pobj=nullptr);
        void download(const QUrl&);

    signals:
        void downloadProgress(quint64,quint64);
        void done(const QUrl&,const QByteArray&);
        void error();
    
    private slots:
        void slotFinished(QNetworkReply*);
};