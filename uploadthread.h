#ifndef UPLOADTHREAD_H
#define UPLOADTHREAD_H

#include <QTCore>

#include "httpsession.h"
#include "uploadfileattributesform.h"

class UploadThread : public QThread
{
    Q_OBJECT
public:
    UploadThread(UploadFileAttributesForm *uploadFileAttributesForm, QString filename, QString encryptedFilePath);
    ~UploadThread();

    void ReportProgress(int);

private:
    UploadFileAttributesForm *uploadFileAttributesForm;
    QString filename;
    QString encryptedFilePath;

    QNetworkReply *reply;


protected:
    void run();

signals:
    void Progress(int);
    void Finished();
    void UploadSuccess(QString);

public slots:
    void UploadFinished();

    void UploadError(QNetworkReply::NetworkError);

    void UploadProgress(qint64, qint64);


};

#endif // UPLOADTHREAD_H
