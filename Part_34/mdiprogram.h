#pragma once

#include <QtWidgets>
#include "docwindow.h"

class MDIProgram : public QMainWindow{
    Q_OBJECT

    private:
        QMdiArea* m_pma;
        QMenu* m_pmnuWindows;
        QSignalMapper* m_psigMapper;
        DocWindow* createNewDoc();
    
    public:
        MDIProgram(QWidget* pwgt=nullptr);

    signals:
        void sig_act_subwindow_triggered(QObject*);

    private slots:
        void slotChangeWindowTitle(const QString&);
        void slot_act_subwindow_triggered(bool);

    private slots:
        void slotNewDoc();
        void slotLoad();
        void slotSave();
        void slotSaveAs();
        void slotAbout();
        void slotWindows();
        void slotSetActiveSubWindow(QObject*);
};