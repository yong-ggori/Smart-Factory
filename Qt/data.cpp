#include "data.h"
#include "ui_data.h"

Data::Data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    connect(ui->btn_home_d,SIGNAL(clicked()),this,SLOT(slotPushButton()));
    pWebView = new QWebEngineView(this);
    pWebView->load(QUrl(QStringLiteral("http://10.10.141.34/sqltable.php")));
    ui->dataL->addWidget(pWebView);
}

Data::~Data()
{
    delete ui;
}

void Data::slotPushButton()
{
//    qDebug() << "check : TEST";
    emit pushButtonSig(0);
}
