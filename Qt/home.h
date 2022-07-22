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
    void slotPushButton2();
    void slotConnectToServer(bool);

signals:
    void pushButtonSig(int);

};
#endif // HOME_H
