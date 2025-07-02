#pragma once

#include <QtWidgets>
#include <QtPrintSupport>

class DialogsDemo : public QWidget{
    Q_OBJECT

    private:
        QPushButton* pb_openFileDialog;
        QPushButton* pb_openPrintDialog;
        QPushButton* pb_openColorDialog;
        QPushButton* pb_openFontDialog;
        QPushButton* pb_openInputDialog;
        QPushButton* pb_openProgressDialog;
        QPushButton* pb_openWizard;

        QPushButton* pb_openMessage;
        QPushButton* pb_openInfoMessage;
        QPushButton* pb_openWarnMessage;
        QPushButton* pb_openCritMessage;
        QPushButton* pb_openAboutMessage;
        QPushButton* pb_openQtMessage;
        QPushButton* pb_openErrorMessage;

    public:
        DialogsDemo(QWidget* parent=nullptr);

    public slots:
        void slot_open_file_dialog();
        void slot_open_print_dialog();
        void slot_open_color_dialog();
        void slot_open_font_dialog();
        void slot_open_input_dialog();
        void slot_open_progress_dialog();
        void slot_open_wizard();
        void slot_open_message();
        void slot_open_info_message();
        void slot_open_warn_message();
        void slot_open_crit_message();
        void slot_open_about_message();
        void slot_open_qt_message();
        void slot_open_error_message();
};

class Wizard : public QWizard{
    private:
        QWizardPage* createPage(QWidget* pwgt,QString strTitle);
    
    public:
        Wizard(QWidget* pwgt=nullptr);
};