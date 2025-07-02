#pragma once

#include <QtWidgets>
#include <QtWebEngineWidgets>

class WebBrowser : public QWidget{
    Q_OBJECT

    private:
        QLineEdit* m_ptxt;
        QWebEngineView* m_pwv;
        QPushButton* m_pcmdBack;
        QPushButton* m_pcmdForward;

    public:
        WebBrowser(QWidget* pwgt=nullptr);

    private slots:
        void slotGo();
        void slotFinished(bool);
};