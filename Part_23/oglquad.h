#pragma once

#include <QtOpenGLWidgets>

class OGLQuad : public QOpenGLWidget{
    protected:
        virtual void initializeGL();
        virtual void resizeGL(int nWidth,int nHeight);
        virtual void paintGL();

    public:
        OGLQuad(QWidget* pwgt=nullptr);
};