#include "downloadthread.h"

DownloadThread::DownloadThread(QString guid, QString downloadPath)
{
    this->guid = guid;
    this->downloadPath = downloadPath;
    this->reply = NULL;
}

DownloadThread::~DownloadThread()
{
    if (file)
        delete file;

    if (reply)
        delete reply;
}

void DownloadThread::run()
{
    QNetworkAccessManager qnam;
    qnam.setCookieJar( HttpSession::getSession()->getCookieJar());

    file = new QFile(this->downloadPath);
    if (!file->open(QIODevice::WriteOnly)) {
        delete file;
        file = 0;
        return;
    }

    QUrl url(WebServiceUrls::DownloadFile() + "/" + this->guid);

    // get() method posts a request
    // to obtain the contents of the target request
    // and returns a new QNetworkReply object
    // opened for reading which emits
    // the readyRead() signal whenever new data arrives.
    reply = qnam.get(QNetworkRequest(url));

    // Whenever more data is received from the network,
    // this readyRead() signal is emitted
    connect(reply, SIGNAL(readyRead()),
            this, SLOT(DownloadReadyRead()));

    // Also, downloadProgress() signal is emitted when data is received
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(DownloadProgress(qint64,qint64)));

    // This signal is emitted when the reply has finished processing.
    // After this signal is emitted,
    // there will be no more updates to the reply's data or metadata.
    connect(reply, SIGNAL(finished()),
            this, SLOT(DownloadFinished()));

    QEventLoop loop;
    connect(this, SIGNAL(Finished()), &loop, SLOT(quit()));
    loop.exec();


    qDebug() << "HERE!";

    file->flush();
    file->close();


    emit DownloadSuccess(QString(reply->rawHeader(QString("GUID").toUtf8())),QString(reply->rawHeader(QString("File-Name").toUtf8())));


}


void DownloadThread::DownloadReadyRead()
{
    qDebug() << "Writing File";
    if (file)
        file->write(reply->readAll());
}

//void DownloadThread::httpDownloadFinished()
//{
//    // when canceled
////    if (httpRequestAborted) {
////        if (file) {
////            file->close();
////            file->remove();
////            delete file;
////            file = 0;
////        }
////        reply->deleteLater();
////        progressDialog->hide();
////        return;
////    }


//}


void DownloadThread::DownloadError(QNetworkReply::NetworkError error)
{
    qDebug() << "Error while downloading" << error;
}

void DownloadThread::DownloadProgress(qint64 bytesSent, qint64 bytesTotal)
{

    qDebug() << "Download Progress...." << bytesSent << " " << bytesTotal;

    if ( bytesSent == 0 && bytesTotal == 0) {
        return;
    }

    if ( bytesTotal == 0) {
        qDebug() << "Progress = 0";
        emit Progress(0);
    }
    else {
        int percentProgress = (int)((bytesSent * (qint64)100)/bytesTotal);
        qDebug() << "Progress = " << percentProgress;
        emit Progress(percentProgress);
    }
}

void DownloadThread::DownloadFinished()
{
    qDebug() << "Download finished";
    emit Finished();
}

