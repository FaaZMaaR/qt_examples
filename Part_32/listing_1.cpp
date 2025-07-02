#include "startdialog.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    StartDialog startDialog;
    startDialog.show();
    return app.exec();
}