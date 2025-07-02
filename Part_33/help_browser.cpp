#include "help_browser.h"

HelpBrowser::HelpBrowser(const QString& strPath,const QString& strFileName,QWidget* pwgt) : QWidget(pwgt){
    QPushButton* pcmdBack=new QPushButton("<<");
    QPushButton* pcmdHome=new QPushButton("Home");
    QPushButton* pcmdForward=new QPushButton(">>");
    QTextBrowser* ptxtBrowser=new QTextBrowser;
    connect(pcmdBack,&QPushButton::clicked,ptxtBrowser,&QTextBrowser::backward);
    connect(pcmdHome,&QPushButton::clicked,ptxtBrowser,&QTextBrowser::home);
    connect(pcmdForward,&QPushButton::clicked,ptxtBrowser,&QTextBrowser::forward);
    connect(ptxtBrowser,&QTextBrowser::backwardAvailable,pcmdBack,&QPushButton::setEnabled);
    connect(ptxtBrowser,&QTextBrowser::forwardAvailable,pcmdForward,&QPushButton::setEnabled);
    ptxtBrowser->setSearchPaths(QStringList() << strPath);
    ptxtBrowser->setSource(QString(strFileName));
    QVBoxLayout* pvbx=new QVBoxLayout;
    QHBoxLayout* phbx=new QHBoxLayout;
    phbx->addWidget(pcmdBack);
    phbx->addWidget(pcmdHome);
    phbx->addWidget(pcmdForward);
    pvbx->addLayout(phbx);
    pvbx->addWidget(ptxtBrowser);
    setLayout(pvbx);
}