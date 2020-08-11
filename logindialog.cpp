#include "logindialog.h"
#include "ui_logindialog.h"
#include "httpsession.h"


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    QString username = this->ui->usernameTextBox->text();
    QString password = this->ui->passwordTextBox->text();

    HttpSession::getSession()->Authenticate(username, password);

    this->close();
}
