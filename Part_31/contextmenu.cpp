#include "contextmenu.h"

ContextMenu::ContextMenu(QWidget* pwgt) : QTextEdit(pwgt){
    setReadOnly(true);
    m_pmnu=new QMenu(this);
    m_pmnu->addAction("Red");
    m_pmnu->addAction("Green");
    m_pmnu->addAction("Blue");
    connect(m_pmnu,&QMenu::triggered,this,&ContextMenu::slotActivated);
}

void ContextMenu::contextMenuEvent(QContextMenuEvent* pe){
    m_pmnu->exec(pe->globalPos());
}

void ContextMenu::slotActivated(QAction* pAction){
    QString strColor=pAction->text().remove("&");
    setHtml(QString("<BODY BGCOLOR=%1></BODY>").arg(strColor));
}