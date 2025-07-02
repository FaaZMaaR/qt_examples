#include "turtle_work_area.h"

int main(int argc,char** argv){
    QApplication app(argc,argv);
    TurtleWorkArea turtleWorkArea;
    turtleWorkArea.show();
    return app.exec();
}