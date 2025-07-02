#include <QtWidgets>
#include <myview.h>

class SimpleItem : public QGraphicsItem{
    private:
        enum{nPenWidth=3};

    virtual QRectF boundingRect()const{
        QPointF ptPosition(-10-nPenWidth,-10-nPenWidth);
        QSizeF size(20+nPenWidth*2,20+nPenWidth*2);
        return QRectF(ptPosition,size);
    }

    virtual void paint(QPainter* ppainter,const QStyleOptionGraphicsItem*,QWidget*){
        ppainter->save();
        ppainter->setPen(QPen(Qt::blue,nPenWidth));
        ppainter->drawEllipse(-10,-10,20,20);
        ppainter->restore();
    }

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe){
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        QGraphicsItem::mousePressEvent(pe);
    }

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pe){
        QApplication::restoreOverrideCursor();
        QGraphicsItem::mouseReleaseEvent(pe);
    }
};

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QGraphicsScene scene(QRectF(-100,-100,640,480));
    MyView* pView=new MyView(&scene);
    QPushButton* pcmdZoomIn=new QPushButton("Zoom In");
    QPushButton* pcmdZoomOut=new QPushButton("Zoom Out");
    QPushButton* pcmdRotateLeft=new QPushButton("Rotate Left");
    QPushButton* pcmdRotateRight=new QPushButton("Rotate Right");
    pView->setRenderHint(QPainter::Antialiasing,true);
    SimpleItem* pSimpleItem=new SimpleItem;
    scene.addItem(pSimpleItem);
    pSimpleItem->setPos(0,0);
    pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsPixmapItem* pPixmapItem=scene.addPixmap(QPixmap("image.png"));
    pPixmapItem->setParentItem(pSimpleItem);
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);
    QObject::connect(pcmdZoomIn,&QPushButton::clicked,pView,&MyView::slotZoomIn);
    QObject::connect(pcmdZoomOut,&QPushButton::clicked,pView,&MyView::slotZoomOut);
    QObject::connect(pcmdRotateLeft,&QPushButton::clicked,pView,&MyView::slotRotateLeft);
    QObject::connect(pcmdRotateRight,&QPushButton::clicked,pView,&MyView::slotRotateRight);
    QVBoxLayout* pvbx=new QVBoxLayout;
    pvbx->addWidget(pView);
    pvbx->addWidget(pcmdZoomIn);
    pvbx->addWidget(pcmdZoomOut);
    pvbx->addWidget(pcmdRotateLeft);
    pvbx->addWidget(pcmdRotateRight);
    wgt.setLayout(pvbx);
    wgt.show();
    return app.exec();
}