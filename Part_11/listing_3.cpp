#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QTreeWidget twg;
    QStringList lst;
    lst << "Folders" << "Used Space";
    twg.setHeaderLabels(lst);
    twg.setSortingEnabled(true);
    QTreeWidgetItem* ptwgItem=new QTreeWidgetItem(&twg);
    ptwgItem->setText(0,"Local Disc(C)");
    ptwgItem->setIcon(0,QPixmap("drive.png"));
    QTreeWidgetItem* ptwgItemDir=nullptr;
    for(int i=0; i<20; ++i){
        ptwgItemDir=new QTreeWidgetItem(ptwgItem);
        ptwgItemDir->setText(0,"Directory"+QString::number(i));
        ptwgItemDir->setText(1,QString::number(i)+"MB");
        ptwgItemDir->setIcon(0,QPixmap("folder.png"));
    }
    ptwgItem->setExpanded(true);
    twg.resize(350,310);
    twg.show();
    return app.exec();
}