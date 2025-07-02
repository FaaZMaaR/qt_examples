#include "shell.h"

Shell::Shell(QWidget* pwgt) : QWidget(pwgt){
    m_process=new QProcess(this);
    m_ptxtDisplay=new QTextEdit(this);
    QLabel* plbl=new QLabel("Command:");
    #ifdef Q_OS_WIN
        QString strCommand="dir";
    #else
        QString strCommand="ls";
    #endif
    m_ptxtCommand=new QLineEdit(strCommand,this);
    QPushButton* pcmd=new QPushButton("Enter",this);
    connect(m_process,&QProcess::readyReadStandardOutput,this,&Shell::slotDataOnStdout);
    connect(m_ptxtCommand,&QLineEdit::returnPressed,this,&Shell::slotReturnPressed);
    connect(pcmd,&QPushButton::clicked,this,&Shell::slotReturnPressed);
    QHBoxLayout* phbx=new QHBoxLayout;
    phbx->addWidget(plbl);
    phbx->addWidget(m_ptxtCommand);
    phbx->addWidget(pcmd);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(m_ptxtDisplay);
    pvbx->addLayout(phbx);
    setLayout(pvbx);
}

void Shell::slotDataOnStdout(){
    m_ptxtDisplay->append(m_process->readAllStandardOutput());
}

void Shell::slotReturnPressed(){
    QString strCommand="";
    #ifdef Q_OS_WIN
        strCommand="cmd /C ";
    #endif
    strCommand+=m_ptxtCommand->text();
    m_process->start(strCommand);
}