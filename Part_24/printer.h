#pragma once

#include <QWidget>
#include <QtPrintSupport>

class Printer : public QWidget{
    Q_OBJECT

    private:
        QPrinter* m_pprinter;

    protected:
        virtual void paintEvent(QPaintEvent* pe);
        void draw(QPaintDevice* ppd);

    public:
        Printer(QWidget* pwgt=nullptr);
        virtual ~Printer();

    public slots:
        void slotPrint();
};