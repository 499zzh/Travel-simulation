#include "map.h"
#include "ui_map.h"
#include "QMessageBox"

map::map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::map)
{
    ui->setupUi(this);
    QImage *img=new QImage;
    img->load("./image/map/my_map.png");
    ui->label->setPixmap(QPixmap::fromImage(*img));
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

map::~map()
{
    delete ui;
}

void map::new_label(){
    QLabel *p = new QLabel("new_label");
    QImage *img = new QImage;
    QString digtitle = "warning";
    QString info = QString::fromLocal8Bit("您已经在创造一个新旅客了！");
    QMessageBox::information(this, digtitle, info, QMessageBox::Ok, QMessageBox::NoButton);
    img->load("./image/traveller_icon/tr_i1.ico");
    ui->gridLayout_2->addWidget(p);
    p->setPixmap(QPixmap::fromImage(*img));
}
