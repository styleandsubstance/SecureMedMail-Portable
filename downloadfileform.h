#ifndef DOWNLOADFILEFORM_H
#define DOWNLOADFILEFORM_H

#include <QString>

class DownloadFileForm
{
public:
    QString extractionFolderPath;
    QString guid;
    QString password;


    DownloadFileForm(QString extractionFolderPath, QString guid, QString password);
    ~DownloadFileForm();
};

#endif // DOWNLOADFILEFORM_H
