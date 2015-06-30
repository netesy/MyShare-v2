#include "settings.h"
#include "ui_settings.h"
#include <QFileDialog>
#include <QMessageBox>

#include "config.h"


Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);
    LoadSettings();
}

void Settings::SaveSettings()
{
   QSettings settings("Unethical","MyShare");
   settings.beginGroup("Main Settings");
   settings.setValue("Folder",ui->folder->text());
   settings.setValue("Name",ui->name->text());
   settings.endGroup();
}

void Settings::LoadSettings()
{
    QSettings settings("Unethical","MyShare");
    settings.beginGroup("Main Settings");
    ui->folder->setText(settings.value("Folder").toString());
    ui->name->setText(settings.value("Name").toString());
    settings.endGroup();
}

bool Settings::isSet()
{
    QSettings settings("Unethical","MyShare");
    settings.beginGroup("Main Settings");
    QString file = settings.value("Folder").toString();
    settings.endGroup();
    if(file.isEmpty())
        return 1;
    else
        return 0;
}

QString Settings::Folder()
{
    QSettings settings("Unethical","MyShare");
    settings.beginGroup("Main Settings");
   QString folder = settings.value("Folder").toString();
    settings.endGroup();
    return folder;
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
                                   ui->folder->text(),
                                   options);
       if (!directory.isEmpty())
          ui->folder->setText(directory);
}

void Settings::on_pushButton_2_clicked()
{
    //try to implement the save to settings code
    SaveSettings();
    QMessageBox::about(this, "Saved", "The Settings have been saved.");

}
