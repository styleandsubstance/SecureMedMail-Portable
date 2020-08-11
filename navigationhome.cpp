#include "navigationhome.h"
#include "ui_navigationhome.h"

NavigationHome::NavigationHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavigationHome)
{
    ui->setupUi(this);
}

NavigationHome::~NavigationHome()
{
    delete ui;
}


bool NavigationHome::IsDownloadChecked()
{
    return ui->downloadRadioButton->isChecked();
}

bool NavigationHome::IsUploadChecked()
{
    return ui->uploadRadioButton->isChecked();
}

bool NavigationHome::IsUploadDiscDriveChecked()
{
    return ui->uploadDiscDriveRadioButton->isChecked();
}

bool NavigationHome::isUploadFolderChecked()
{
    return ui->uploadFolderRadioButton->isChecked();
}
