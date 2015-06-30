#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "about.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->tabWidget);
    this->setWindowFlags(Qt::FramelessWindowHint);
     QString download = "";
    Settings *settings = new Settings();
    if(settings->isSet() == 0)
    {
        //use the set folder selected by the user
        download = settings->Folder();
    }
    else
    {
    //use the download folder inside the home directory for files
    download = QDir::homePath()+"/Downloads";
    }

   //set the models to use
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter( QDir::NoDotAndDotDot | QDir::AllDirs);

//Application
{
    //set the filter to get only executable files
    QStringList filters;
    filters << "*.exe" << "*.msi" << "*.msu";
    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot |QDir::AllEntries | QDir::Files);
    fileModel->setNameFilters(filters);
    fileModel->setNameFilterDisables(false);
    fileModel->setRootPath(download);
    ui->listView->setModel(fileModel);
    ui->listView->setRootIndex(fileModel->index(download));
}
//Image
    {
        //set the filter to get only image files
        QStringList filters;
        filters << "*.jpeg" << "*.jpg" << "*.png"<<"*.gif";
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        fileModel->setNameFilters(filters);
        fileModel->setNameFilterDisables(false);
        fileModel->setRootPath(download);
        ui->image_2->setModel(fileModel);
        ui->image_2->setRootIndex(fileModel->index(download));
    }
//Music
    {
        //set the filter to get only music files
        QStringList filters;
        filters << "*.mp3" << "*.ogg" << "*.wav"<<"*.aaf"<<"*.wma"<<"*.aac"<<"*.aiff";
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        fileModel->setNameFilters(filters);
        fileModel->setNameFilterDisables(false);
        fileModel->setRootPath(download);
        ui->music_2->setModel(fileModel);
        ui->music_2->setRootIndex(fileModel->index(download));
    }
//Movies
    {
        //set the filter to get only videos files
        QStringList filters;
        filters << "*.avi" << "*.ogv" << "*.mov"<<"*.mkv"<<"*.webm"<<"*.mp4"<<"*.3gp";
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        fileModel->setNameFilters(filters);
        fileModel->setNameFilterDisables(false);
        fileModel->setRootPath(download);
        ui->movies_2->setModel(fileModel);
        ui->movies_2->setRootIndex(fileModel->index(download));
    }
//Categories
    {
        //set the filter to get only categories files
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files |QDir::AllEntries);
        fileModel->setRootPath(download);
        ui->categories_2->setModel(fileModel);

    }
//Disk
    {
        //set the filter to get only music files
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
        fileModel->setRootPath(QDir::rootPath());
        ui->disk_2->setModel(fileModel);
    }
//Record
    {
        //set the filter to get only sent files
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        fileModel->setRootPath(download);
        ui->record_2->setModel(fileModel);
    }

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
