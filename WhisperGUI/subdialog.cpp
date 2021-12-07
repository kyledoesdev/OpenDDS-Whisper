#include "subdialog.h"
#include "ui_WhisperFormSub.h"
#include "pubdialog.h"
#include "ui_WhisperFormPub.h"


SubDialog::SubDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubDialog)

{
    ui->setupUi(this);
}

SubDialog::~SubDialog()
{
    delete ui;
}

void SubDialog::on_createReaderButton_clicked()
{
    std::string businessType = ui->subTopic->displayText().toStdString();
    std::string text = "Now listening for: ";
    text += businessType + "!";


    QString qstr = QString::fromStdString(text);
    ui->subTextBrowser->setText(qstr);
}


void SubDialog::on_subQosButton_clicked()
{
    (new ReaderQos) -> show();
}


void SubDialog::on_filterButton_clicked()
{
    (new FilterDialog) -> show();
}


void SubDialog::on_clearButton_clicked()
{
    ui->subTextBrowser->setText("");
}

