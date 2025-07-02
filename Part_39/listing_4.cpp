#include <QApplication>
#include "udpclient.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    UdpClient udpClient;
    udpClient.show();
    return app.exec();
}