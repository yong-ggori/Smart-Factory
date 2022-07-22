#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <monitoring.h>
#include <home.h>
#include <data.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    Monitoring* pMonitoring;
    Home* pHome;
    Data* pData;

private slots:
    void slotChangeIndex(int);

};
#endif // MAINWIDGET_H
