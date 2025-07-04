#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "Item3");
    QTreeView* pTreeView=new QTreeView;
    pTreeView->setModel(&model);
    QListView* pListView=new QListView;
    pListView->setModel(&model);
    QTableView* pTableView=new QTableView;
    pTableView->setModel(&model);
    QItemSelectionModel selection(&model);
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);
    QHBoxLayout* phbxLayout=new QHBoxLayout;
    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);
    wgt.setLayout(phbxLayout);
    wgt.show();
    return app.exec();
}