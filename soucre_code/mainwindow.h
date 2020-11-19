#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void set_map();
    //设置地图
    ~MainWindow();

private slots:

    int on_btntravel_clicked();
    //选择旅行策略
    void on_check_all_clicked();
    //查询当前所有旅客情况
    void on_check_sb_clicked();
    //查询某个指定旅客
    void on_start_clicked();
    //开始模拟
    void show_time();
    //显示时间
    void delay_(int msec);
    //sleep函数
    void on_new_traveller_clicked();
    //进入新建旅客状态
    void on_new_tr_isok_clicked();
    //确定建立旅客
    void on_new_tr_iscan_clicked();
    //取消建立旅客
    void on_pause_clicked();
    //暂停
    void on_go_on_clicked();
    //继续
    int on_x_clicked();
    //倍速
    void on_output_log_clicked();
    //输出日志

private:
    Ui::MainWindow *ui;
    void change_passenger();
};
#endif // MAINWINDOW_H
