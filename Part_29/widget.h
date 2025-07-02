#pragma once

#include <QtWidgets>

class WidgetMimeData : public QMimeData{
    private:
        QWidget* m_pwgt;
    
    public:
        WidgetMimeData();
        virtual ~WidgetMimeData();
        static QString mimeType();
        void setWidget(QWidget* pwgt);
        QWidget* widget()const;
};

class WidgetDrag : public QDrag{
    public:
        WidgetDrag(QWidget* pwgtDragSource=nullptr);
        void setWidget(QWidget* pwgt);
};

class Widget : public QLabel{
    Q_OBJECT

    private:
        QPoint m_ptDragPos;
        void startDrag();

    protected:
        virtual void mousePressEvent(QMouseEvent*);
        virtual void mouseMoveEvent(QMouseEvent*);
        virtual void dragEnterEvent(QDragEnterEvent*);
        virtual void dropEvent(QDropEvent*);

    public:
        Widget(QWidget* pwgt=nullptr);
};