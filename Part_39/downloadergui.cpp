#include "downloadergui.h"

DownloaderGui::DownloaderGui(QWidget* pwgt) : QWidget(pwgt){
    m_pdl=new Downloader(this);
    m_ppb=new QProgressBar(this);
    m_ptxt=new QLineEdit(this);
    m_pcmd=new QPushButton(tr("Go"),this);
    QString strDownloadLink="http://qt-book.com/pic.jpg";
    m_ptxt->setText(strDownloadLink);
    connect(m_pcmd,&QPushButton::clicked,this,&DownloaderGui::slotGo);
    connect(m_pdl,&Downloader::downloadProgress,this,&DownloaderGui::slotDownloadProgress);
    connect(m_pdl,&Downloader::done,this,&DownloaderGui::slotDone);
    QGridLayout* pLayout=new QGridLayout;
    pLayout->addWidget(m_ptxt,0,0);
    pLayout->addWidget(m_pcmd,0,1);
    pLayout->addWidget(m_ppb,1,0,1,2);
    setLayout(pLayout);
}

void DownloaderGui::slotGo(){
    m_pdl->download(QUrl(m_ptxt->text()));
}

void DownloaderGui::slotDownloadProgress(quint64 nReceived,quint64 nTotal){
    if(nTotal<=0){
        slotError();
        return;
    }
    m_ppb->setValue(100*nReceived/nTotal);
}

void DownloaderGui::slotDone(const QUrl& url,const QByteArray& ba){
    QString strFileName=QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)+"/"+url.path().section('/',-1);
    QFile file(strFileName);
    if(file.open(QIODevice::WriteOnly)){
        file.write(ba);
        file.close();
        if(strFileName.endsWith(".jpg") || strFileName.endsWith(".png")){
            showPic(strFileName);
        }
    }
}

void DownloaderGui::showPic(const QString& strFileName){
    QPixmap pix(strFileName);
    pix=pix.scaled(pix.size()/2,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QLabel* plbl=new QLabel;
    plbl->setPixmap(pix);
    plbl->setFixedSize(pix.size());
    plbl->show();
}

void DownloaderGui::slotError(){
    QMessageBox::critical(nullptr,tr("Error"),tr("An error while download is occured"));
}