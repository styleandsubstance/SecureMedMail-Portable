#include "uploadfile.h"
#include "ui_uploadfile.h"
#include <QFileDialog>
#include <QDebug>

UploadFile::UploadFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadFile)
{
    ui->setupUi(this);
}

UploadFile::~UploadFile()
{
    delete ui;
}

void UploadFile::on_pushButton_clicked()
{
    QFileDialog *dialog = new QFileDialog(this);

    dialog->setFileMode(QFileDialog::AnyFile);

//    QObject::connect( dialog, SIGNAL( Progress(int) ),
//            this, SLOT( setCompressionProgressBar(int) ) );

    dialog->exec();

    if ( dialog->selectedFiles().length() > 0 ) {
        qDebug() << "User selected file: " << dialog->selectedFiles().first();

        this->ui->filePath->setText(dialog->selectedFiles().first());
    }




}

void UploadFile::initialize()
{

    LoginDialog *loginDialog = new LoginDialog(this);

    //loginDialog->setWindowFlags( ( (loginDialog->windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint) );

    loginDialog->exec();
}

bool UploadFile::validate()
{
    return true;
}

UploadFileOrFolderForm *UploadFile::buildUploadFileOrFolderForm()
{
    return new UploadFileOrFolderForm(this->ui->filePath->text(),
        this->ui->uploadFileOptions->buildUploadForm());
}
