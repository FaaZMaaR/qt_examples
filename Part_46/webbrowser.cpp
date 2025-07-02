#include "webbrowser.h"

WebBrowser::WebBrowser(QWidget* pwgt) : QWidget(pwgt){
    m_ptxt=new QLineEdit("http://www.bhv.ru");
    m_pwv=new QWebEngineView;
    m_pcmdBack=new QPushButton("<");
    m_pcmdForward=new QPushButton(">");
    m_pcmdBack->setEnabled(false);
    m_pcmdForward->setEnabled(false);
    QProgressBar* pprb=new QProgressBar;
    QPushButton* pcmdGo=new QPushButton("Go");
    QPushButton* pcmdStop=new QPushButton("Stop");
    QPushButton* pcmdRefresh=new QPushButton("Refresh");
    connect(pcmdGo,&QPushButton::clicked,this,&WebBrowser::slotGo);
    connect(m_ptxt,&QLineEdit::returnPressed,this,&WebBrowser::slotGo);
    connect(m_pcmdBack,&QPushButton::clicked,m_pwv,&QWebEngineView::back);
    connect(m_pcmdForward,&QPushButton::clicked,m_pwv,&QWebEngineView::forward);
    connect(pcmdRefresh,&QPushButton::clicked,m_pwv,&QWebEngineView::reload);
    connect(pcmdStop,&QPushButton::clicked,m_pwv,&QWebEngineView::stop);
    connect(m_pwv,&QWebEngineView::loadProgress,pprb,&QProgressBar::setValue);
    connect(m_pwv,&QWebEngineView::loadFinished,this,&WebBrowser::slotFinished);
    QHBoxLayout* phbx=new QHBoxLayout;
    phbx->addWidget(m_pcmdBack);
    phbx->addWidget(m_pcmdForward);
    phbx->addWidget(pcmdStop);
    phbx->addWidget(pcmdRefresh);
    phbx->addWidget(m_ptxt);
    phbx->addWidget(pcmdGo);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addLayout(phbx);
    pvbx->addWidget(m_pwv);
    pvbx->addWidget(pprb);
    setLayout(pvbx);
    slotGo();
}

void WebBrowser::slotGo(){
    if(!m_ptxt->text().startsWith("ftp://") && !m_ptxt->text().startsWith("http://") && !m_ptxt->text().startsWith("gopher://")){
        m_ptxt->setText("http://"+m_ptxt->text());
    }
    m_pwv->load(QUrl(m_ptxt->text()));
}

void WebBrowser::slotFinished(bool bOk){
    if(!bOk){
        m_pwv->setHtml("<CENTER>An error has occured while loading the web page</CENTER>");
    }
    m_ptxt->setText(m_pwv->url().toString());
    m_pcmdBack->setEnabled(m_pwv->page()->history()->canGoBack());
    m_pcmdForward->setEnabled(m_pwv->page()->history()->canGoForward());
}