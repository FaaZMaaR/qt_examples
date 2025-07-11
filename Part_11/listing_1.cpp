#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QStringList lst;
    QListWidget lwg;
    QListWidgetItem* pitem=nullptr;

    lwg.setIconSize(QSize(48,48));
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str,lst){
        pitem=new QListWidgetItem(str,&lwg);
        pitem->setIcon(QPixmap(str+".jpg"));
    }
    lwg.resize(125,175);
    lwg.show();
    return app.exec();
}