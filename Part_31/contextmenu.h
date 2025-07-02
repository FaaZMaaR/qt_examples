#pragma once

#include <QtWidgets>

class ContextMenu : public QTextEdit{
    Q_OBJECT

    private:
        QMenu* m_pmnu;

    protected:
        virtual void contextMenuEvent(QContextMenuEvent* pe);

    public:
        ContextMenu(QWidget* pwgt=nullptr);

    public slots:
        void slotActivated(QAction* pAction);
};