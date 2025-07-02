#include "jstools.h"

JSTools::JSTools(QObject* pobj) : QObject(pobj){}

void JSTools::print(const QString& str){
    qDebug() << str;
}

void JSTools::alert(const QString& strMessage){
    QMessageBox::information(0,"",strMessage);
}

void JSTools::quitApplication(){
    qApp->quit();
}

QStringList JSTools::dirEntryList(const QString& strDir,const QString& strExt){
    QDir dir(strDir);
    return dir.entryList(strExt.split(" "),QDir::Files);
}