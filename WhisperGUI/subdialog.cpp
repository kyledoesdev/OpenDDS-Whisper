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
    std::string businessType = ui->businessCombo->currentText().toStdString();
    std::string text = "Subscribed to ";
    text += businessType;


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

