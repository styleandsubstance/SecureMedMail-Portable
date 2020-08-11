#include "httpsession.h"

HttpSession::HttpSession()
{

    authenicated = false;
    //qnam.setCookieJar();
    //cookieJar = new QNetworkCookieJar()
}

HttpSession::~HttpSession()
{

}

QNetworkReply *HttpSession::HttpFormPost(QString requestUrl, QUrlQuery *params)
{
    QUrl url(requestUrl);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    //QByteArray data;
    //data.append(params->toEncoded());

    //qnam.setCookieJar();

    QNetworkReply *reply = qnam.post(request, params->query().toUtf8());

    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    return reply;
}

void HttpSession::Authenticate(QString username, QString password)
{
    qDebug() << "Attempting to authenticate with username: " << username << " and password: " << password;

    QUrlQuery params;
    params.addQueryItem("username", username);
    params.addQueryItem("password", password);
    QNetworkReply *reply = this->HttpFormPost(WebServiceUrls::Authenticate(), &params);

    QVariant statusCode = reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );
    if ( !statusCode.isValid() )
        return;

    int status = statusCode.toInt();
    qDebug() << "Http Status Code: " << status;

//    if ( status != 200 )
//    {
//        QString reason = reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
//        qDebug() << reason;
//    }



}


QNetworkCookieJar *HttpSession::getCookieJar()
{
    return qnam.cookieJar();
}


QNetworkReply *HttpSession::Upload(UploadFileAttributesForm *uploadFileAttributesForm, QString filename, QString encryptedFilePath)
{
    QFile *file = new QFile(encryptedFilePath);

    if (!file->exists()) {
        //emit error(tr("Upload Error. File does not exist: ") + this->encryptedFilePath);
        return NULL;
    }


    file->open(QIODevice::ReadOnly);

    QUrl url(WebServiceUrls::UploadFile());
    QNetworkRequest request(url);

    request.setRawHeader("File-Size", QString::number(file->size()).toUtf8());

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QMap<QString, QString> *formValues = uploadFileAttributesForm->buildDictionaryForPost();
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

    QNetworkReply *reply = this->qnam.post(request, multiPart);
    multiPart->setParent(reply); // delete the multiPart with the reply

    return reply;
}

