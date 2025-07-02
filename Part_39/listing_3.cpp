#include <QApplication>
#include "udpserver.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    UdpServer udpServer;
    udpServer.show();
    return app.exec();
}