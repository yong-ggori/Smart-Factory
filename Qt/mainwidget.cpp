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
    pData = new Data(ui->page3);
    ui->page3->setLayout(pData->layout());
    connect(pHome,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));
    connect(pMonitoring,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));
    connect(pData,SIGNAL(pushButtonSig(int)),this,SLOT(slotChangeIndex(int)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::slotChangeIndex(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
