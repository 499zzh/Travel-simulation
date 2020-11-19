#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

#include<QTime>
#include<QFile>
#include<QTextStream>
#include<passenger.h>
#include<get_table.h>


static int my_passenger = 0;
//乘客数量
static int lock = 0;
//控制程序
static int is_start = 0;
//是否开始
static int is_pause = 0;
//是否暂停
static QString log_time;
//供日志使用的字符串形式的时间
static Passenger P[MAX_PASSENGER];
//一个乘客的数组

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btntravel_s1, SIGNAL(clicked), this, SLOT(on_btntravel_clicked()));
    connect(ui->btntrave_s2, SIGNAL(clicked), this, SLOT(on_btntravel_clicked()));
    connect(ui->btntravel_s3, SIGNAL(clicked), this, SLOT(on_btntravel_clicked()));
    connect(ui->btntravel_s4, SIGNAL(clicked), this, SLOT(on_btntravel_clicked()));
    connect(ui->x1, SIGNAL(clicked), this, SLOT(on_x_clicked()));
    connect(ui->x2, SIGNAL(clicked), this, SLOT(on_x_clicked()));
    connect(ui->x5, SIGNAL(clicked), this, SLOT(on_x_clicked()));
    connect(ui->x10, SIGNAL(clicked), this, SLOT(on_x_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::on_btntravel_clicked()
{
    if(ui->btntravel_s1->isChecked())
        return DANGER_MIN_STRATEGY;
    else if(ui->btntrave_s2->isChecked())
        return PUNCTUAL_DANGER_MIN_STRATEGY;
    else if(ui->btntravel_s3->isChecked())
        return DANGER_MIN_WITH_TRANS_STRATEGY;
    else if(ui->btntravel_s4->isChecked())
        return 3;
    else
        return PUNCTUAL_DANGER_MIN_WITH_TRANS_STRATEGY;
}
//选择旅行策略，默认为风险最小
void MainWindow::on_check_all_clicked()
{
    for(int i = 0; i < my_passenger; i++){
        ui->textEdit->append(log_time + P[i].inquire_now());
    }
}
//查询当前所有旅客状态
void MainWindow::on_check_sb_clicked()
{
    QString str = ui->check_sb2->text();
    int temp = str.toInt();
    while(str == NULL || str.toInt() > MAX_PASSENGER){
        QString digtitle = "warning";
        QString info = "请输入正确序号！";
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
        str = ui->check_sb->text();
    }
    ui->textEdit->append(log_time + (P[temp - 1].inquire_plan()));
}
//查询指定旅客状态
void MainWindow::on_start_clicked()
{
    if(!is_start){
        set_time();
        get_timetable();
        get_danger();
        show_time();
        log_time = QString::number(now_year) + ":" + QString::number(now_month) + ":"
                + QString::number(now_day) + ":" + QString::number(now_hour);
        change_passenger();
        is_start = 1;
        while(1){
            for(int i = 0; i < on_x_clicked(); i++){
                while(lock || is_pause){
                    delay_(100);
                }
                delay_(100);
            }
            for(int i = 0; i < my_passenger; i++){
                if(P[i].get_status() == 0){
                    QString temp = P[i].travel();
                    if(!temp.isEmpty())
                        ui->textEdit->append(log_time + temp);
                 }
            }
            change_passenger();
            change_time();
            log_time = QString::number(now_year) + ":" + QString::number(now_month) + ":"
                    + QString::number(now_day) + ":" + QString::number(now_hour);
            show_time();
        }
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("已经开始运行了！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//开始运行
void MainWindow::show_time(){
    ui->year->setText(QString::number(now_year));
    ui->month->setText(QString::number(now_month));
    ui->day->setText(QString::number(now_day));
    ui->hour->setText(QString::number(now_hour));
}
//限时时间
void MainWindow::delay_(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
//时延函数
void MainWindow::change_passenger(){
    int count = 0;
    for(int i = 0; i < MAX_PASSENGER; i++){
        if(P[i].get_status() == 0){
            count++;
        }
    }
    ui->travel_num->setText(QString::number(count));
}
//记录，改变当前旅客数量
void MainWindow::on_new_traveller_clicked()
{
    if(is_start && lock == 0)
        lock = 1;
    else if(is_start == 0){
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先开始！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("您已经在创造一个新旅客了！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//新建旅客
void MainWindow::on_new_tr_isok_clicked()
{
    if(is_start && lock){
        if(my_passenger < MAX_PASSENGER){
            if(ui->source_box->currentIndex() ==  ui->destination_box->currentIndex()){
                QString digtitle = "warning";
                QString info = QString::fromLocal8Bit("请输入正确的始发地，目的地！");
                QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
                lock = 0;
                return;
            }
            if(on_btntravel_clicked() == 0 || on_btntravel_clicked() == 2){
                P[my_passenger].initial_a_Passenger(now_day, now_hour, ui->source_box->currentIndex(),
                                                    ui->destination_box->currentIndex(), on_btntravel_clicked(), my_passenger);
                P[my_passenger].travel_simulation_DMS(0, 0, now_hour, P[my_passenger]);
                P[my_passenger].get_plan();
            }
            else if(on_btntravel_clicked() == 1 || on_btntravel_clicked() == 3){
                QString str = ui->time_input->text();
                int max_time = str.toInt();
                QString digtitle = "warning";
                QString info = QString::fromLocal8Bit("请输入限定的时间！");
                if(max_time <= 0){
                    QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
                    QString str = ui->time_input->text();
                    max_time = str.toInt();
                    lock = 0;
                    return;
                }
                P[my_passenger].initial_a_Passenger(now_day, now_hour, ui->source_box->currentIndex(),
                                                    ui->destination_box->currentIndex(), on_btntravel_clicked(), my_passenger, max_time);
                P[my_passenger].travel_simulation_PDMS(0, 0, now_hour, 0, P[my_passenger]);
                P[my_passenger].get_plan();
            }
            QLabel *p = new QLabel(this);
            QImage *img = new QImage;
            P[my_passenger].my_label = p;
            P[my_passenger].my_label->setEnabled(true);
            QString str = "./image/traveller_icon/tr_i" + QString::number(my_passenger%13 + 1) + ".ico";
            img->load(str);
            P[my_passenger].my_label->setPixmap(QPixmap::fromImage(*img));
            P[my_passenger].my_label->setGeometry(P[my_passenger].label_pos_x(0), P[my_passenger].label_pos_y(0), 48, 48);
            P[my_passenger].my_label->show();
            ui->textEdit->append(log_time + QString::fromLocal8Bit("第") + QString::number(my_passenger + 1)
                                 + QString::fromLocal8Bit("位旅客已经生成"));
            if(P[my_passenger].get_status() == 2){
                P[my_passenger].my_label->setGeometry(0, 0, 0, 0);
            }
            my_passenger++;
        }
        else{
            QString digtitle = "warning";
            QString info = QString::fromLocal8Bit("旅客数量已满！");
            QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
        }
        lock  = 0;

        return;
    }
    else if (lock == 0){
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先点击新建旅客");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先开始！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
        return ;
    }
}
//确定
void MainWindow::on_new_tr_iscan_clicked()
{
    if(is_start && lock)
        lock = 0;
    else if(is_start == 0){
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先开始！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("您当前没有进入新建旅客状态哦！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//取消
void MainWindow::on_pause_clicked()
{
    if(is_start && is_pause == 0){
        is_pause = 1;
     }
    else if(is_start && is_pause == 1){
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("当前已经是暂停状态了！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先开始！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//暂停
void MainWindow::on_go_on_clicked()
{
    if(is_start && is_pause == 1){
        is_pause = 0;
    }
    else if(is_start == 0){
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("请先开始！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
    else{
        QString digtitle = "warning";
        QString info = QString::fromLocal8Bit("当前没有暂停哦！");
        QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    }
}
//继续
int MainWindow::on_x_clicked()
{
    if(ui->x1->isChecked())
        return 10;
    else if(ui->x2->isChecked())
        return 5;
    else if(ui->x5->isChecked())
        return 2;
    else if(ui->x10->isChecked())
        return 1;
    else
        return 10;
}
//倍速
void MainWindow::on_output_log_clicked()
{
    QFile *myFile;
    QTextStream *outfile;
    QString filename = "mylog.txt";
    myFile = new QFile(filename);
    myFile->open(QIODevice::WriteOnly | QIODevice::Text);
    outfile = new QTextStream(myFile);
    *outfile << ui->textEdit->toPlainText();
    myFile->close();
}
//输出日志
void MainWindow::set_map(){
    QImage *img = new QImage;
    img->load("./image/map/my_map.png");
    ui->map->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/bj.ico");
    ui->bj_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/sy.ico");
    ui->sy_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/heb.ico");
    ui->heb_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/xa.ico");
    ui->xa_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/sh.ico");
    ui->sh_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/gz.ico");
    ui->gz_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/hz.ico");
    ui->hz_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/cd.ico");
    ui->cd_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/nj.ico");
    ui->nj_icon->setPixmap(QPixmap::fromImage(*img));
    img->load("./image/city_icon/wh.ico");
    ui->wh_icon->setPixmap(QPixmap::fromImage(*img));
}

