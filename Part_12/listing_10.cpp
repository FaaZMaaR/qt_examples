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
    lwg.setWindowTitle("ListWidget");
    lwg.show();
    QListView listView;
    listView.setModel(lwg.model());
    listView.setSelectionModel(lwg.selectionModel());
    listView.setWindowTitle("ListView");
    listView.show();
    return app.exec();
}