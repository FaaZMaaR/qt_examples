#pragma once

#include <QtWidgets>

class Clock : public QLabel{
    Q_OBJECT

    public:
        Clock(QWidget* pwgt=nullptr);

    public slots:
        void slotUpdateDateTime();
};