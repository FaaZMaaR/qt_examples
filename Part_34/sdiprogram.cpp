#include "sdiprogram.h"

SDIProgram::SDIProgram(QWidget* pwgt) : QMainWindow(pwgt){
    QMenu* pmnuFile=new QMenu("File");
    QMenu* pmnuHelp=new QMenu("Help");
    DocWindow* pdoc=new DocWindow(this);
    pmnuFile->addAction("Open...",QKeySequence("CTRL+O"),pdoc,&DocWindow::slotLoad);
    pmnuFile->addAction("Save",QKeySequence("CTRL+S"),pdoc,&DocWindow::slotSave);
    pmnuFile->addAction("Save As...",pdoc,&DocWindow::slotSaveAs);
    pmnuFile->addSeparator();
    pmnuFile->addAction("Quit",QKeySequence("CTRL+Q"),qApp,&QApplication::quit);
    pmnuHelp->addAction("About",Qt::Key_F1,this,&SDIProgram::slotAbout);
    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);
    setCentralWidget(pdoc);
    connect(pdoc,&DocWindow::changeWindowTitle,this,&SDIProgram::slotChangeWindowTitle);
    statusBar()->showMessage("Ready",2000);
}

void SDIProgram::slotAbout(){
    QMessageBox::about(this,"Application","SDI Example");
}

void SDIProgram::slotChangeWindowTitle(const QString& str){
    setWindowTitle(str);
}