#include "pubdialog.h"
#include "ui_WhisperFormPub.h"

PubDialog::PubDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PubDialog)
{
    ui->setupUi(this);
}

PubDialog::~PubDialog()
{
    delete ui;
}

void PubDialog::on_createWriterButton_clicked()
{
    int numResults = ui->numResults->value();
    std::string businessType = ui->pubTopic->displayText().toStdString();
    std::string text = "Published ";
    text += std::to_string(numResults) + " place";
    if(numResults != 1)
        text += "s";

    text += " of type " + businessType;

    QString qstr = QString::fromStdString(text);



    ui->pubTextBrowser->setText(qstr);
}


void PubDialog::on_pubQosButton_clicked()
{
    {
        (new WriterQoS) -> show();

    }
}

