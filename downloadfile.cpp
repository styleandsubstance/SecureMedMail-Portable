#include "downloadfile.h"
#include "ui_downloadfile.h"

DownloadFile::DownloadFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadFile)
{
    ui->setupUi(this);
}

DownloadFile::~DownloadFile()
{
    delete ui;
}

void DownloadFile::on_pushButton_clicked()
{
    QFileDialog *dialog = new QFileDialog(this);

    dialog->setFileMode(QFileDialog::DirectoryOnly);

//    QObject::connect( dialog, SIGNAL( Progress(int) ),
//            this, SLOT( setCompressionProgressBar(int) ) );

    dialog->exec();

    if ( dialog->selectedFiles().length() > 0 ) {
        qDebug() << "User selected file: " << dialog->selectedFiles().first();

        this->ui->filePath->setText(dialog->selectedFiles().first());
    }

    delete dialog;
}



bool DownloadFile::validate()
{
    return true;
}

DownloadFileForm *DownloadFile::buildDownloadFileForm()
{
    DownloadFileForm *downloadFileForm = new DownloadFileForm(this->ui->filePath->text(),
                                                              this->ui->guid->text(),
                                                              this->ui->password->text());
    return downloadFileForm;
}
