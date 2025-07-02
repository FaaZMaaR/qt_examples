#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QWidget wgt;
    QTextEdit* txted=new QTextEdit(&wgt);
    QPushButton* pb_toHtml=new QPushButton("Convert to HTML",&wgt);
    QPushButton* pb_toOdf=new QPushButton("Save to ODF",&wgt);

    QObject::connect(pb_toHtml,&QPushButton::clicked,txted,[txted]{
        txted->setHtml(txted->toPlainText());
    });

    QTextDocumentWriter writer;
    writer.setFormat("odf");
    writer.setFileName("output.odf");

    QObject::connect(pb_toOdf,&QPushButton::clicked,txted,[&]{
        writer.write(txted->document());
    });

    QVBoxLayout* pvbxLayout=new QVBoxLayout(&wgt);
    pvbxLayout->addWidget(txted);
    pvbxLayout->addWidget(pb_toHtml);
    pvbxLayout->addWidget(pb_toOdf);
    wgt.setLayout(pvbxLayout);
    wgt.show();
    return app.exec();
}