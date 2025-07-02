#include <mouse_observer.h>

MouseObserver::MouseObserver(QWidget* pwgt) : QLabel(pwgt){
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button)");
}

void MouseObserver::mousePressEvent(QMouseEvent* pe){
    dumpEvent(pe,"Mouse Pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent* pe){
    dumpEvent(pe,"Mouse Released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent* pe){
    dumpEvent(pe,"Mouse Is Moving");
}

void MouseObserver::dumpEvent(QMouseEvent* pe,const QString& strMsg){
    setText(strMsg
        +"\nbuttons()="+buttonsInfo(pe)
        +"\nx()="+QString::number(pe->x())
        +"\ny()="+QString::number(pe->y())
        +"\nglobalX()="+QString::number(pe->globalX())
        +"\nglobalY()="+QString::number(pe->globalY())
        +"\nmodifiers()="+modifiersInfo(pe)
    );
}

QString MouseObserver::modifiersInfo(QMouseEvent* pe){
    QString strModifiers;
    if(pe->modifiers() & Qt::ShiftModifier){
        strModifiers+="Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier){
        strModifiers+="Control ";
    }
    if(pe->modifiers() & Qt::AltModifier){
        strModifiers+="Alt";
    }
    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent* pe){
    QString strButtons;
    if(pe->buttons() & Qt::LeftButton){
        strButtons+="Left ";
    }
    if(pe->buttons() & Qt::RightButton){
        strButtons+="Right ";
    }
    if(pe->buttons() & Qt::MiddleButton){
        strButtons+="Middle";
    }
    return strButtons;
}