#include <QApplication>
#include "downloadergui.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    DownloaderGui downloader;
    downloader.show();
    downloader.resize(280,100);
    return app.exec();
}