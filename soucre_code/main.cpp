#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.set_map();
    w.setWindowTitle(QString::fromLocal8Bit("旅行模拟控制面板"));
    w.setWindowIcon(QIcon("./image/mainicon.ico"));
    w.show();
    return a.exec();
}
