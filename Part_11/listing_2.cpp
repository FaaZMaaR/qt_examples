#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QStringList lst;
    QListWidget lwg;
    QListWidgetItem* pitem=nullptr;

    lwg.setIconSize(QSize(48,48));
    lwg.setSelectionMode(QAbstractItemView::MultiSelection);
    lwg.setViewMode(QListView::IconMode);
    lst << "Linux" << "Windows" << "MacOSX" << "Android";
    foreach(QString str,lst){
        pitem=new QListWidgetItem(str,&lwg);
        pitem->setIcon(QPixmap(str+".jpg"));
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled);
    }
    lwg.resize(150,150);
    lwg.show();
    return app.exec();
}