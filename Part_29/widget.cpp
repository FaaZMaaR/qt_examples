#include <widget.h>

WidgetMimeData::WidgetMimeData() : QMimeData(){}

WidgetMimeData::~WidgetMimeData(){}

QString WidgetMimeData::mimeType(){
    return "application/widget";
}

void WidgetMimeData::setWidget(QWidget* pwgt){
    m_pwgt=pwgt;
    setData(mimeType(),QByteArray());
}

QWidget* WidgetMimeData::widget()const{
    return m_pwgt;
}

WidgetDrag::WidgetDrag(QWidget* pwgtDragSource) : QDrag(pwgtDragSource){}

void WidgetDrag::setWidget(QWidget* pwgt){
    WidgetMimeData* pmd=new WidgetMimeData;
    pmd->setWidget(pwgt);
    setMimeData(pmd);
}

Widget::Widget(QWidget* pwgt) : QLabel(pwgt){
    setAcceptDrops(true);
}

void Widget::startDrag(){
    WidgetDrag* pDrag=new WidgetDrag(this);
    pDrag->setWidget(this);
    pDrag->exec(Qt::CopyAction);
}

void Widget::mousePressEvent(QMouseEvent* pe){
    if(pe->button()==Qt::LeftButton){
        m_ptDragPos=pe->pos();
    }
    QWidget::mousePressEvent(pe);
}

void Widget::mouseMoveEvent(QMouseEvent* pe){
    if(pe->buttons() & Qt::LeftButton){
        int distance=(pe->pos()-m_ptDragPos).manhattanLength();
        if(distance>QApplication::startDragDistance()){
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(pe);
}

void Widget::dragEnterEvent(QDragEnterEvent* pe){
    if(pe->mimeData()->hasFormat(WidgetMimeData::mimeType())){
        pe->acceptProposedAction();
    }
}

void Widget::dropEvent(QDropEvent* pe){
    const WidgetMimeData* pmmd=dynamic_cast<const WidgetMimeData*>(pe->mimeData());
    if(pmmd){
        QWidget* pwgt=pmmd->widget();
        QString str("Widget is dropped\nObjectName:%1");
        setText(str.arg(pwgt->objectName()));
    }
}