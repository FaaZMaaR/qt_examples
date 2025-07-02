#pragma once

#include <QWidget>
#include <QTouchEvent>

class MultiTouchWidget : public QWidget{
    private:
        QList<QColor> m_lstCols;
        QList<QTouchEvent::TouchPoint> m_lstTps;
    
    protected:
        virtual void paintEvent(QPaintEvent*);
        virtual bool event(QEvent*);

    public:
        MultiTouchWidget(QWidget* pwgt=nullptr);
};