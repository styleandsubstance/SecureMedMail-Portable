#ifndef WEBSERVICEURLS
#define WEBSERVICEURLS

#include <QString>

#include "appsettings.h"

class WebServiceUrls
{

public:
    static QString Authenticate() {
        return AppSettings::getValue(AppSettings::WebServiceUrl::ServerUrl)
                + AppSettings::getValue(AppSettings::WebServiceUrl::Authenticate);
    }

    static QString UploadFile() {
        return AppSettings::getValue(AppSettings::WebServiceUrl::ServerUrl)
                + AppSettings::getValue(AppSettings::WebServiceUrl::UploadFile);
    }

    static QString DownloadFile() {
        return AppSettings::getValue(AppSettings::WebServiceUrl::ServerUrl)
                + AppSettings::getValue(AppSettings::WebServiceUrl::DownloadFile);
    }

};

#endif // WEBSERVICEURLS

