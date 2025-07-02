#include "mdiprogram.h"

MDIProgram::MDIProgram(QWidget* pwgt) : QMainWindow(pwgt){
    QAction* pactNew=new QAction("New File",this);
    pactNew->setText("New");
    pactNew->setShortcut(QKeySequence("CTRL+N"));
    pactNew->setToolTip("New Document");
    pactNew->setWhatsThis("Create a new file");
    pactNew->setStatusTip("Create a new file");
    pactNew->setIcon(QPixmap("img1.png"));
    connect(pactNew,&QAction::triggered,this,&MDIProgram::slotNewDoc);

    QAction* pactOpen=new QAction("Open File",this);
    pactOpen->setText("Open...");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Open Document");
    pactOpen->setWhatsThis("Open an existing file");
    pactOpen->setStatusTip("Open an existing file");
    pactOpen->setIcon(QPixmap("img2.png"));
    connect(pactOpen,&QAction::triggered,this,&MDIProgram::slotLoad);

    QAction* pactSave=new QAction("Save File",this);
    pactSave->setText("Save");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Save Document");
    pactSave->setWhatsThis("Save the file to disk");
    pactSave->setStatusTip("Save the file to disk");
    pactSave->setIcon(QPixmap("img3.png"));
    connect(pactSave,&QAction::triggered,this,&MDIProgram::slotSave);

    QToolBar* ptbFile=new QToolBar("File Operation",this);
    ptbFile->addAction(pactNew);
    ptbFile->addAction(pactOpen);
    ptbFile->addAction(pactSave);
    addToolBar(Qt::TopToolBarArea,ptbFile);

    QMenu* pmnuFile=new QMenu("File",this);
    pmnuFile->addAction(pactNew);
    pmnuFile->addAction(pactOpen);
    pmnuFile->addAction(pactSave);
    pmnuFile->addAction("Save As...",this,&MDIProgram::slotSaveAs);
    pmnuFile->addSeparator();
    pmnuFile->addAction("Quit",QKeySequence("CTRL+Q"),qApp,&QApplication::quit);
    menuBar()->addMenu(pmnuFile);

    m_pmnuWindows=new QMenu("Windows",this);
    menuBar()->addMenu(m_pmnuWindows);
    connect(m_pmnuWindows,&QMenu::aboutToShow,this,&MDIProgram::slotWindows);
    menuBar()->addSeparator();

    QMenu* pmnuHelp=new QMenu("Help",this);
    pmnuHelp->addAction("About",Qt::Key_F1,this,&MDIProgram::slotAbout);
    menuBar()->addMenu(pmnuHelp);

    m_pma=new QMdiArea(this);
    m_pma->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    m_pma->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setCentralWidget(m_pma);

    m_psigMapper=new QSignalMapper(this);
    connect(m_psigMapper,&QSignalMapper::mappedObject,this,&MDIProgram::slotSetActiveSubWindow);

    statusBar()->showMessage("Ready",3000);
}

void MDIProgram::slotNewDoc(){
    createNewDoc()->show();
}

DocWindow* MDIProgram::createNewDoc(){
    DocWindow* pdoc=new DocWindow(this);
    m_pma->addSubWindow(pdoc);
    pdoc->setAttribute(Qt::WA_DeleteOnClose);
    pdoc->setWindowTitle("Unnamed Document");
    pdoc->setWindowIcon(QPixmap("img4.png"));
    connect(pdoc,&DocWindow::changeWindowTitle,this,&MDIProgram::slotChangeWindowTitle);
    return pdoc;
}

void MDIProgram::slotChangeWindowTitle(const QString& str){
    qobject_cast<DocWindow*>(sender())->setWindowTitle(str);
}

void MDIProgram::slotLoad(){
    DocWindow* pdoc=createNewDoc();
    pdoc->slotLoad();
    pdoc->show();
}

void MDIProgram::slotSave(){
    DocWindow* pdoc=qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if(pdoc){
        pdoc->slotSave();
    }
}

void MDIProgram::slotSaveAs(){
    DocWindow* pdoc=qobject_cast<DocWindow*>(m_pma->activeSubWindow());
    if(pdoc){
        pdoc->slotSaveAs();
    }
}

void MDIProgram::slotAbout(){
    QMessageBox::about(this,"Application","MDI Example");
}

void MDIProgram::slotWindows(){
    m_pmnuWindows->clear();
    QAction* pact=m_pmnuWindows->addAction("Cascade",m_pma,&QMdiArea::cascadeSubWindows);
    pact->setEnabled(!m_pma->subWindowList().isEmpty());
    pact=m_pmnuWindows->addAction("Tile",m_pma,&QMdiArea::tileSubWindows);
    pact->setEnabled(!m_pma->subWindowList().isEmpty());
    m_pmnuWindows->addSeparator();
    QList<QMdiSubWindow*> listDoc=m_pma->subWindowList();
    for(int i=0; i<listDoc.size(); ++i){
        pact=m_pmnuWindows->addAction(listDoc.at(i)->windowTitle());
        pact->setCheckable(true);
        pact->setChecked(m_pma->activeSubWindow()==listDoc.at(i));
        connect(pact,&QAction::triggered,m_psigMapper,qOverload<>(&QSignalMapper::map));
        m_psigMapper->setMapping(pact,listDoc.at(i));
    }
}

void MDIProgram::slotSetActiveSubWindow(QObject* pwgt){
    if(pwgt){
        m_pma->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(pwgt));
    }
}

void MDIProgram::slot_act_subwindow_triggered(bool){
    QString swtitle=qobject_cast<QAction*>(sender())->text();
    for(QMdiSubWindow* sub : m_pma->subWindowList()){
        if(swtitle==sub->windowTitle()){
            emit sig_act_subwindow_triggered(sub);
            break;
        }
    }
}