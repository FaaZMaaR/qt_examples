#pragma once

#include <QtWidgets>

class JSTools : public QObject{
    Q_OBJECT

    public:
        JSTools(QObject* pobj=nullptr);

    public slots:
        void print(const QString& str);
        void alert(const QString& str);
        void quitApplication();
        QStringList dirEntryList(const QString& strDir,const QString& strExt);
};