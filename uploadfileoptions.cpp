#include "uploadfileoptions.h"
#include "ui_uploadfileoptions.h"

UploadFileOptions::UploadFileOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadFileOptions)
{
    ui->setupUi(this);
    this->ui->deletionValue->hide();

    ui->downloadAllowedForComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_MEMBERS_ONLY));
    ui->downloadAllowedForComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_REGISTERED_USERS));
    ui->downloadAllowedForComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_ANYONE));


    ui->deletionComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_IMMEDIATELY));
    ui->deletionComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DAYS));
    ui->deletionComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS));

    ui->billingComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::BILL_TO_MY_ACCOUNT));
    ui->billingComboBox->addItem(AppSettings::getValue(AppSettings::UploadFileOption::BILL_TO_DOWNLOADING_USER));

}

UploadFileOptions::~UploadFileOptions()
{
    delete ui;
}

UploadFileAttributesForm *UploadFileOptions::buildUploadForm()
{
    unsigned int deleteAfterNumberOfDownloads = 0;
    unsigned int deleteAfterNumberOfDays = 0;

    if (this->ui->deletionComboBox->currentText() ==
            AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS))
    {
        deleteAfterNumberOfDownloads = (unsigned int)this->ui->deletionValue->value();
    }

    if (this->ui->deletionComboBox->currentText() ==
            AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DAYS))
    {
        deleteAfterNumberOfDays = (unsigned int)this->ui->deletionValue->value();
    }

    UploadFileAttributesForm *uploadFileAttributesForm = new UploadFileAttributesForm(
        this->ui->passwordTextBox->text(),
        this->ui->descriptionTextBox->toPlainText(),
        this->ui->deletionComboBox->currentText()== AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_IMMEDIATELY),
        this->ui->downloadAllowedForComboBox->currentText() == AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_MEMBERS_ONLY) ||
            this->ui->downloadAllowedForComboBox->currentText() == AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_REGISTERED_USERS),
        this->ui->downloadAllowedForComboBox->currentText() == AppSettings::getValue(AppSettings::UploadFileOption::DOWNLOAD_FOR_MEMBERS_ONLY),
        this->ui->billingComboBox->currentText() == AppSettings::getValue(AppSettings::UploadFileOption::BILL_TO_MY_ACCOUNT),
        this->ui->deletionComboBox->currentText() == AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS),
        deleteAfterNumberOfDownloads,
        this->ui->deletionComboBox->currentText()== AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DAYS),
        deleteAfterNumberOfDays,
        this->ui->notifyUploaderAfterDownloadCheckbox->isChecked());

   return uploadFileAttributesForm;
}

void UploadFileOptions::on_deletionComboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DOWNLOADS))
    {
        this->ui->deletionValue->show();
        this->ui->deletionLabel->setText("downloads");
        //this.deletionLabel.Text = "downloads";
    }
    else if (arg1 == AppSettings::getValue(AppSettings::UploadFileOption::DELETE_FILE_AFTER_NUMBER_OF_DAYS))
    {
        this->ui->deletionValue->show();
        this->ui->deletionLabel->setText("days");
        //this.deletionLabel.Text = "days";
    }
    else
    {
        this->ui->deletionValue->hide();
        this->ui->deletionLabel->setText("");
        //this.deletionTextValue.Visible = false;
        //this.deletionLabel.Text = "";
    }
}
