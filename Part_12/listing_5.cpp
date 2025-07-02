#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QSplitter spl(Qt::Horizontal);
    QFileSystemModel model;
    model.setRootPath(QDir::rootPath());
    QTreeView* pTreeView=new QTreeView;
    pTreeView->setModel(&model);
    QTableView* pTableView=new QTableView;
    pTableView->setModel(&model);
    QObject::connect(pTreeView,&QTreeView::clicked,pTableView,&QTableView::setRootIndex);
    QObject::connect(pTableView,&QTableView::activated,pTreeView,&QTreeView::setCurrentIndex);
    QObject::connect(pTableView,&QTableView::activated,pTableView,&QTableView::setRootIndex);
    spl.addWidget(pTreeView);
    spl.addWidget(pTableView);
    spl.show();
    return app.exec();
}