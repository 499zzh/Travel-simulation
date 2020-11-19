/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *source;
    QComboBox *source_box;
    QLabel *travel_s;
    QRadioButton *btntravel_s1;
    QRadioButton *btntrave_s2;
    QRadioButton *btntravel_s3;
    QRadioButton *btntravel_s4;
    QLabel *destination;
    QComboBox *destination_box;
    QLabel *label_string1;
    QLabel *time_label;
    QLineEdit *time_input;
    QPushButton *new_traveller;
    QPushButton *new_tr_isok;
    QPushButton *new_tr_iscan;
    QGroupBox *groupBox_3;
    QPushButton *check_all;
    QLineEdit *check_sb2;
    QLabel *check_sb3;
    QPushButton *check_sb;
    QLabel *check_sb1;
    QPushButton *pause;
    QPushButton *start;
    QPushButton *output_log;
    QPushButton *go_on;
    QLabel *beisu;
    QRadioButton *x1;
    QRadioButton *x2;
    QRadioButton *x5;
    QRadioButton *x10;
    QGroupBox *groupBox_2;
    QLabel *now_time;
    QLabel *now_year;
    QLabel *now_month;
    QLabel *now_day;
    QLabel *now_hour;
    QLabel *now_time2;
    QLabel *now_traveller_num;
    QLabel *now_traveller2;
    QLabel *now_traveller1;
    QLineEdit *year;
    QLineEdit *month;
    QLineEdit *day;
    QLineEdit *hour;
    QLineEdit *travel_num;
    QTextEdit *textEdit;
    QGroupBox *groupBox_4;
    QLabel *map;
    QLabel *heb_icon;
    QLabel *sy_icon;
    QLabel *bj_icon;
    QLabel *xa_icon;
    QLabel *cd_icon;
    QLabel *gz_icon;
    QLabel *wh_icon;
    QLabel *nj_icon;
    QLabel *sh_icon;
    QLabel *hz_icon;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1093, 748);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 590, 891, 101));
        source = new QLabel(groupBox);
        source->setObjectName(QString::fromUtf8("source"));
        source->setGeometry(QRect(10, 10, 72, 15));
        source_box = new QComboBox(groupBox);
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->addItem(QString());
        source_box->setObjectName(QString::fromUtf8("source_box"));
        source_box->setGeometry(QRect(70, 10, 87, 22));
        travel_s = new QLabel(groupBox);
        travel_s->setObjectName(QString::fromUtf8("travel_s"));
        travel_s->setGeometry(QRect(190, 20, 72, 15));
        btntravel_s1 = new QRadioButton(groupBox);
        btntravel_s1->setObjectName(QString::fromUtf8("btntravel_s1"));
        btntravel_s1->setGeometry(QRect(290, 20, 115, 19));
        btntrave_s2 = new QRadioButton(groupBox);
        btntrave_s2->setObjectName(QString::fromUtf8("btntrave_s2"));
        btntrave_s2->setGeometry(QRect(290, 60, 115, 19));
        btntravel_s3 = new QRadioButton(groupBox);
        btntravel_s3->setObjectName(QString::fromUtf8("btntravel_s3"));
        btntravel_s3->setGeometry(QRect(410, 20, 191, 19));
        btntravel_s4 = new QRadioButton(groupBox);
        btntravel_s4->setObjectName(QString::fromUtf8("btntravel_s4"));
        btntravel_s4->setGeometry(QRect(410, 60, 221, 19));
        destination = new QLabel(groupBox);
        destination->setObjectName(QString::fromUtf8("destination"));
        destination->setGeometry(QRect(10, 60, 72, 15));
        destination_box = new QComboBox(groupBox);
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->addItem(QString());
        destination_box->setObjectName(QString::fromUtf8("destination_box"));
        destination_box->setGeometry(QRect(70, 60, 87, 22));
        label_string1 = new QLabel(groupBox);
        label_string1->setObjectName(QString::fromUtf8("label_string1"));
        label_string1->setGeometry(QRect(610, 10, 171, 16));
        time_label = new QLabel(groupBox);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(630, 30, 51, 16));
        time_input = new QLineEdit(groupBox);
        time_input->setObjectName(QString::fromUtf8("time_input"));
        time_input->setGeometry(QRect(690, 30, 71, 21));
        new_traveller = new QPushButton(groupBox);
        new_traveller->setObjectName(QString::fromUtf8("new_traveller"));
        new_traveller->setGeometry(QRect(190, 50, 71, 28));
        new_tr_isok = new QPushButton(groupBox);
        new_tr_isok->setObjectName(QString::fromUtf8("new_tr_isok"));
        new_tr_isok->setGeometry(QRect(630, 60, 71, 28));
        new_tr_iscan = new QPushButton(groupBox);
        new_tr_iscan->setObjectName(QString::fromUtf8("new_tr_iscan"));
        new_tr_iscan->setGeometry(QRect(720, 60, 61, 28));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(890, 0, 191, 261));
        check_all = new QPushButton(groupBox_3);
        check_all->setObjectName(QString::fromUtf8("check_all"));
        check_all->setGeometry(QRect(40, 0, 131, 28));
        check_sb2 = new QLineEdit(groupBox_3);
        check_sb2->setObjectName(QString::fromUtf8("check_sb2"));
        check_sb2->setGeometry(QRect(60, 40, 61, 21));
        check_sb3 = new QLabel(groupBox_3);
        check_sb3->setObjectName(QString::fromUtf8("check_sb3"));
        check_sb3->setGeometry(QRect(130, 40, 51, 21));
        check_sb = new QPushButton(groupBox_3);
        check_sb->setObjectName(QString::fromUtf8("check_sb"));
        check_sb->setGeometry(QRect(0, 30, 41, 31));
        check_sb1 = new QLabel(groupBox_3);
        check_sb1->setObjectName(QString::fromUtf8("check_sb1"));
        check_sb1->setGeometry(QRect(40, 40, 21, 21));
        pause = new QPushButton(groupBox_3);
        pause->setObjectName(QString::fromUtf8("pause"));
        pause->setGeometry(QRect(10, 220, 71, 28));
        start = new QPushButton(groupBox_3);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(60, 77, 71, 31));
        output_log = new QPushButton(groupBox_3);
        output_log->setObjectName(QString::fromUtf8("output_log"));
        output_log->setGeometry(QRect(60, 180, 71, 28));
        go_on = new QPushButton(groupBox_3);
        go_on->setObjectName(QString::fromUtf8("go_on"));
        go_on->setGeometry(QRect(110, 220, 71, 28));
        beisu = new QLabel(groupBox_3);
        beisu->setObjectName(QString::fromUtf8("beisu"));
        beisu->setGeometry(QRect(10, 120, 31, 16));
        x1 = new QRadioButton(groupBox_3);
        x1->setObjectName(QString::fromUtf8("x1"));
        x1->setGeometry(QRect(50, 120, 41, 19));
        x2 = new QRadioButton(groupBox_3);
        x2->setObjectName(QString::fromUtf8("x2"));
        x2->setGeometry(QRect(120, 120, 41, 20));
        x5 = new QRadioButton(groupBox_3);
        x5->setObjectName(QString::fromUtf8("x5"));
        x5->setGeometry(QRect(50, 150, 41, 19));
        x10 = new QRadioButton(groupBox_3);
        x10->setObjectName(QString::fromUtf8("x10"));
        x10->setGeometry(QRect(120, 150, 51, 20));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(890, 260, 191, 171));
        now_time = new QLabel(groupBox_2);
        now_time->setObjectName(QString::fromUtf8("now_time"));
        now_time->setGeometry(QRect(10, 10, 72, 15));
        now_year = new QLabel(groupBox_2);
        now_year->setObjectName(QString::fromUtf8("now_year"));
        now_year->setGeometry(QRect(60, 40, 16, 21));
        now_month = new QLabel(groupBox_2);
        now_month->setObjectName(QString::fromUtf8("now_month"));
        now_month->setGeometry(QRect(110, 40, 16, 21));
        now_day = new QLabel(groupBox_2);
        now_day->setObjectName(QString::fromUtf8("now_day"));
        now_day->setGeometry(QRect(160, 40, 21, 21));
        now_hour = new QLabel(groupBox_2);
        now_hour->setObjectName(QString::fromUtf8("now_hour"));
        now_hour->setGeometry(QRect(70, 90, 21, 21));
        now_time2 = new QLabel(groupBox_2);
        now_time2->setObjectName(QString::fromUtf8("now_time2"));
        now_time2->setGeometry(QRect(10, 70, 72, 15));
        now_traveller_num = new QLabel(groupBox_2);
        now_traveller_num->setObjectName(QString::fromUtf8("now_traveller_num"));
        now_traveller_num->setGeometry(QRect(10, 110, 81, 16));
        now_traveller2 = new QLabel(groupBox_2);
        now_traveller2->setObjectName(QString::fromUtf8("now_traveller2"));
        now_traveller2->setGeometry(QRect(90, 140, 91, 16));
        now_traveller1 = new QLabel(groupBox_2);
        now_traveller1->setObjectName(QString::fromUtf8("now_traveller1"));
        now_traveller1->setGeometry(QRect(10, 140, 51, 16));
        year = new QLineEdit(groupBox_2);
        year->setObjectName(QString::fromUtf8("year"));
        year->setGeometry(QRect(0, 40, 61, 21));
        month = new QLineEdit(groupBox_2);
        month->setObjectName(QString::fromUtf8("month"));
        month->setGeometry(QRect(80, 40, 31, 21));
        day = new QLineEdit(groupBox_2);
        day->setObjectName(QString::fromUtf8("day"));
        day->setGeometry(QRect(130, 40, 31, 21));
        hour = new QLineEdit(groupBox_2);
        hour->setObjectName(QString::fromUtf8("hour"));
        hour->setGeometry(QRect(20, 90, 41, 21));
        travel_num = new QLineEdit(groupBox_2);
        travel_num->setObjectName(QString::fromUtf8("travel_num"));
        travel_num->setGeometry(QRect(60, 140, 31, 21));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(890, 430, 191, 251));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 881, 591));
        map = new QLabel(groupBox_4);
        map->setObjectName(QString::fromUtf8("map"));
        map->setGeometry(QRect(0, 0, 881, 591));
        heb_icon = new QLabel(groupBox_4);
        heb_icon->setObjectName(QString::fromUtf8("heb_icon"));
        heb_icon->setGeometry(QRect(760, 130, 51, 41));
        sy_icon = new QLabel(groupBox_4);
        sy_icon->setObjectName(QString::fromUtf8("sy_icon"));
        sy_icon->setGeometry(QRect(720, 215, 51, 41));
        bj_icon = new QLabel(groupBox_4);
        bj_icon->setObjectName(QString::fromUtf8("bj_icon"));
        bj_icon->setGeometry(QRect(540, 260, 51, 41));
        xa_icon = new QLabel(groupBox_4);
        xa_icon->setObjectName(QString::fromUtf8("xa_icon"));
        xa_icon->setGeometry(QRect(450, 350, 51, 41));
        cd_icon = new QLabel(groupBox_4);
        cd_icon->setObjectName(QString::fromUtf8("cd_icon"));
        cd_icon->setGeometry(QRect(380, 420, 51, 41));
        gz_icon = new QLabel(groupBox_4);
        gz_icon->setObjectName(QString::fromUtf8("gz_icon"));
        gz_icon->setGeometry(QRect(570, 530, 41, 41));
        wh_icon = new QLabel(groupBox_4);
        wh_icon->setObjectName(QString::fromUtf8("wh_icon"));
        wh_icon->setGeometry(QRect(530, 420, 41, 41));
        nj_icon = new QLabel(groupBox_4);
        nj_icon->setObjectName(QString::fromUtf8("nj_icon"));
        nj_icon->setGeometry(QRect(620, 370, 51, 41));
        sh_icon = new QLabel(groupBox_4);
        sh_icon->setObjectName(QString::fromUtf8("sh_icon"));
        sh_icon->setGeometry(QRect(680, 400, 41, 41));
        hz_icon = new QLabel(groupBox_4);
        hz_icon->setObjectName(QString::fromUtf8("hz_icon"));
        hz_icon->setGeometry(QRect(630, 460, 41, 41));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 460, 72, 15));
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(490, 390, 72, 15));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(570, 460, 72, 15));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 570, 72, 15));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(730, 170, 72, 15));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(690, 260, 72, 15));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(630, 410, 72, 15));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(670, 430, 72, 15));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(650, 450, 72, 15));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1093, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        source->setText(QApplication::translate("MainWindow", "\345\247\213\345\217\221\345\234\260", nullptr));
        source_box->setItemText(0, QApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        source_box->setItemText(1, QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        source_box->setItemText(2, QApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        source_box->setItemText(3, QApplication::translate("MainWindow", "\346\235\255\345\267\236", nullptr));
        source_box->setItemText(4, QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        source_box->setItemText(5, QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        source_box->setItemText(6, QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        source_box->setItemText(7, QApplication::translate("MainWindow", "\345\215\227\344\272\254", nullptr));
        source_box->setItemText(8, QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        source_box->setItemText(9, QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));

        travel_s->setText(QApplication::translate("MainWindow", "\346\227\205\350\241\214\347\255\226\347\225\245", nullptr));
        btntravel_s1->setText(QApplication::translate("MainWindow", "\351\243\216\351\231\251\346\234\200\345\260\217", nullptr));
        btntrave_s2->setText(QApplication::translate("MainWindow", "\351\231\220\346\227\266\351\243\216\351\231\251\346\234\200\345\260\217", nullptr));
        btntravel_s3->setText(QApplication::translate("MainWindow", "\351\243\216\351\231\251\346\234\200\345\260\217\357\274\210\345\220\253\344\272\244\351\200\232\345\267\245\345\205\267\357\274\211", nullptr));
        btntravel_s4->setText(QApplication::translate("MainWindow", "\351\231\220\346\227\266\351\243\216\351\231\251\346\234\200\345\260\217\357\274\210\345\220\253\344\272\244\351\200\232\345\267\245\345\205\267\357\274\211", nullptr));
        destination->setText(QApplication::translate("MainWindow", "\347\233\256\347\232\204\345\234\260", nullptr));
        destination_box->setItemText(0, QApplication::translate("MainWindow", "\345\214\227\344\272\254", nullptr));
        destination_box->setItemText(1, QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        destination_box->setItemText(2, QApplication::translate("MainWindow", "\345\271\277\345\267\236", nullptr));
        destination_box->setItemText(3, QApplication::translate("MainWindow", "\346\235\255\345\267\236", nullptr));
        destination_box->setItemText(4, QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        destination_box->setItemText(5, QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        destination_box->setItemText(6, QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        destination_box->setItemText(7, QApplication::translate("MainWindow", "\345\215\227\344\272\254", nullptr));
        destination_box->setItemText(8, QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        destination_box->setItemText(9, QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));

        label_string1->setText(QApplication::translate("MainWindow", "  \351\231\220\346\227\266\347\255\226\347\225\245\347\232\204\346\227\266\351\227\264\351\231\220\345\210\266", nullptr));
        time_label->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264/h", nullptr));
        new_traveller->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\227\205\345\256\242", nullptr));
        new_tr_isok->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        new_tr_iscan->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        groupBox_3->setTitle(QString());
        check_all->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\275\223\345\211\215\346\211\200\346\234\211\346\227\205\345\256\242", nullptr));
        check_sb3->setText(QApplication::translate("MainWindow", "\344\275\215\346\227\205\345\256\242", nullptr));
        check_sb->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        check_sb1->setText(QApplication::translate("MainWindow", "\347\254\254", nullptr));
        pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        output_log->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\346\227\245\345\277\227", nullptr));
        go_on->setText(QApplication::translate("MainWindow", "\347\273\247\347\273\255", nullptr));
        beisu->setText(QApplication::translate("MainWindow", "\345\200\215\351\200\237", nullptr));
        x1->setText(QApplication::translate("MainWindow", "1x", nullptr));
        x2->setText(QApplication::translate("MainWindow", "2x", nullptr));
        x5->setText(QApplication::translate("MainWindow", "5x", nullptr));
        x10->setText(QApplication::translate("MainWindow", "10x", nullptr));
        groupBox_2->setTitle(QString());
        now_time->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\351\227\264", nullptr));
        now_year->setText(QApplication::translate("MainWindow", "\345\271\264", nullptr));
        now_month->setText(QApplication::translate("MainWindow", "\346\234\210", nullptr));
        now_day->setText(QApplication::translate("MainWindow", "\346\227\245", nullptr));
        now_hour->setText(QApplication::translate("MainWindow", "\346\227\266", nullptr));
        now_time2->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\266\345\210\273", nullptr));
        now_traveller_num->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\227\205\345\256\242\346\225\260", nullptr));
        now_traveller2->setText(QApplication::translate("MainWindow", "\344\270\252\346\227\205\345\256\242\345\234\250\346\227\205\350\241\214", nullptr));
        now_traveller1->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\234\211", nullptr));
        groupBox_4->setTitle(QString());
        map->setText(QApplication::translate("MainWindow", "map", nullptr));
        heb_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        sy_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        bj_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        xa_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        cd_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        gz_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        wh_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        nj_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        sh_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        hz_icon->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\210\220\351\203\275", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\350\245\277\345\256\211", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\255\246\346\261\211", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "   \345\271\277\345\267\236", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\346\262\210\351\230\263", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\345\215\227\344\272\254", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\344\270\212\346\265\267", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\346\235\255\345\267\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
