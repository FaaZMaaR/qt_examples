#pragma once

#include <QtWidgets>

class HelpBrowser : public QWidget{
    Q_OBJECT

    public:
        HelpBrowser(const QString& strPath,const QString& strFileName,QWidget* pwgt=nullptr);
};