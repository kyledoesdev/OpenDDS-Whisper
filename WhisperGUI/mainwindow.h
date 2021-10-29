#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <shapesdialog.h>
#include <pubdialog.h>
#include <subdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pubButton_clicked();

    void on_subButton_clicked();

private:
    Ui::MainWindow *ui;
    ShapesDialog *sWindow;
    PubDialog *sWindow2;
    SubDialog *sWindow3;
};
#endif // MAINWINDOW_H
