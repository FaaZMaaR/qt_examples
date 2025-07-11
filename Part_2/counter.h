#pragma once

#include <qt6/QtCore/QObject>

class Counter : public QObject{
    Q_OBJECT
    private:
        int m_nValue;

    public:
        Counter();
    
    public slots:
        void slotInc();

    signals:
        void goodbye();
        void counterChanged(int);
};