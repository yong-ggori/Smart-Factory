#include "monitoring.h"
#include "ui_monitoring.h"

Monitoring::Monitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitoring)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    connect(ui->btn_home_m,SIGNAL(clicked()),this,SLOT(slotPushButton()));
    connect(ui->btn_control, SIGNAL(clicked(bool)), this, SLOT(slotControlData(bool)));
    pWebView = new QWebEngineView(this);
    pWebView->load(QUrl(QStringLiteral("http://10.10.141.136:8080/?action=stream")));
    ui->monitoring_L->addWidget(pWebView);
}

Monitoring::~Monitoring()
{
    delete ui;
}

void Monitoring::slotPushButton()
{
    emit pushButtonSig(0);
}

void Monitoring::slotControlData(bool check)
{
    if(check){
        emit sigControl(check);
    }
    else {
        emit sigControl(check);
    }
}
