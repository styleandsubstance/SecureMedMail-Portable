#ifndef UPLOADFILEPROPERTY_H
#define UPLOADFILEPROPERTY_H

#include <QString>

class UploadFileProperty
{
public:
    UploadFileProperty();
    ~UploadFileProperty();

    QString name;
    QString value;
    QString type;


    static const QString DeleteAfterDownload;
    static const QString MustBeAuthenticated;
    static const QString MustBeAccountMember;
    static const QString BillDownloadToUploader;
    static const QString DeleteAfterNumberOfDownloads;
    static const QString DeleteAfterNumberOfDays;
    static const QString NotifyUploaderAfterDownload;

    static bool uploadFilePropertyValueToBoolean(QString value);
    static bool numericaUploadFilePropertyValueToBoolean(QString value);

};

#endif // UPLOADFILEPROPERTY_H
