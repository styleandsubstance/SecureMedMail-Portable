#ifndef UPLOADPROGRESS_H
#define UPLOADPROGRESS_H

#include <QWidget>
#include "encryptionthread.h"
#include "tempfile.h"
#include "uploadfileorfolderform.h"
#include "uploadsuccessdialog.h"
#include "uploadthread.h"
#include "zipthread.h"


namespace Ui {
class UploadProgress;
}

class UploadProgress : public QWidget
{
    Q_OBJECT

public:
    explicit UploadProgress(QWidget *parent = 0);
    ~UploadProgress();

    void Start(UploadFileOrFolderForm *uploadFileOrFolderForm);

private:
    Ui::UploadProgress *ui;

    QString filePath;
    QString fileName;
    UploadFileOrFolderForm *uploadFileOrFolderForm;
    QString compressedFile;
    QString encryptedFile;

    ZipThread *z;
    EncryptionThread *e;
    UploadThread *u;


public slots:
    void setCompressionProgressBar(int val);
    void setEncryptionProgressBar(int val);
    void setUploadProgressBar(int val);
    void CompressionFinished(void);
    void EncryptionFinished();
    void UploadFinished(QString);

};

#endif // UPLOADPROGRESS_H
