#pragma once

#include "inputdialog.h"

class StartDialog : public QPushButton{
    Q_OBJECT

    public:
        StartDialog(QWidget* pwgt=nullptr);

    public slots:
        void slotButtonClicked();
};