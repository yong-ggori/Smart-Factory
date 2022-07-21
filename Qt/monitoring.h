#ifndef MONITORING_H
#define MONITORING_H

#include <QWidget>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class Monitoring; }
QT_END_NAMESPACE

class Monitoring : public QWidget
{
    Q_OBJECT

public:
    explicit Monitoring(QWidget *parent = nullptr);
    ~Monitoring();
    void imgload();

private:
    Ui::Monitoring *ui;
private slots:
    void slotPushButton();
signals:
    void pushButtonSig(int);
};

#endif // MONITORING_H
