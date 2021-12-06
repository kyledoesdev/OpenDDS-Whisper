#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pubButton_clicked()
{
    (new PubDialog) -> show();
    close();
}


void MainWindow::on_subButton_clicked()
{
    (new SubDialog) -> show();
    close();
}

