#include "downloadfileform.h"

DownloadFileForm::DownloadFileForm(QString extractionFolderPath, QString guid, QString password)
{
    this->extractionFolderPath = extractionFolderPath;
    this->guid = guid;
    this->password = password;
}

DownloadFileForm::~DownloadFileForm()
{

}

