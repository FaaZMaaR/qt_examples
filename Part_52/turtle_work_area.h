#pragma once

#include <QJSEngine>
#include "turtle.h"

class TurtleWorkArea : public QWidget{
    Q_OBJECT

    private:
        QTextEdit* m_ptxt;
        QJSEngine m_scriptEngine;
        Turtle* m_pTurtle;

    public:
        TurtleWorkArea(QWidget* pwgt=nullptr);

    private slots:
        void slotEvaluate();
        void slotApplyCode(int);
};