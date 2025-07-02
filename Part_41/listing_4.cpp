#include <QtWidgets>
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
    QApplication app(argc,argv);
    if(!createConnection()){
        return -1;
    }
    QTableView view;
    QSqlRelationalTableModel model;
    model.setTable("addressbook");
    model.setRelation(0,QSqlRelation("status","number","married"));
    model.select();
    view.setModel(&model);
    view.show();
    return app.exec();
}