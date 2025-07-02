#pragma once

#include <QtWidgets>
#include "docwindow.h"

class SDIProgram : public QMainWindow{
    Q_OBJECT

    public:
        SDIProgram(QWidget* pwgt=nullptr);

    public slots:
        void slotAbout();
        void slotChangeWindowTitle(const QString& str);
};