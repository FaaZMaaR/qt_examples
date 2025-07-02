#include "sdiprogram.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    SDIProgram sdi;
    sdi.show();
    return app.exec();
}