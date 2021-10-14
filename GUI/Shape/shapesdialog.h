#ifndef SHAPESDIALOG_H
#define SHAPESDIALOG_H

#include <QDialog>
#include <writerqos.h>
#include <readerqos.h>
#include <filterdialog.h>

namespace Ui {
class ShapesDialog;
}

class ShapesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShapesDialog(QWidget *parent = nullptr);
    ~ShapesDialog();

private slots:
    void on_pubQosButton_clicked();

    void on_subQosButton_clicked();

    void on_filterButton_clicked();

private:
    Ui::ShapesDialog *ui;
    WriterQoS *spubQoS;
    ReaderQos *ssubQos;
    FilterDialog *sFilter;
};

#endif // SHAPESDIALOG_H
