#pragma once

#include <QObject>

class MouseFilter : public QObject{
    protected:
        virtual bool eventFilter(QObject*,QEvent*);

    public:
        MouseFilter(QObject* pobj=nullptr);
};