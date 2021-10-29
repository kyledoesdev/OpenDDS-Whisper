#include "writerqos.h"
#include "ui_pubQosForm.h"

WriterQoS::WriterQoS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WriterQoS)
{
    ui->setupUi(this);
}

WriterQoS::~WriterQoS()
{
    delete ui;
}
