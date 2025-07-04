#include <QtXml>

int main(){
    QFile file("addressbook.xml");
    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader sr(&file);
        do{
            sr.readNext();
            qDebug() << sr.tokenString() << sr.name() << sr.text();
        }
        while(!sr.atEnd());
        if(sr.hasError()){
            qDebug() << "Error: " << sr.errorString();
        }
        file.close();
    }
    return 0;
}