#include "inputdialog.h"

InputDialog::InputDialog(QWidget* pwgt) : QDialog(pwgt,Qt::WindowTitleHint | Qt::WindowSystemMenuHint){
    m_ptxtFirstName=new QLineEdit;
    m_ptxtLastName=new QLineEdit;
    QLabel* plblFirstName=new QLabel("First Name");
    QLabel* plblLastName=new QLabel("Last Name");
    QPushButton* pcmdOk=new QPushButton("Ok");
    QPushButton* pcmdCancel=new QPushButton("Cancel");
    connect(pcmdOk,&QPushButton::clicked,this,&QDialog::accept);
    connect(pcmdCancel,&QPushButton::clicked,this,&QDialog::reject);
    QGridLayout* ptop=new QGridLayout;
    ptop->addWidget(plblFirstName,0,0);
    ptop->addWidget(plblLastName,1,0);
    ptop->addWidget(m_ptxtFirstName,0,1);
    ptop->addWidget(m_ptxtLastName,1,1);
    ptop->addWidget(pcmdOk,2,0);
    ptop->addWidget(pcmdCancel,2,1);
    setLayout(ptop);
}

QString InputDialog::firstName()const{
    return m_ptxtFirstName->text();
}

QString InputDialog::lastName()const{
    return m_ptxtLastName->text();
}