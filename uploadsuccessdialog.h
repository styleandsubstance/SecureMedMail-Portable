#ifndef UPLOADSUCCESSDIALOG_H
#define UPLOADSUCCESSDIALOG_H

#include <QDialog>

namespace Ui {
class UploadSuccessDialog;
}

class UploadSuccessDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UploadSuccessDialog(QWidget *parent = 0);
    ~UploadSuccessDialog();

    void setGuid(QString guid);

private:
    Ui::UploadSuccessDialog *ui;
};

#endif // UPLOADSUCCESSDIALOG_H
