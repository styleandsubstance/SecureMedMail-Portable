#include "downloadprogress.h"
#include "ui_downloadprogress.h"

DownloadProgress::DownloadProgress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadProgress)
{
    ui->setupUi(this);
}

DownloadProgress::~DownloadProgress()
{
    delete ui;
}

void DownloadProgress::Start(DownloadFileForm *downloadFileForm)
{
    this->downloadFileForm = downloadFileForm;
    this->downloadedFile = TempFile::GetTempFilePathWithExtension(".tmp");
    this->decryptedFile = TempFile::GetTempFilePathWithExtension(".tmp");


    qDebug() << "Downloading file: " << this->downloadFileForm->guid << " to location: " << this->downloadedFile << endl;

    downloadThread = new DownloadThread(this->downloadFileForm->guid, this->downloadedFile);

    QObject::connect( downloadThread, SIGNAL( Progress(int) ),
            this, SLOT( setDownloadProgressBar(int) ) );

    QObject::connect( downloadThread, SIGNAL( DownloadSuccess(QString, QString) ),
            this, SLOT( DownloadSuccess(QString, QString) ) );

    QObject::connect( downloadThread, SIGNAL( finished() ),
            this, SLOT( DownloadFinished() ) );

    downloadThread->start();
}

void DownloadProgress::DownloadSuccess(QString guid, QString filename)
{
    this->guid = guid;
    this->extractionPath = QDir(this->downloadFileForm->extractionFolderPath).filePath(filename);

}

void DownloadProgress::DownloadFinished()
{
    qDebug() << "Download Finished";

    qDebug() << "Decrypting file: " << this->downloadedFile << " to location: " << this->decryptedFile;

    decryptionThread = new DecryptionThread(this->downloadFileForm->password,
                             this->downloadedFile,
                             this->decryptedFile);

    QObject::connect( decryptionThread, SIGNAL( Progress(int) ),
            this, SLOT( setDecryptionProgressBar(int) ) );

    QObject::connect( decryptionThread, SIGNAL( finished() ),
            this, SLOT( DecryptionFinished() ) );

    decryptionThread->start();

}


void DownloadProgress::DecryptionFinished()
{
    qDebug() << "Decryption Finished";
    extractionThread = new ExtractionThread(this->decryptedFile, this->extractionPath);

    QObject::connect( extractionThread, SIGNAL( Progress(int) ),
            this, SLOT( setExtractionProgressBar(int) ) );

    QObject::connect( extractionThread, SIGNAL( finished() ),
            this, SLOT( ExtractionFinished() ) );

    extractionThread->start();
}

void DownloadProgress::ExtractionFinished()
{

    qDebug() << "Extraction Finished: " << guid ;

//    DownloadSuccessDialog *downloadSuccessDialog = new DownloadSuccessDialog(this);
//    //uploadSuccessDialog->setGuid(guid);
//    downloadSuccessDialog->show();
}

void DownloadProgress::setDownloadProgressBar(int val)
{
    this->ui->downloadProgressBar->setValue(val);
}

void DownloadProgress::setDecryptionProgressBar(int val)
{
    this->ui->decryptionProgressBar->setValue(val);
}

void DownloadProgress::setExtractionProgressBar(int val)
{
    this->ui->extractionProgressBar->setValue(val);
}
