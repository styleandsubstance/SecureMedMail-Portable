#include "uploadsuccessdialog.h"
#include "ui_uploadsuccessdialog.h"

UploadSuccessDialog::UploadSuccessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UploadSuccessDialog)
{
    ui->setupUi(this);
}

UploadSuccessDialog::~UploadSuccessDialog()
{
    delete ui;
}


void UploadSuccessDialog::setGuid(QString guid)
{
    this->ui->guid->setText(guid);
}
