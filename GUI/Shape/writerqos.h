#ifndef WRITERQOS_H
#define WRITERQOS_H

#include <QDialog>

namespace Ui {
class WriterQoS;
}

class WriterQoS : public QDialog
{
    Q_OBJECT

public:
    explicit WriterQoS(QWidget *parent = nullptr);
    ~WriterQoS();

private:
    Ui::WriterQoS *ui;
};

#endif // WRITERQOS_H
