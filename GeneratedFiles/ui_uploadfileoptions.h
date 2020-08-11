/********************************************************************************
** Form generated from reading UI file 'uploadfileoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADFILEOPTIONS_H
#define UI_UPLOADFILEOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadFileOptions
{
public:
    QLabel *label;
    QLineEdit *passwordTextBox;
    QLabel *label_2;
    QLineEdit *confirmPasswordTextBox;
    QLabel *label_3;
    QPlainTextEdit *descriptionTextBox;
    QComboBox *downloadAllowedForComboBox;
    QComboBox *deletionComboBox;
    QComboBox *billingComboBox;
    QCheckBox *notifyUploaderAfterDownloadCheckbox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *deletionValue;
    QLabel *deletionLabel;

    void setupUi(QWidget *UploadFileOptions)
    {
        if (UploadFileOptions->objectName().isEmpty())
            UploadFileOptions->setObjectName(QStringLiteral("UploadFileOptions"));
        UploadFileOptions->resize(572, 260);
        label = new QLabel(UploadFileOptions);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 61, 16));
        passwordTextBox = new QLineEdit(UploadFileOptions);
        passwordTextBox->setObjectName(QStringLiteral("passwordTextBox"));
        passwordTextBox->setGeometry(QRect(120, 10, 151, 20));
        passwordTextBox->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(UploadFileOptions);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 101, 20));
        confirmPasswordTextBox = new QLineEdit(UploadFileOptions);
        confirmPasswordTextBox->setObjectName(QStringLiteral("confirmPasswordTextBox"));
        confirmPasswordTextBox->setGeometry(QRect(120, 40, 151, 20));
        confirmPasswordTextBox->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(UploadFileOptions);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 71, 20));
        descriptionTextBox = new QPlainTextEdit(UploadFileOptions);
        descriptionTextBox->setObjectName(QStringLiteral("descriptionTextBox"));
        descriptionTextBox->setGeometry(QRect(120, 70, 251, 41));
        downloadAllowedForComboBox = new QComboBox(UploadFileOptions);
        downloadAllowedForComboBox->setObjectName(QStringLiteral("downloadAllowedForComboBox"));
        downloadAllowedForComboBox->setGeometry(QRect(120, 120, 251, 22));
        deletionComboBox = new QComboBox(UploadFileOptions);
        deletionComboBox->setObjectName(QStringLiteral("deletionComboBox"));
        deletionComboBox->setGeometry(QRect(120, 160, 251, 22));
        billingComboBox = new QComboBox(UploadFileOptions);
        billingComboBox->setObjectName(QStringLiteral("billingComboBox"));
        billingComboBox->setGeometry(QRect(120, 200, 251, 22));
        notifyUploaderAfterDownloadCheckbox = new QCheckBox(UploadFileOptions);
        notifyUploaderAfterDownloadCheckbox->setObjectName(QStringLiteral("notifyUploaderAfterDownloadCheckbox"));
        notifyUploaderAfterDownloadCheckbox->setGeometry(QRect(120, 240, 16, 17));
        label_4 = new QLabel(UploadFileOptions);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 114, 81, 31));
        label_4->setWordWrap(true);
        label_5 = new QLabel(UploadFileOptions);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 162, 81, 20));
        label_6 = new QLabel(UploadFileOptions);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 193, 81, 31));
        label_6->setWordWrap(true);
        label_7 = new QLabel(UploadFileOptions);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 230, 81, 31));
        label_7->setWordWrap(true);
        deletionValue = new QSpinBox(UploadFileOptions);
        deletionValue->setObjectName(QStringLiteral("deletionValue"));
        deletionValue->setEnabled(true);
        deletionValue->setGeometry(QRect(390, 160, 42, 22));
        deletionValue->setValue(1);
        deletionLabel = new QLabel(UploadFileOptions);
        deletionLabel->setObjectName(QStringLiteral("deletionLabel"));
        deletionLabel->setGeometry(QRect(440, 164, 61, 16));

        retranslateUi(UploadFileOptions);

        QMetaObject::connectSlotsByName(UploadFileOptions);
    } // setupUi

    void retranslateUi(QWidget *UploadFileOptions)
    {
        UploadFileOptions->setWindowTitle(QApplication::translate("UploadFileOptions", "Form", 0));
        label->setText(QApplication::translate("UploadFileOptions", "Password:", 0));
        label_2->setText(QApplication::translate("UploadFileOptions", "Confirm Password:", 0));
        label_3->setText(QApplication::translate("UploadFileOptions", "Description:", 0));
        notifyUploaderAfterDownloadCheckbox->setText(QString());
        label_4->setText(QApplication::translate("UploadFileOptions", "Downloads are allowed for:", 0));
        label_5->setText(QApplication::translate("UploadFileOptions", "Delete this file:", 0));
        label_6->setText(QApplication::translate("UploadFileOptions", "Bill downloads of this file to:", 0));
        label_7->setText(QApplication::translate("UploadFileOptions", "E-mail me after file downloaded:", 0));
        deletionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UploadFileOptions: public Ui_UploadFileOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILEOPTIONS_H
