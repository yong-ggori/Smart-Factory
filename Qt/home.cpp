#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    connect(ui->btn_monitoring,SIGNAL(clicked()),this,SLOT(slotPushButton1()));
    connect(ui->btn_data,SIGNAL(clicked()),this,SLOT(slotPushButton2()));
    connect(ui->btn_data,SIGNAL(clicked()),this,SLOT(slotPushButton2()));
    connect(ui->btn_server,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer(bool)));

}
void Home::slotPushButton1()
{
//    qDebug() << "check : TEST";
    emit pushButtonSig(1);
}

void Home::slotPushButton2()
{
//    qDebug() << "check : TEST";
    emit pushButtonSig(2);
}

void Home::slotConnectToServer(bool check)
{
    bool bOk;
    // qDebug() << "check : " << check;
    if(check) {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk) {
            ui->btn_monitoring->setText("실시간 모니터링");
            ui->btn_monitoring->setEnabled(true);
            ui->btn_data->setText("데이터 관리");
            ui->btn_data->setEnabled(true);
        }
    }
    else {
        pSocketClient->slotClosedByServer();
        ui->btn_monitoring->setText("서버연결");
        ui->btn_monitoring->setEnabled(false);
        ui->btn_data->setText("서버연결");
        ui->btn_data->setEnabled(false);
    }
}

Home::~Home()
{
    delete ui;
}
