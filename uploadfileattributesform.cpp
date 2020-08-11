#include "uploadfileattributesform.h"

UploadFileAttributesForm::UploadFileAttributesForm(
        QString password,
       QString description,
       bool deleteAfterDownload,
       bool mustBeAuthenticated,
       bool mustBeAccountMember,
       bool billDownloadToUploader,
       bool deleteAfterNumberOfDownloads,
       unsigned int deleteAfterNumberOfDownloadsValue,
       bool deleteAfterNumberOfDays,
       unsigned int deleteAfterNumberOfDaysValue,
       bool notifyUploaderAfterDownload)
{
    this->password = password;
    this->description = description;
    this->deleteAfterDownload = deleteAfterDownload;
    this->mustBeAuthenticated = mustBeAuthenticated;
    this->mustBeAccountMember = mustBeAccountMember;
    this->billDownloadToUploader = billDownloadToUploader;
    this->deleteAfterNumberOfDownloads = deleteAfterNumberOfDownloads;
    this->deleteAfterNumberOfDownloadsValue = deleteAfterNumberOfDownloadsValue;
    this->deleteAfterNumberOfDays = deleteAfterNumberOfDays;
    this->deleteAfterNumberOfDaysValue = deleteAfterNumberOfDaysValue;
    this->notifyUploaderAfterDownload = notifyUploaderAfterDownload;
}

UploadFileAttributesForm::~UploadFileAttributesForm()
{

}

QString UploadFileAttributesForm::buildFormFieldName(QString propertyName)
{
   return "file_properties." + propertyName;
}


QMap<QString, QString> *UploadFileAttributesForm::buildDictionaryForPost()
{

   QMap<QString, QString> *values = new  QMap<QString, QString>();
   if (description.isNull() != false)
   {
       values->insert("description", description);
   }

   if (password.isNull() != false)
   {
       values->insert("password_hash", QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Algorithm::Sha256).toHex());
   }
   else
   {
       values->insert("password_hash", "");
   }

   if ( deleteAfterDownload == true )
   {
       values->insert(buildFormFieldName(UploadFileProperty::DeleteAfterDownload), "true");
   }

   if ( mustBeAuthenticated == true )
   {
       values->insert(buildFormFieldName(UploadFileProperty::MustBeAuthenticated), "true");
   }

   if (mustBeAccountMember == true)
   {
       values->insert(buildFormFieldName(UploadFileProperty::MustBeAccountMember), "true");
   }

   if (billDownloadToUploader == true)
   {

       values->insert(buildFormFieldName(UploadFileProperty::BillDownloadToUploader), "true");
   }

   if ( deleteAfterNumberOfDownloads == true )
   {
       values->insert(buildFormFieldName(UploadFileProperty::DeleteAfterNumberOfDownloads), QString::number(deleteAfterNumberOfDownloadsValue));
   }

   if (deleteAfterNumberOfDays == true)
   {
       values->insert(buildFormFieldName(UploadFileProperty::DeleteAfterNumberOfDays), QString::number(deleteAfterNumberOfDaysValue));
   }

   if (notifyUploaderAfterDownload == true)
   {
       values->insert(buildFormFieldName(UploadFileProperty::NotifyUploaderAfterDownload), "true");
   }

   return values;
}

QString UploadFileAttributesForm::getPassword()
{
   return password;
}
