#include "dbtable.h"
#include "image.h"
#include "ui_dbtable.h"

DBTable::DBTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBTable)
{
    ui->setupUi(this);
    connect(ui->btn_home_db,SIGNAL(clicked()),this,SLOT(slotPushButton()));
    connect(ui->pPB_Search, SIGNAL(clicked()), this, SLOT(slotSearchDB()));
    connect(ui->pPB_Delete, SIGNAL(clicked()), this, SLOT(slotDeleteDB()));
    //connect(ui->pTableWidget->, SIGNAL(clicked()), this, SLOT(slotPushButton()));

    ui->pTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    sqlDb = QSqlDatabase::addDatabase("QMYSQL");       // 사용할 데이터 베이스 목록 기입
    sqlDb.setHostName("10.10.141.34");
    sqlDb.setUserName("ubuntu");
    sqlDb.setPassword("kcci");
    sqlDb.setDatabaseName("smartFactory");

    if(sqlDb.open()) {
        qDebug() << "Success DB connection";
    }
    else {
        qDebug() << "fail DB connection";
    }
}

DBTable::~DBTable()
{
    delete ui;
}

void DBTable::slotPushButton()
{
    emit pushButtonSig(0);
}

void DBTable::slotSearchDB()
{
    QDateTime dateTimeFrom = ui->pDateTimeEditFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy-MM-dd hh:mm:ss");       // 저장된 날짜 및 시간 형식으로 변경

    QDateTime dateTimeTo = ui->pDateTimeEditTo->dateTime();
    QString strTo = dateTimeTo.toString("yy-MM-dd hh:mm:ss");

    int rowCount = 0;
    ui->pTableWidget->clearContents();                                  // tablewidget clear 시키는 함수 실행

    QString query = "select * from imageProcessing where datetime>'" + strFrom + "' AND datetime < '" + strTo + "'";
    // 날짜가 strFrom 부터 strTo 까지 사이에 있는 모든 데이터 조회
    QSqlQuery qry;

    if(qry.exec(query)) {
        while(qry.next()) {
            rowCount++;
            ui->pTableWidget->setRowCount(rowCount);                    // table widget 안에 값을 넣기 위한 작업 ...
            QTableWidgetItem *id = new QTableWidgetItem();
            QTableWidgetItem *datetime = new QTableWidgetItem();
            QTableWidgetItem *shape = new QTableWidgetItem();
            QTableWidgetItem *color = new QTableWidgetItem();
            QTableWidgetItem *image = new QTableWidgetItem();

            id->setText(qry.value("id").toString());
            datetime->setText(qry.value("datetime").toString());
            shape->setText(qry.value("shape").toString());
            color->setText(qry.value("color").toString());
            //image->setText(qry.value("image").toString());

            ui->pTableWidget->setItem(rowCount-1, 0, id);               // 인덱스는 0부터 시작하기 때문에 -1 해준다.
            ui->pTableWidget->setItem(rowCount-1, 1, datetime);
            ui->pTableWidget->setItem(rowCount-1, 2, shape);
            ui->pTableWidget->setItem(rowCount-1, 3, color);
            //ui->pTableWidget->setItem(rowCount-1, 4, image);


            button = new QPushButton();
            imgSRC = qry.value("image").toString();
            button->setText(imgSRC);
            imgSRC = "/home/ubuntu/img_socket/img/" + qry.value("image").toString();

            img[n] = imgSRC;
            n++;

            ui->pTableWidget->setCellWidget(rowCount-1, 4, button);
            connect(button, SIGNAL(clicked()), this, SLOT(new_window()));
        }
    }
    else
        qDebug() << qry.lastError().text();             // 쿼리문 작성 오류면 오류 문구 출력
}
void DBTable::slotDeleteDB()
{
    QDateTime dateTimeFrom = ui->pDateTimeEditFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy-MM-dd hh:mm:ss");       // 저장된 날짜 및 시간 형식으로 변경

    QDateTime dateTimeTo = ui->pDateTimeEditTo->dateTime();
    QString strTo = dateTimeTo.toString("yy-MM-dd hh:mm:ss");

    QString query = "delete from imageProcessing where datetime >'" + strFrom + "' AND datetime < '" + strTo + "'";
    QSqlQuery qry;

    if(qry.exec(query)) {

    }
}

void DBTable::new_window()
{
    image = new Image(this);
    int currentRow = ui->pTableWidget->currentRow();
    image->imgload(img[currentRow]);
    image->show();
}
