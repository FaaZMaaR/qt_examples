#include <QtWidgets>

int main(int argc,char** argv){
    QApplication app(argc,argv);
    QTextEdit txt;
    txt.setHtml(
        "<HTML>"
        "<BODY BGCOLOR=YELLOW>"
        "<CENTER><IMG SRC=\"image.png\"></CENTER>"
        "<H2><CENTER>Test Image</CENTER></H2>"
        "<FONT COLOR=BLUE>"
        "<P ALIGN=\"center\">"
        "<I>"
        "Sample text!<BR>"
        "Sample text!<BR>"
        "Sample text!<BR>"
        "..."
        "</I>"
        "</P>"
        "</FONT>"
        "</BODY>"
        "</HTML>"
    );
    txt.resize(320,350);
    txt.show();
    return app.exec();
}