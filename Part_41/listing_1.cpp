#include <QtSql>

static bool createConnection(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QPSQL");    
    db.setHostName("localhost");
    db.setPort(5432);
    db.setDatabaseName("qt");
    db.setUserName("postgres");
    db.setPassword("gy11ep");
    if(!db.open()){
        qDebug() << "Cannot open database: " << db.lastError();
        return false;
    }
    return true;
}

int main(int argc,char** argv){
    QCoreApplication app(argc,argv);
    if(!createConnection()){
        return -1;
    }
    QSqlQuery query;
    QString str="CREATE TABLE IF NOT EXISTS addressbook("
        "number SERIAL PRIMARY KEY,"
        "name VARCHAR(40) NOT NULL,"
        "phone VARCHAR(40) NOT NULL,"
        "email VARCHAR(40) NOT NULL"
        ");";
    if(!query.exec(str)){
        qDebug() << "Unable to create a table";
    }
    QString strF="INSERT INTO addressbook(name,phone,email) VALUES('%1','%2','%3');";
    str=strF.arg("Piggy").arg("+49 631322187").arg("piggy@mega.de");
    if(!query.exec(str)){
        qDebug() << str;
        qDebug() << "Unable to make insert operation";
    }
    str=strF.arg("Kermit").arg("+49 631322181").arg("kermit@mega.de");
    if(!query.exec(str)){
        qDebug() << "Unable to make insert operation";
    }
    if(!query.exec("SELECT * FROM addressbook;")){
        qDebug() << "Unable to execute query - exiting";
        return 1;
    }
    QSqlRecord rec=query.record();
    int nNumber=0;
    QString strName;
    QString strPhone;
    QString strEmail;
    while(query.next()){
        nNumber=query.value(rec.indexOf("number")).toInt();
        strName=query.value(rec.indexOf("name")).toString();
        strPhone=query.value(rec.indexOf("phone")).toString();
        strEmail=query.value(rec.indexOf("email")).toString();
        qDebug() << nNumber << " " << strName << ";\t" << strPhone << ";\t" << strEmail;
    }
    return 0;
}