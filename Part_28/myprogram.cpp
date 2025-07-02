#include <myprogram.h>

MyProgram::MyProgram(QWidget* pwgt) : QWidget(pwgt), m_settings("BHV","MyProgram"){
    m_plbl=new QLabel;
    m_ptxt=new QTextEdit;
    m_pcbo=new QComboBox;
    m_pchk=new QCheckBox("Disable edit");
    m_pcbo->addItem("Classic");
    m_pcbo->addItem("Borland");
    connect(m_pchk,&QCheckBox::clicked,this,&MyProgram::slotCheckBoxClicked);
    connect(m_pcbo,&QComboBox::activated,this,&MyProgram::slotComboBoxActivated);
    readSettings();
    QVBoxLayout* pvbx=new QVBoxLayout;
    QHBoxLayout* phbx=new QHBoxLayout;
    pvbx->setContentsMargins(5,5,5,5);
    phbx->setSpacing(15);
    pvbx->setSpacing(15);
    pvbx->addWidget(m_plbl);
    pvbx->addWidget(m_ptxt);
    phbx->addWidget(m_pcbo);
    phbx->addWidget(m_pchk);
    pvbx->addLayout(phbx);
    setLayout(pvbx);
}

void MyProgram::readSettings(){
    m_settings.beginGroup("/Settings");
    QString strText=m_settings.value("/text","").toString();
    int nWidth=m_settings.value("/width",width()).toInt();
    int nHeigth=m_settings.value("/height",height()).toInt();
    int nComboItem=m_settings.value("/highlight",0).toInt();
    bool bEdit=m_settings.value("/edit",false).toBool();
    m_nCounter=m_settings.value("/counter",1).toInt();
    QString str=QString().setNum(m_nCounter++);
    m_plbl->setText("This program has been started "+str+" times");
    m_ptxt->setPlainText(strText);
    resize(nWidth,nHeigth);
    m_pchk->setChecked(bEdit);
    slotCheckBoxClicked();
    m_pcbo->setCurrentIndex(nComboItem);
    slotComboBoxActivated(nComboItem);
    m_settings.endGroup();
}

MyProgram::~MyProgram(){
    writeSettings();
}

void MyProgram::writeSettings(){
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/counter",m_nCounter);
    m_settings.setValue("/text",m_ptxt->toPlainText());
    m_settings.setValue("/width",width());
    m_settings.setValue("/height",height());
    m_settings.setValue("/highlight",m_pcbo->currentIndex());
    m_settings.setValue("/edit",m_pchk->isChecked());
    m_settings.endGroup();
}

void MyProgram::slotCheckBoxClicked(){
    m_ptxt->setEnabled(!m_pchk->isChecked());
}

void MyProgram::slotComboBoxActivated(int n){
    QPalette pal=m_ptxt->palette();
    pal.setColor(QPalette::Active,QPalette::Base,n ? Qt::darkBlue : Qt::white);
    pal.setColor(QPalette::Active,QPalette::Text,n ? Qt::yellow : Qt::black);
    m_ptxt->setPalette(pal);
}