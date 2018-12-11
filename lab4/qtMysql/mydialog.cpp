#include "mydialog.h"
#include "ui_mydialog.h"

MYDialog::MYDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MYDialog)
{
    ui->setupUi(this);
}

MYDialog::~MYDialog()
{
    delete ui;
}
