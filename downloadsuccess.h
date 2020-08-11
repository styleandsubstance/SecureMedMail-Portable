#ifndef DOWNLOADSUCCESS_H
#define DOWNLOADSUCCESS_H

#include <QDialog>

namespace Ui {
class DownloadSuccess;
}

class DownloadSuccess : public QDialog
{
    Q_OBJECT

public:
    explicit DownloadSuccess(QWidget *parent = 0);
    ~DownloadSuccess();

private:
    Ui::DownloadSuccess *ui;
};

#endif // DOWNLOADSUCCESS_H
