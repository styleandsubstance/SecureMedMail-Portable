/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLineEdit *usernameTextBox;
    QLineEdit *passwordTextBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 144);
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 51, 16));
        usernameTextBox = new QLineEdit(LoginDialog);
        usernameTextBox->setObjectName(QStringLiteral("usernameTextBox"));
        usernameTextBox->setGeometry(QRect(110, 30, 191, 20));
        passwordTextBox = new QLineEdit(LoginDialog);
        passwordTextBox->setObjectName(QStringLiteral("passwordTextBox"));
        passwordTextBox->setGeometry(QRect(110, 60, 191, 20));
        passwordTextBox->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 51, 16));
        pushButton = new QPushButton(LoginDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 100, 75, 23));
        pushButton_2 = new QPushButton(LoginDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 100, 75, 23));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", 0));
        label->setText(QApplication::translate("LoginDialog", "Username:", 0));
        label_2->setText(QApplication::translate("LoginDialog", "Password:", 0));
        pushButton->setText(QApplication::translate("LoginDialog", "Login", 0));
        pushButton_2->setText(QApplication::translate("LoginDialog", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
