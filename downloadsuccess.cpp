#include "downloadsuccess.h"
#include "ui_downloadsuccess.h"

DownloadSuccess::DownloadSuccess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DownloadSuccess)
{
    ui->setupUi(this);
}

DownloadSuccess::~DownloadSuccess()
{
    delete ui;
}
