#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QLabel* plblDisplay=new QLabel;
    plblDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    plblDisplay->setLineWidth(2);
    plblDisplay->setFixedHeight(50);
    QLabel* plblText=new QLabel("&Text:");
    QLineEdit* ptxt=new QLineEdit;
    plblText->setBuddy(ptxt);
    QObject::connect(ptxt,&QLineEdit::textChanged,plblDisplay,&QLabel::setText);
    QLabel* plblPassword=new QLabel("&Password:");
    QLineEdit* ptxtPassword=new QLineEdit;
    plblPassword->setBuddy(ptxtPassword);
    ptxtPassword->setEchoMode(QLineEdit::Password);
    QObject::connect(ptxtPassword,&QLineEdit::textChanged,plblDisplay,&QLabel::setText);
    QVBoxLayout* pvbxLayout=new QVBoxLayout;
    pvbxLayout->addWidget(plblDisplay);
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    pvbxLayout->addWidget(plblPassword);
    pvbxLayout->addWidget(ptxtPassword);
    wgt.setLayout(pvbxLayout);
    wgt.show();
    return app.exec();
}