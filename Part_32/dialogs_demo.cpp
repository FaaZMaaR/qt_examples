#include "dialogs_demo.h"

DialogsDemo::DialogsDemo(QWidget* parent) : QWidget(parent){
    pb_openFileDialog=new QPushButton("Open File Dialog",this);
    pb_openPrintDialog=new QPushButton("Open Print Dialog",this);
    pb_openColorDialog=new QPushButton("Open Color Dialog",this);
    pb_openFontDialog=new QPushButton("Open Font Dialog",this);
    pb_openInputDialog=new QPushButton("Open Input Dialog",this);
    pb_openProgressDialog=new QPushButton("Open Progress Dialog",this);
    pb_openWizard=new QPushButton("Open Wizard",this);
    pb_openMessage=new QPushButton("Open Message",this);
    pb_openInfoMessage=new QPushButton("Open Information Message",this);
    pb_openWarnMessage=new QPushButton("Open Warning Message",this);
    pb_openCritMessage=new QPushButton("Open Critical Message",this);
    pb_openAboutMessage=new QPushButton("Open About Message",this);
    pb_openQtMessage=new QPushButton("Open About Qt Message",this);
    pb_openErrorMessage=new QPushButton("Open Error Message",this);

    connect(pb_openFileDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_file_dialog);
    connect(pb_openPrintDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_print_dialog);
    connect(pb_openColorDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_color_dialog);
    connect(pb_openFontDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_font_dialog);
    connect(pb_openInputDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_input_dialog);
    connect(pb_openProgressDialog,&QPushButton::clicked,this,&DialogsDemo::slot_open_progress_dialog);
    connect(pb_openWizard,&QPushButton::clicked,this,&DialogsDemo::slot_open_wizard);
    connect(pb_openMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_message);
    connect(pb_openInfoMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_info_message);
    connect(pb_openWarnMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_warn_message);
    connect(pb_openCritMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_crit_message);
    connect(pb_openAboutMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_about_message);
    connect(pb_openQtMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_qt_message);
    connect(pb_openErrorMessage,&QPushButton::clicked,this,&DialogsDemo::slot_open_error_message);

    QVBoxLayout* pvbx=new QVBoxLayout(this);
    pvbx->addWidget(pb_openFileDialog);
    pvbx->addWidget(pb_openPrintDialog);
    pvbx->addWidget(pb_openColorDialog);
    pvbx->addWidget(pb_openFontDialog);
    pvbx->addWidget(pb_openInputDialog);
    pvbx->addWidget(pb_openProgressDialog);
    pvbx->addWidget(pb_openWizard);
    pvbx->addWidget(pb_openMessage);
    pvbx->addWidget(pb_openInfoMessage);
    pvbx->addWidget(pb_openWarnMessage);
    pvbx->addWidget(pb_openCritMessage);
    pvbx->addWidget(pb_openAboutMessage);
    pvbx->addWidget(pb_openQtMessage);
    pvbx->addWidget(pb_openErrorMessage);

    setLayout(pvbx);
    setWindowTitle("Dialogs Demo");
}

void DialogsDemo::slot_open_file_dialog(){
    QPixmap pix(320,200);
    QString strFilter;
    QString str=QFileDialog::getSaveFileName(this,tr("Save Pixmap"),"Pixmap","*.png ;; *.jpg ;; *.bmp",&strFilter);
    if(!str.isEmpty()){
        if(strFilter.contains("jpg")){
            pix.save(str,"JPG");
        }
        else if(strFilter.contains("bmp")){
            pix.save(str,"BMP");
        }
        else{
            pix.save(str,"PNG");
        }
    }
}

void DialogsDemo::slot_open_print_dialog(){
    QPrinter printer;
    QPrintDialog* pPrintDialog=new QPrintDialog(&printer,this);
    if(pPrintDialog->exec()==QDialog::Accepted){
        qDebug() << "QPrintDialog accepted";
    }
}

void DialogsDemo::slot_open_color_dialog(){
    QColor color=QColorDialog::getColor(Qt::blue,this);
    if(!color.isValid()){
        qDebug() << "Color is invalid";
    }
}

void DialogsDemo::slot_open_font_dialog(){
    bool bOk;
    QFont fnt=QFontDialog::getFont(&bOk,this);
    if(!bOk){
        qDebug() << "QFontDialog was canceled";
    }
}

void DialogsDemo::slot_open_input_dialog(){
    bool bOk;
    QString str=QInputDialog::getText(this,"Input","Name:",QLineEdit::Normal,"Tarja",&bOk);
    if(!bOk){
        qDebug() << "QInputDialog was canceled";
    }
}

void DialogsDemo::slot_open_progress_dialog(){
    int n=1000000;
    QProgressDialog* pprd=new QProgressDialog("Processing the data...","Cancel",0,n,this);
    pprd->setMinimumDuration(0);
    pprd->setWindowTitle("Please Wait");
    for(int i=0; i<n; ++i){
        pprd->setValue(i);
        qApp->processEvents();
        if(pprd->wasCanceled()){
            break;
        }
    }
    pprd->setValue(n);
}

void DialogsDemo::slot_open_wizard(){
    Wizard* wizard=new Wizard(this);
    wizard->exec();
}

void DialogsDemo::slot_open_message(){
    QMessageBox* pmbx=new QMessageBox(QMessageBox::Information,"MessageBox","<b>A</b> <i>Simple</i> <u>Message</u>",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,this);
    int n=pmbx->exec();
    if(n==QMessageBox::Yes){
        qDebug() << "Yes Button was pressed";
    }
}

void DialogsDemo::slot_open_info_message(){
    QMessageBox::information(this,"Information","Operation Complete");
}

void DialogsDemo::slot_open_warn_message(){
    int n=QMessageBox::warning(this,"Warning","The text in the file has changed\nDo you want to save the changes?",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
    if(n==QMessageBox::Yes){
        qDebug() << "Saving changes";
    }
}

void DialogsDemo::slot_open_crit_message(){
    int n=QMessageBox::critical(this,"Attention","This operation will make your computer unusable, continue?",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if(n==QMessageBox::Yes){
        qDebug() << "You were warned...";
    }
}

void DialogsDemo::slot_open_about_message(){
    QMessageBox::about(this,"About","My Program Ver. 1.0");
}

void DialogsDemo::slot_open_qt_message(){
    QMessageBox::aboutQt(this);
}

void DialogsDemo::slot_open_error_message(){
    (new QErrorMessage(this))->showMessage("Write Error");
}

QWizardPage* Wizard::createPage(QWidget* pwgt,QString strTitle){
    QWizardPage* ppage=new QWizardPage(this);
    ppage->setTitle(strTitle);
    QVBoxLayout* playout=new QVBoxLayout(this);
    playout->addWidget(pwgt);
    ppage->setLayout(playout);
    return ppage;
}

Wizard::Wizard(QWidget* pwgt) : QWizard(pwgt){
    addPage(createPage(new QLabel("<H1>Label 1</H1>",this),"One"));
    addPage(createPage(new QLabel("<H1>Label 2</H1>",this),"Two"));
    addPage(createPage(new QLabel("<H1>Label 3</H1>",this),"Three"));
}