#pragma once

#include <QWidget>

class MyApplication : public QWidget{
    Q_OBJECT

    public:
        MyApplication(QWidget* pwgt=nullptr);

    public slots:
        void slotChangeStyle(const QString& str);
};