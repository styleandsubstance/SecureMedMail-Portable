#ifndef UPLOADFILEORFOLDERFORM_H
#define UPLOADFILEORFOLDERFORM_H

#include <QString>
#include "uploadfileattributesform.h"

class UploadFileOrFolderForm
{
public:
    QString filepath;
    UploadFileAttributesForm *uploadFileAttributesForm;

    UploadFileOrFolderForm(QString filepath, UploadFileAttributesForm *uploadFileAttributesForm);
    ~UploadFileOrFolderForm();
};

#endif // UPLOADFILEORFOLDERFORM_H
