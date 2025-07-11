#include <QtWidgets>

void loadModules(QSplashScreen* psplash){
    QElapsedTimer time;
    time.start();

    for(int i=0; i<100;){
        if(time.elapsed()>40){
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: "+QString::number(i)+"%",Qt::AlignHCenter | Qt::AlignBottom,Qt::red);
        qApp->processEvents();
    }
}

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QSplashScreen splash(QPixmap("img.jpg"));
    splash.show();
    QLabel lbl("<H1><CENTER>My Application<BR>Is Ready!</CENTER></H1>");
    loadModules(&splash);
    splash.finish(&lbl);
    lbl.resize(250,250);
    lbl.show();
    return app.exec();
}