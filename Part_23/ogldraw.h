#pragma once

#include <QtOpenGLWidgets>

class OGLDraw : public QOpenGLWidget{
    protected:
        virtual void initializeGL();
        virtual void resizeGL(int nWidth,int nHeight);
        virtual void paintGL();
    
    public:
        OGLDraw(QWidget* pwgt=nullptr);
        void draw(int xOffset,int yOffset,GLenum type);
};