#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>

#include "config.h"


Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    QFileDialog::Options options = QFlag(QFileDialog::ShowDirsOnly);
       options |= QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
       QString directory = QFileDialog::getExistingDirectory(this,
                                   tr("Select the Folder To Use"),
                                   ui->lineEdit->text(),
                                   options);
       if (!directory.isEmpty())
          ui->lineEdit->setText(directory);
}

void Settings::on_pushButton_2_clicked()
{
    //try to implement the save to settings code

}
