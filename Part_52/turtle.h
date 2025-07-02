#pragma once

#include <QtWidgets>

class Turtle : public QWidget{
    Q_OBJECT

    private:
        QPixmap m_pix;
        QPainter m_painter;

    public:
        Turtle(QWidget* pwgt=nullptr);

    protected:
        void init();
        virtual void paintEvent(QPaintEvent*);

    public slots:
        void forward(int n);
        void back(int n);
        void left(int nAngle);
        void right(int nAngle);
        void reset();
};