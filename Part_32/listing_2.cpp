#include "dialogs_demo.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    DialogsDemo window;
    window.show();
    return app.exec();
}