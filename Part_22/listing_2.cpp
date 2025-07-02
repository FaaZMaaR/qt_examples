#include <QtWidgets>
#include <QtSvg>
#include <QSvgWidget>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QSvgWidget svg("svgeshka.svg");
    svg.show();
    QObject::connect(svg.renderer(),SIGNAL(repaintNeeded()),&svg,SLOT(repaint()));
    return app.exec();
}