#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include "socketclient.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    SocketClient* pSocketClient;

private slots:
    void slotPushButton1();
    void slotPushButton3();
    void slotConnectToServer(bool);
    //void slotSocketRecvUpdate(QString);
    void slotSocketSendData(bool);
    void slotSocketSendData(QString);

    void geterr(QString);

signals:
    void pushButtonSig(int);
    void sigSocketRecv(QString);

};
#endif // HOME_H
