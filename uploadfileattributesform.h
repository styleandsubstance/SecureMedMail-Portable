#ifndef UPLOADFILEATTRIBUTESFORM_H
#define UPLOADFILEATTRIBUTESFORM_H

#include <QString>
#include <QMap>
#include <QCryptographicHash>

#include "uploadfileproperty.h"

class UploadFileAttributesForm
{
public:
    UploadFileAttributesForm(QString password,
                             QString description,
                             bool deleteAfterDownload,
                             bool mustBeAuthenticated,
                             bool mustBeAccountMember,
                             bool billDownloadToUploader,
                             bool deleteAfterNumberOfDownloads,
                             unsigned int deleteAfterNumberOfDownloadsValue,
                             bool deleteAfterNumberOfDays,
                             unsigned int deleteAfterNumberOfDaysValue,
                             bool notifyUploaderAfterDownload);
    ~UploadFileAttributesForm();

    QString password;
    QString description;

    bool deleteAfterDownload;
    bool mustBeAuthenticated;
    bool mustBeAccountMember;
    bool billDownloadToUploader;
    bool deleteAfterNumberOfDownloads;
    unsigned int deleteAfterNumberOfDownloadsValue;
    bool deleteAfterNumberOfDays;
    unsigned int deleteAfterNumberOfDaysValue;
    bool notifyUploaderAfterDownload;

    QString getPassword();

    QMap<QString, QString> *buildDictionaryForPost();

private:
    QString buildFormFieldName(QString propertyName);

};

#endif // UPLOADFILEATTRIBUTESFORM_H
