#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui {
class Data;
}
QT_END_NAMESPACE

class Data : public QWidget
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = nullptr);
    ~Data();

private:
    Ui::Data *ui;
    QWebEngineView  *pWebView;

private slots:
    void slotPushButton();

signals:
    void pushButtonSig(int);
};

#endif // DATA_H
