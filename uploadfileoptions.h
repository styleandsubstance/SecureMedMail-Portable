#ifndef UPLOADFILEOPTIONS_H
#define UPLOADFILEOPTIONS_H

#include <QWidget>

#include "appsettings.h"
#include "uploadfileattributesform.h"

namespace Ui {
class UploadFileOptions;
}

class UploadFileOptions : public QWidget
{
    Q_OBJECT

public:
    explicit UploadFileOptions(QWidget *parent = 0);
    ~UploadFileOptions();

    UploadFileAttributesForm *buildUploadForm();

private slots:
    void on_deletionComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::UploadFileOptions *ui;
};

#endif // UPLOADFILEOPTIONS_H
