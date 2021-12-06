#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include <QDialog>
#include <readerqos.h>
#include <filterdialog.h>

namespace Ui {
class SubDialog;
}

class SubDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SubDialog(QWidget *parent = nullptr);
    ~SubDialog();

private slots:
    void on_createReaderButton_clicked();

    void on_filterButton_clicked();

    void on_subQosButton_clicked();

private:
    Ui::SubDialog *ui;
    ReaderQos *ssubQos;
    FilterDialog *sFilter;
};

#endif // SUBDIALOG_H
