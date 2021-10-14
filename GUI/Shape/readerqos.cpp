#include "readerqos.h"
#include "ui_readerQosForm.h"

ReaderQos::ReaderQos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderQos)
{
    ui->setupUi(this);
}

ReaderQos::~ReaderQos()
{
    delete ui;
}
