#ifndef DOWNLOADFILE_H
#define DOWNLOADFILE_H

#include <QDebug>
#include <QWidget>
#include <QFileDialog>
#include "downloadfileform.h"

namespace Ui {
class DownloadFile;
}

class DownloadFile : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadFile(QWidget *parent = 0);
    ~DownloadFile();

    bool validate();

    DownloadFileForm *buildDownloadFileForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DownloadFile *ui;
};

#endif // DOWNLOADFILE_H
