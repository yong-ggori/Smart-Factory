#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    connect(ui->btn_monitoring,SIGNAL(clicked()),this,SLOT(slotPushButton1()));
    connect(ui->btn_DB,SIGNAL(clicked()),this,SLOT(slotPushButton3()));
    connect(ui->btn_server,SIGNAL(clicked(bool)),this,SLOT(slotConnectToServer(bool)));

    qDebug()<<"state : " << pSocketClient->socketState;

    connect(pSocketClient,SIGNAL(sigerr(QString)),this,SLOT(geterr(QString)));
}
void Home::slotPushButton1()
{
    emit pushButtonSig(1);
}

void Home::slotPushButton3()
{
    emit pushButtonSig(2);
}

void Home::slotConnectToServer(bool check)
{
    bool bOk;
    if(check) {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk) {
            if(pSocketClient->socketState == true){
                ui->btn_monitoring->setText("실시간 모니터링");
                ui->btn_monitoring->setEnabled(pSocketClient->socketState);
                ui->btn_DB->setText("데이터 관리");
                ui->btn_DB->setEnabled(pSocketClient->socketState);
            }
        }
    }
    else {
        pSocketClient->slotClosedByServer();
        if(pSocketClient->socketState == false){
            ui->btn_server->setChecked(false);
            ui->btn_monitoring->setText("실시간 모니터링");
            ui->btn_monitoring->setEnabled(pSocketClient->socketState);
            ui->btn_DB->setText("데이터 관리");
            ui->btn_DB->setEnabled(pSocketClient->socketState);
        }
    }
}

//get err
void Home::geterr(QString err_msg){
    if(!err_msg.isEmpty()){
        ui->btn_server->setChecked(false);
        ui->btn_monitoring->setText(" ");
        ui->btn_monitoring->setEnabled(false);
        ui->btn_DB->setText(" ");
        ui->btn_DB->setEnabled(false);
    }
}
void Home::slotSocketSendData(bool check)
{
    QString strSendData = "[ALLMSG]";

    if(check) {
        strSendData += "operate";
    } else {
        strSendData += "stop";
    }

    pSocketClient->slotSocketSendData(strSendData);
}

void Home::slotSocketSendData(QString strData)
{
    pSocketClient->slotSocketSendData(strData);
}

Home::~Home()
{
    delete ui;
}
