#include "shapesdialog.h"
//#include "subDialog.h"
#include "ui_iShapesForm.h"

ShapesDialog::ShapesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShapesDialog)
{
    ui->setupUi(this);
}

ShapesDialog::~ShapesDialog()
{
    delete ui;
}

void ShapesDialog::on_pubQosButton_clicked()
{
    (new WriterQoS) -> show();

}


void ShapesDialog::on_subQosButton_clicked()
{
    (new ReaderQos) -> show();
}


void ShapesDialog::on_filterButton_clicked()
{
    (new FilterDialog) -> show();
}

