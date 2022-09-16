#ifndef DBTABLE_H
#define DBTABLE_H

#include <QWidget>
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "image.h"

namespace Ui {
class DBTable;
}

class DBTable : public QWidget
{
    Q_OBJECT

public:
    explicit DBTable(QWidget *parent = nullptr);
    ~DBTable();

private:
    Ui::DBTable *ui;
    Image *image;
    QSqlDatabase sqlDb;
    QSqlQuery qry;
    QString query;
    QPushButton *button;
    QString imgSRC;
    QString *img = new QString[100];
    int n=0;

private slots:
    void slotPushButton();
    void slotSearchDB();
    void slotDeleteDB();
    void new_window();

signals:
    void pushButtonSig(int);
};

#endif // DBTABLE_H
