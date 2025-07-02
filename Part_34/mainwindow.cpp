#include "mainwindow.h"

MainWindow::MainWindow(QWidget* pwgt) : QMainWindow(pwgt){
    addToolBar(Qt::TopToolBarArea,createToolBar());
    addToolBar(Qt::BottomToolBarArea,createToolBar());
    addToolBar(Qt::LeftToolBarArea,createToolBar());
    addToolBar(Qt::RightToolBarArea,createToolBar());
    setMouseTracking(true);
    m_plblX=new QLabel(this);
    m_plblY=new QLabel(this);
    statusBar()->addWidget(m_plblX);
    statusBar()->addWidget(m_plblY);
}

void MainWindow::mouseMoveEvent(QMouseEvent* pe){
    m_plblX->setText("x="+QString().setNum(pe->pos().x()));
    m_plblY->setText("y="+QString().setNum(pe->pos().y()));
}

QToolBar* MainWindow::createToolBar(){
    QToolBar* ptb=new QToolBar("Linker ToolBar");
    ptb->addAction(QPixmap("img1.png"),"1",this,&MainWindow::slotNoImpl);
    ptb->addAction(QPixmap("img2.png"),"2",this,&MainWindow::slotNoImpl);
    ptb->addSeparator();
    ptb->addAction(QPixmap("img3.png"),"3",this,&MainWindow::slotNoImpl);
    ptb->addAction(QPixmap("img4.png"),"4",this,&MainWindow::slotNoImpl);
    return ptb;
}

void MainWindow::slotNoImpl(){
    QMessageBox::information(nullptr,"Message","Not implemented");
}