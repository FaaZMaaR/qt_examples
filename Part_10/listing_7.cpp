#include <QtWidgets>

class NameValidator : public QValidator{
    public:
        NameValidator(QObject* parent) : QValidator(parent) {}
        virtual State validate(QString& str,int& pos)const{
            QRegularExpression rxp=QRegularExpression("[0-9]");
            if(str.contains(rxp)){
                return Invalid;
            }
            return Acceptable;
        }
};

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QLabel* plblText=new QLabel("&Name (The digits will not be accepted!):");
    QLineEdit* ptxt=new QLineEdit;
    NameValidator* pnameValidator=new NameValidator(ptxt);
    ptxt->setValidator(pnameValidator);
    plblText->setBuddy(ptxt);
    QVBoxLayout* pvbxLayout=new QVBoxLayout;
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    wgt.setLayout(pvbxLayout);
    wgt.show();
    return app.exec();
}