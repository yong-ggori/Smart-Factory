#ifndef IMAGE_H
#define IMAGE_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class Image;
}

class Image : public QDialog
{
    Q_OBJECT

public:
    explicit Image(QWidget *parent = nullptr);
    ~Image();
    void imgload(QString);

private:
    Ui::Image *ui;
};

#endif // IMAGE_H
