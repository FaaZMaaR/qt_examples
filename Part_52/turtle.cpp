#include "turtle.h"

Turtle::Turtle(QWidget* pwgt) : QWidget(pwgt), m_pix(400,400), m_painter(&m_pix){
    setFixedSize(m_pix.size());
    init();
}

void Turtle::init(){
    m_pix.fill(Qt::yellow);
    m_painter.translate(rect().center());
    m_painter.rotate(-90);
}

void Turtle::paintEvent(QPaintEvent*){
    QPainter painter(this);
    painter.drawPixmap(rect(),m_pix);
}

void Turtle::forward(int n){
    m_painter.drawLine(0,0,n,0);
    m_painter.translate(n,0);
    repaint();
}

void Turtle::back(int n){
    m_painter.drawLine(0,0,-n,0);
    m_painter.translate(-n,0);
    repaint();
}

void Turtle::left(int nAngle){
    m_painter.rotate(-nAngle);
}

void Turtle::right(int nAngle){
    m_painter.rotate(nAngle);
}

void Turtle::reset(){
    m_painter.resetTransform();
    init();
    repaint();
}