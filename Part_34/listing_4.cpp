#include "mdiprogram.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    MDIProgram mdi;
    mdi.show();
    return app.exec();
}