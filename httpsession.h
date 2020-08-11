#ifndef HTTPSESSION_H
#define HTTPSESSION_H

#include <QTCore>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrlQuery>
#include <QEventLoop>

#include "appsettings.h"
#include "uploadfileattributesform.h"
#include "webserviceurls.h"

class HttpSession : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager qnam;
    bool authenicated;
public:
    HttpSession();
    ~HttpSession();



    //static HttpSession *httpSession;

    static HttpSession *getSession() {
        static HttpSession *session = new HttpSession();

        return session;


//        if (AppSettings::httpSession == NULL ) {
//            AppSettings::httpSession = new HttpSession();
//        }
//        return AppSettings::httpSession;

//        return new HttpSession();
    }


    QNetworkReply *HttpFormPost(QString requestUrl, QUrlQuery *params);

    void Authenticate(QString username, QString password);

    QNetworkReply *Upload(UploadFileAttributesForm *uploadFileAttributesForm, QString filename, QString encryptedFilePath);

    QNetworkCookieJar *getCookieJar();


};

#endif // HTTPSESSION_H
