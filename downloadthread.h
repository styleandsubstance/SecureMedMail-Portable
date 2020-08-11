#ifndef DOWNLOADTHREAD_H
#define DOWNLOADTHREAD_H

#include <QtCore>

#include "httpsession.h"

class DownloadThread : public QThread
{
    Q_OBJECT

private:
    QString guid;
    QString downloadPath;
    QFile *file;
    QNetworkReply *reply;

public:
    DownloadThread(QString guid, QString downloadPath);
    ~DownloadThread();

protected:
    void run();

signals:
    void Progress(int);
    void Finished();
    void DownloadSuccess(QString, QString);

public slots:
    void DownloadReadyRead();

    void DownloadFinished();

    void DownloadError(QNetworkReply::NetworkError);

    void DownloadProgress(qint64, qint64);

};

#endif // DOWNLOADTHREAD_H
