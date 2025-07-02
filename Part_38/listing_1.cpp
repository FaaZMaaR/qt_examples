#include "shell.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    Shell shell;
    shell.show();
    return app.exec();
}