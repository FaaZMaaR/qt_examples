#include <QtWidgets>
#include <QtWebEngineWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWebEngineView webView;
    webView.load(QUrl("http://www.bhv.ru"));
    webView.show();
    return app.exec();
}