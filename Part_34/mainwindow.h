#pragma once

#include <QtWidgets>

class MainWindow : public QMainWindow{
    Q_OBJECT

    private:
        QLabel* m_plblX;
        QLabel* m_plblY;

    protected:
        virtual void mouseMoveEvent(QMouseEvent* pe);

    public:
        MainWindow(QWidget* pwgt=nullptr);
        QToolBar* createToolBar();

    public slots:
        void slotNoImpl();
};