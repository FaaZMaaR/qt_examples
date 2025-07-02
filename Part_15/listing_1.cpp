#include <QtWidgets>
#include <mouse_filter.h>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));
    txt.show();
    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&txt));
    lbl.show();
    QPushButton cmd("QPushButton");
    cmd.installEventFilter(new MouseFilter(&cmd));
    cmd.show();
    return app.exec();
}