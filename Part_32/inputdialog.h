#pragma once

#include <QtWidgets>

class InputDialog : public QDialog{
    Q_OBJECT

    private:
        QLineEdit* m_ptxtFirstName;
        QLineEdit* m_ptxtLastName;

    public:
        InputDialog(QWidget* pwgt=nullptr);
        QString firstName()const;
        QString lastName()const;
};