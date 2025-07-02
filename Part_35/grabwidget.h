#pragma once

#include <QtWidgets>

class GrabWidget : public QWidget{
    Q_OBJECT

    private:
        QLabel* m_plbl;
        QPixmap m_pic;

    public:
        GrabWidget(QWidget* pwgt=nullptr);

    public slots:
        void slotGrabScreen();
};