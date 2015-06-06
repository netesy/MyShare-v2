#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "about.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    //open the about dialog
    About *about = new About();
    about->show();

}

void MainWindow::on_actionSettings_2_triggered()
{
    //open the settings dialog
    Settings *settings = new Settings();
    settings->show();
}
