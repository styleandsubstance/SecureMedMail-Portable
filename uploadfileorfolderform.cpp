#include "uploadfileorfolderform.h"

UploadFileOrFolderForm::UploadFileOrFolderForm(QString filepath, UploadFileAttributesForm *uploadFileAttributesForm)
{
    this->filepath = filepath;
    this->uploadFileAttributesForm = uploadFileAttributesForm;
}

UploadFileOrFolderForm::~UploadFileOrFolderForm()
{

}

