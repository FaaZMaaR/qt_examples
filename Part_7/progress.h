#pragma once

#include <QWidget>

class QProgressBar;

class Progress : public QWidget{
    Q_OBJECT
    private:
        QProgressBar* m_pprb;
        int m_nStep;
    
    public:
        Progress(QWidget* pobj=nullptr);
    
    public slots:
        void slotStep();
        void slotReset();
};