#include "contextmenu.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    ContextMenu conMenu;
    conMenu.resize(200,200);
    conMenu.show();
    return app.exec();
}