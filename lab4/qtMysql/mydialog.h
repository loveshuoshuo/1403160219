#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class MYDialog;
}

class MYDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MYDialog(QWidget *parent = 0);
    ~MYDialog();

private:
    Ui::MYDialog *ui;
};

#endif // MYDIALOG_H
