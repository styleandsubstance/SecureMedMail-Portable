#include "uploadfileproperty.h"

UploadFileProperty::UploadFileProperty()
{

}

UploadFileProperty::~UploadFileProperty()
{

}

const QString UploadFileProperty::DeleteAfterDownload = "DeleteAfterDownload";
const QString UploadFileProperty::MustBeAuthenticated = "MustBeAuthenticated";
const QString UploadFileProperty::MustBeAccountMember = "MustBeAccountMember";
const QString UploadFileProperty::BillDownloadToUploader = "BillDownloadToUploader";
const QString UploadFileProperty::DeleteAfterNumberOfDownloads = "DeleteAfterNumberOfDownloads";
const QString UploadFileProperty::DeleteAfterNumberOfDays = "DeleteAfterNumberOfDays";
const QString UploadFileProperty::NotifyUploaderAfterDownload = "NotifyUploaderAfterDownload";


bool UploadFileProperty::uploadFilePropertyValueToBoolean(QString value)
{
    if (value.isNull() == false)
        return (value == "true");

    return false;
}

bool UploadFileProperty::numericaUploadFilePropertyValueToBoolean(QString value)
{
    if (value.isNull())
    {
        return false;
    }

    return true;
}
