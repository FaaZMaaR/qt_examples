#include "viewer.h"

Viewer::Viewer(QWidget* pwgt) : QTextEdit(pwgt){
    setWindowTitle("File System Watcher");
}

void Viewer::slotDirectoryChanged(const QString& str){
    append("Directory changed: "+str);
}

void Viewer::slotFileChanged(const QString& str){
    append("File Changed: "+str);
}