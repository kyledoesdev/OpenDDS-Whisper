#ifndef READERQOS_H
#define READERQOS_H

#include <QDialog>

namespace Ui {
class ReaderQos;
}

class ReaderQos : public QDialog
{
    Q_OBJECT

public:
    explicit ReaderQos(QWidget *parent = nullptr);
    ~ReaderQos();

private:
    Ui::ReaderQos *ui;
};

#endif // READERQOS_H
