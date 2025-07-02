#pragma once

#include <QObject>
#include <QTimer>

class MyWorker : public QObject{
    Q_OBJECT

    private:
        int m_nValue;
        QTimer* m_ptimer;

    public:
        MyWorker(QObject* pobj=nullptr);

    signals:
        void valueChanged(int);
        void finished();

    public slots:
        void slotDoWork();

    private slots:
        void setNextValue();
};