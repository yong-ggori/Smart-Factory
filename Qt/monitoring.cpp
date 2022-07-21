#include "monitoring.h"
#include "ui_monitoring.h"

Monitoring::Monitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitoring)
{
    ui->setupUi(this);
    imgload();   // 함수 호출
    connect(ui->btn_home_m,SIGNAL(clicked()),this,SLOT(slotPushButton()));
}

Monitoring::~Monitoring()
{
    delete ui;
}

void Monitoring::imgload() {   // Label에 이미지를 출력하기 위한 함수
    QPixmap *pixmap = new QPixmap();
    pixmap->load("C:/Users/KCCI03/Desktop/img/img1");   // 원하는 이미지 로드

    int w = ui->label_pic->width();   // label_pic의 가로값
    int h = ui->label_pic->height();  // label_pic의 세로값

    pixmap->scaled(w, h, Qt::IgnoreAspectRatio);   // 이미지 크기 조절
    ui->label_pic->setPixmap(*pixmap);   // 이미지 출력

    //QPixmap pix("C:/Users/KCCI03/Desktop/img/img1");
    //ui->label_pic->setPixmap(pix);
}

void Monitoring::slotPushButton()
{
//    qDebug() << "check : TEST";
    emit pushButtonSig(0);
}
