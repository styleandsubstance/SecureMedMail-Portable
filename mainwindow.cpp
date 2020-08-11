#include "appsettings.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "navigationhome.h"
#include "logindialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QDebug>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->gridLayout->

    //NavigationHome *navigationHome = new NavigationHome(this);
    //navigationHome->show();
    //NavigationHome navigationHome;
    //navigationHome.show();

    //QUrl test("file:///C:/Users/sdoshi/Documents");

    //QDesktopServices::openUrl(test);


    qDebug() << WebServiceUrls::Authenticate();

    //loginDialog->setFocus();
   // loginDialog->raise();


    //loginDialog->raise();

    //loginDialog->activateWindow();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_nextButton_clicked()
{
    if ( this->ui->containerWidget->currentIndex() == 0) {



        NavigationHome *navigationHome = (NavigationHome *)this->ui->containerWidget->currentWidget();

        if ( navigationHome->isUploadFolderChecked()) {
            qDebug() << "User wants to upload a folder";
        }
        else if ( navigationHome->IsUploadChecked() ) {
            qDebug() << "User wants to upload a file";
            this->ui->containerWidget->setCurrentWidget(this->ui->uploadFile);
            this->ui->uploadFile->initialize();
            qDebug() << this->ui->containerWidget->currentIndex();
        }
        else if ( navigationHome->IsUploadDiscDriveChecked() ) {
            qDebug() << "User wants to upload a disc drive";
        }
        else {
            qDebug() << "User wants to download a file";
            this->ui->containerWidget->setCurrentWidget(this->ui->downloadFile);
        }
    }
    else if ( this->ui->containerWidget->currentIndex() == 1) {

        if ( this->ui->uploadFile->validate()) {
            this->ui->containerWidget->setCurrentWidget(this->ui->uploadProgress);
            this->ui->uploadProgress->Start(this->ui->uploadFile->buildUploadFileOrFolderForm());
        }
        else {
            //show the error message
        }
    }
    else if ( this->ui->containerWidget->currentIndex() == 3) {
        if ( this->ui->downloadFile->validate()) {
            this->ui->containerWidget->setCurrentWidget(this->ui->downloadProgress);
            this->ui->downloadProgress->Start(this->ui->downloadFile->buildDownloadFileForm());
        }
        else {
            //show the error message
        }
    }
}
