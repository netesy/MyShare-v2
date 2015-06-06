#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "config.h"

namespace Ui {
class About;
}

class About : public QWidget
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private slots:
    void on_close_clicked();

    void on_License_clicked();

    void on_info_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
