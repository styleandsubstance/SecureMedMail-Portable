#include "uploadthread.h"

UploadThread::UploadThread(UploadFileAttributesForm *uploadFileAttributesForm, QString filename, QString encryptedFilePath)
{
    this->uploadFileAttributesForm = uploadFileAttributesForm;
    this->filename = filename;
    this->encryptedFilePath = encryptedFilePath;
}

UploadThread::~UploadThread()
{

}

void UploadThread::run()
{

    QNetworkAccessManager qnam;
    qnam.setCookieJar( HttpSession::getSession()->getCookieJar());

    QFile *file = new QFile(this->encryptedFilePath);

    if (!file->exists()) {
        //emit error(tr("Upload Error. File does not exist: ") + this->encryptedFilePath);
        //return NULL;
        qDebug() << "File doesn't exist...can't upload";
        return;
    }


    file->open(QIODevice::ReadOnly);

    //QUrl url("http://localhost:9000/putFile");
    QUrl url(WebServiceUrls::UploadFile());
    QNetworkRequest request(url);

    request.setRawHeader("File-Size", QString::number(file->size()).toUtf8());

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QMap<QString, QString> *formValues = this->uploadFileAttributesForm->buildDictionaryForPost();
    for(QString e : formValues->keys())
    {
        QHttpPart formValuePart;
        QString contentDispositionHeader = "form-data; name=\"" + e + "\"";

        formValuePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDispositionHeader));
        formValuePart.setBody(formValues->value(e).toUtf8());

        multiPart->append(formValuePart);
    }

    delete formValues;

    QHttpPart filePart;
    QString contentDispositionHeader = "form-data; name=\"file\"; filename=\"" + filename + "\"";

    filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant( "application/octet-stream"));
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(contentDispositionHeader));

    filePart.setBodyDevice(file);
    //file->setParent(multiPart); // we cannot delete the file now, so delete it with the multiPart

    multiPart->append(filePart);

    //QNetworkReply *reply = qnam.post(request, multiPart);
    QNetworkReply *reply = qnam.post(request, multiPart);
    multiPart->setParent(reply); // delete the multiPart with the reply

    connect(reply, SIGNAL(finished()),
             this, SLOT  (UploadFinished()));

    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
             this, SLOT  (UploadError(QNetworkReply::NetworkError)));

    connect(reply, SIGNAL(uploadProgress(qint64, qint64)),
             this, SLOT  (UploadProgress(qint64, qint64)));


    this->reply = reply;

    QEventLoop loop;
    //connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(this, SIGNAL(Finished()), &loop, SLOT(quit()));
    loop.exec();


    qDebug() << "HERE!";

    emit UploadSuccess(QString(reply->rawHeader(QString("GUID").toUtf8())));


    //qDebug() << "GUID: " << reply->rawHeader(QString("GUID").toUtf8());

//    return reply;


//    reply = HttpSession::getSession()->Upload(
//                this->uploadFileAttributesForm,
//                this->filename, this->encryptedFilePath);



}

void UploadThread::UploadError(QNetworkReply::NetworkError error)
{
    qDebug() << "Error while uploading" << error;
}

void UploadThread::UploadProgress(qint64 bytesSent, qint64 bytesTotal)
{

    qDebug() << "Upload Progress...." << bytesSent << " " << bytesTotal;

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

void UploadThread::UploadFinished()
{
    qDebug() << "Upload finished";
    emit Finished();
}
