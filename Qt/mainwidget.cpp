#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "home.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    pHome = new Home(ui->page1);
    ui->page1->setLayout(pHome->layout());
    pMonitoring = new Monitoring(ui->page2);
    ui->page2->setLayout(pMonitoring->layout());
    pDBTable = new DBTable(ui->page3);
    ui->page3->setLayout(pDBTable->layout());

    connect(pHome,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));
    connect(pMonitoring,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));
    connect(pDBTable,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));

    //connect(pHome,SIGNAL(sigTab3RecvData(QString)), pMonitoring, SLOT(slotTab3RecvData(QString)));
    connect(pMonitoring,SIGNAL(sigControl(bool)), pHome, SLOT(slotSocketSendData(bool)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::slotChangeIndex(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
