#include "downloader.h"

Downloader::Downloader(QObject* pobj) : QObject(pobj){
    m_pnam=new QNetworkAccessManager(this);
    connect(m_pnam,&QNetworkAccessManager::finished,this,&Downloader::slotFinished);
}

void Downloader::download(const QUrl& url){
    QNetworkRequest request(url);
    QNetworkReply* pnr=m_pnam->get(request);
    connect(pnr,&QNetworkReply::downloadProgress,this,&Downloader::downloadProgress);
}

void Downloader::slotFinished(QNetworkReply* pnr){
    if(pnr->error()!=QNetworkReply::NoError){
        emit error();
    }
    else{
        emit done(pnr->url(),pnr->readAll());
    }
    pnr->deleteLater();
}