#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>

class AppSettings
{
public:
    enum UploadFileOption {
        BILL_TO_DOWNLOADING_USER,
        BILL_TO_MY_ACCOUNT,
        DELETE_FILE_AFTER_NUMBER_OF_DAYS,
        DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS,
        DELETE_FILE_IMMEDIATELY,
        DOWNLOAD_FOR_ANYONE,
        DOWNLOAD_FOR_MEMBERS_ONLY,
        DOWNLOAD_FOR_REGISTERED_USERS
    };

    enum WebServiceUrl {
        AccountCreate,
        Authenticate,
        ConfirmDownloadByGuid,
        DownloadFile,
        GetFilePropertiesByGuid,
        GetUserFilePropertyProfiles,
        ServerUrl,
        UploadFile,
        VerifyFilePasswordHash
    };

    static QString getValue(UploadFileOption val) {
        static const std::pair<UploadFileOption, QString> arr[] = {
            std::pair<UploadFileOption, QString>(BILL_TO_DOWNLOADING_USER,              "Account of user who downloded the file"),
            std::pair<UploadFileOption, QString>(BILL_TO_MY_ACCOUNT,                    "My account"),
            std::pair<UploadFileOption, QString>(DELETE_FILE_AFTER_NUMBER_OF_DAYS,      "After a set number of days"),
            std::pair<UploadFileOption, QString>(DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS, "After a set number of downloads"),
            std::pair<UploadFileOption, QString>(DELETE_FILE_IMMEDIATELY,               "Immediately after it has been downloaded"),
            std::pair<UploadFileOption, QString>(DOWNLOAD_FOR_ANYONE,                   "Anonymous - Anyone with GUID/Password"),
            std::pair<UploadFileOption, QString>(DOWNLOAD_FOR_MEMBERS_ONLY,             "Members of my account only"),
            std::pair<UploadFileOption, QString>(DOWNLOAD_FOR_REGISTERED_USERS,         "Any registered SecureMedMail user")
        };


        return arr[(int)val].second;

    }

    static QString getValue(WebServiceUrl val) {
        static const std::pair<WebServiceUrl, QString> arr[] = {
            std::pair<WebServiceUrl, QString>(AccountCreate,               "/account/new"),
            std::pair<WebServiceUrl, QString>(Authenticate,                "/account/authenticate"),
            std::pair<WebServiceUrl, QString>(ConfirmDownloadByGuid,       "/file/confirmDownloadByGuid"),
            std::pair<WebServiceUrl, QString>(DownloadFile,                "/download"),
            std::pair<WebServiceUrl, QString>(GetFilePropertiesByGuid,     "/file/getFilePropertiesByGuid"),
            std::pair<WebServiceUrl, QString>(GetUserFilePropertyProfiles, "/account/profile/getAllProfiles"),
            std::pair<WebServiceUrl, QString>(ServerUrl,                   "http://localhost:9000"),
            std::pair<WebServiceUrl, QString>(UploadFile,                  "/putFile"),
            std::pair<WebServiceUrl, QString>(VerifyFilePasswordHash,      "/file/verifyFilePasswordHash")
        };


        return arr[(int)val].second;
    }
};

#endif // APPSETTINGS_H

