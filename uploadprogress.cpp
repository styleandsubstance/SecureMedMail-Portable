#include "uploadprogress.h"
#include "ui_uploadprogress.h"

UploadProgress::UploadProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadProgress)
{
    ui->setupUi(this);
}

UploadProgress::~UploadProgress()
{
    delete ui;
}


void UploadProgress::Start(UploadFileOrFolderForm *uploadFileOrFolderForm)
{
    //this->filePath = filePath;
    //this->fileName = fileName;
    this->uploadFileOrFolderForm = uploadFileOrFolderForm;
    this->compressedFile = TempFile::GetTempFilePathWithExtension(".tmp");
    this->encryptedFile = TempFile::GetTempFilePathWithExtension(".tmp");


    qDebug() << "Compressiong file/foloder: " << this->uploadFileOrFolderForm->filepath << " to location: " << this->compressedFile << endl;

    //start the zip thread.
    z = new ZipThread(this->uploadFileOrFolderForm->filepath, this->compressedFile);

    QObject::connect( z, SIGNAL( Progress(int) ),
            this, SLOT( setCompressionProgressBar(int) ) );

    QObject::connect( z, SIGNAL( finished() ),
            this, SLOT( CompressionFinished() ) );

    z->start();
}

void UploadProgress::CompressionFinished()
{
    qDebug() << "Compression Finished";

    qDebug() << "Encrypting file: " << this->compressedFile << " to location: " << this->encryptedFile << endl;

    e = new EncryptionThread(this->uploadFileOrFolderForm->uploadFileAttributesForm->password,
                             this->compressedFile,
                             this->encryptedFile);

    QObject::connect( e, SIGNAL( Progress(int) ),
            this, SLOT( setEncryptionProgressBar(int) ) );

    QObject::connect( e, SIGNAL( finished() ),
            this, SLOT( EncryptionFinished() ) );

    e->start();

}


void UploadProgress::EncryptionFinished()
{
    qDebug() << "Encryption Finished";
    u = new UploadThread(this->uploadFileOrFolderForm->uploadFileAttributesForm, "SachinDoshi.txt", this->encryptedFile);

    QObject::connect( u, SIGNAL( Progress(int) ),
            this, SLOT( setUploadProgressBar(int) ) );

    QObject::connect( u, SIGNAL( UploadSuccess(QString) ),
            this, SLOT( UploadFinished(QString) ) );

    u->start();
}

void UploadProgress::UploadFinished(QString guid)
{

    qDebug() << "Upload Finshed: " << guid ;

    UploadSuccessDialog *uploadSuccessDialog = new UploadSuccessDialog(this);
    uploadSuccessDialog->setGuid(guid);
    uploadSuccessDialog->show();


}

void UploadProgress::setCompressionProgressBar(int val)
{
    this->ui->compressionProgressBar->setValue(val);
}

void UploadProgress::setEncryptionProgressBar(int val)
{
    this->ui->encryptionProgressBar->setValue(val);
}

void UploadProgress::setUploadProgressBar(int val)
{
    this->ui->uploadProgressBar->setValue(val);
}
