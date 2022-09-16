#ifndef MONITORING_H
#define MONITORING_H

#include <QWidget>
#include <QWebEngineView>
#include "socketclient.h"
#include "home.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Monitoring; }
QT_END_NAMESPACE

class Monitoring : public QWidget
{
    Q_OBJECT

public:
    explicit Monitoring(QWidget *parent = nullptr);
    ~Monitoring();

private:
    Ui::Monitoring *ui;
    QWebEngineView *pWebView;
    Home* home;
    SocketClient* pSocketClient;
    void monitoring();

private slots:
    void slotPushButton();
    void slotControlData(bool);
signals:
    void pushButtonSig(int);
    void sigControl(bool);
    void sigSocketSendData(QString);
};

#endif // MONITORING_H
