#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QWidget>
#include "logindialog.h"
#include "uploadfileorfolderform.h"

namespace Ui {
class UploadFile;
}

class UploadFile : public QWidget
{
    Q_OBJECT

public:
    explicit UploadFile(QWidget *parent = 0);
    ~UploadFile();

    void initialize();
    bool validate();

    UploadFileOrFolderForm *buildUploadFileOrFolderForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UploadFile *ui;
};

#endif // UPLOADFILE_H
