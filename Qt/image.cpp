#include "image.h"
#include "ui_image.h"

Image::Image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Image)
{
    ui->setupUi(this);
}

Image::~Image()
{
    delete ui;
}

void Image::imgload(QString imgSRC)
{
    QPixmap *pixmap = new QPixmap();
    pixmap->load(imgSRC);   // 원하는 이미지 로드

    int w = ui->label_pic->width();   // label_pic의 가로값
    int h = ui->label_pic->height();  // label_pic의 세로값

    pixmap->scaled(w, h, Qt::IgnoreAspectRatio);   // 이미지 크기 조절
    ui->label_pic->setPixmap(*pixmap);   // 이미지 출력
}
