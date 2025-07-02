#pragma once

#include <QtWidgets>

class Shell : public QWidget{
    Q_OBJECT

    private:
        QProcess* m_process;
        QLineEdit* m_ptxtCommand;
        QTextEdit* m_ptxtDisplay;

    public:
        Shell(QWidget* pwgt=nullptr);

    public slots:
        void slotDataOnStdout();
        void slotReturnPressed();
};