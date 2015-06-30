#include "about.h"
#include "ui_about.h"

//set the text to use
const QString Credits =
    "<html><head><meta name='qrichtext' content='1'/></head><body>"
    "<table><tr><td>Created by:</td>"
    "<td><a href='mailto:netesy1@gmail.com'>Netesy Maximus</a></td></tr>"
    "<tr><td></td></tr></table></body></html>";

const QString License =
    "The MIT License (MIT)\n\n"

    "Permission is hereby granted, free of charge, to any person obtaining a copy "
    "of this software and associated documentation files (the \"Software\"), to "
    "deal in the Software without restriction, including without limitation the "
    "rights to use, copy, modify, merge, publish, distribute, sublicense, and/or "
    "sell copies of the Software, and to permit persons to whom the Software is "
    "furnished to do so, subject to the following conditions:\n\n"

    "The above copyright notice and this permission notice shall be included in "
    "all copies or substantial portions of the Software.\n\n"

    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE "
    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING "
    "FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS "
    "IN THE SOFTWARE.";
About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    QString websiteTxt("<html><head/><body><a href=\"%1\">%1</a></body></html>");
    ui->setupUi(this);
    ui->textBrowser->hide();
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->logo->setPixmap(QPixmap(":/images/images/logo.png").scaled(128, 128));
    ui->appname->setText(PROJECT_TITLE);
    ui->version->setText(QString("Version %1").arg(PROJECT_VERSION));
    ui->disc->setText(PROJECT_DESCRIPTION);
    ui->label->setText(websiteTxt.arg(PROJECT_WEBSITE));
    ui->copyright->setText(QString("Copyright (c) 2015 - %1").arg(PROJECT_AUTHOR));




}

About::~About()
{
    delete ui;
}

void About::on_close_clicked()
{
    this->close();
}

void About::on_License_clicked()
{
    //show the textBrowser
    if(!ui->textBrowser->isHidden())
     ui->textBrowser->hide();
        else
     ui->textBrowser->show();
    //first clear the previous text if any
    ui->textBrowser->clear();
    //set the text
    ui->textBrowser->setText(License);
}

void About::on_info_clicked()
{
    //show the textBrowser
    if(!ui->textBrowser->isHidden())
     ui->textBrowser->hide();
        else
     ui->textBrowser->show();
    //first clear the previous text if any
    ui->textBrowser->clear();
    //set the text
    ui->textBrowser->setText(Credits);
}
