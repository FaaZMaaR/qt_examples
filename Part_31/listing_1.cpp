#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QMenuBar mnuBar;
    QMenu* pmnu=new QMenu("Menu");
    pmnu->addAction("About Qt",Qt::CTRL | Qt::Key_Q,&app,&QApplication::aboutQt);
    pmnu->addSeparator();
    QAction* pCheckableAction=pmnu->addAction("CheckableItem");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);
    pmnu->addAction(QPixmap("skull.png"),"IconItem");
    QMenu* pmnuSubMenu=new QMenu("SubMenu",pmnu);
    pmnu->addMenu(pmnuSubMenu);
    pmnuSubMenu->addAction("Test");
    QAction* pDisabledAction=pmnu->addAction("DisabledItem");
    pDisabledAction->setEnabled(false);
    pmnu->addSeparator();
    pmnu->addAction("Exit",&app,&QApplication::quit);
    mnuBar.addMenu(pmnu);
    mnuBar.show();
    return app.exec();
}