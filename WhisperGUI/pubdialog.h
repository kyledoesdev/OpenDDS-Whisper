#ifndef PUBDIALOG_H
#define PUBDIALOG_H
#include <writerqos.h>
#include <QDialog>

namespace Ui {
class PubDialog;
}

class PubDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PubDialog(QWidget *parent = nullptr);
    ~PubDialog();

private slots:
    void on_createWriterButton_clicked();

    void on_pubQosButton_clicked();

private:
    Ui::PubDialog *ui;
    WriterQoS *spubQoS;
};

#endif // PUBDIALOG_H
