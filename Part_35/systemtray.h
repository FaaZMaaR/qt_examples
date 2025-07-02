#pragma once

#include <QtWidgets>

class SystemTray : public QLabel{
    Q_OBJECT

    private:
        QSystemTrayIcon* m_ptrayIcon;
        QMenu* m_ptrayIconMenu;
        bool m_bIconSwitcher;

    protected:
        virtual void closeEvent(QCloseEvent*);

    public:
        SystemTray(QWidget* pwgt=nullptr);

    public slots:
        void slotShowHide();
        void slotShowMessage();
        void slotChangeIcon();
};