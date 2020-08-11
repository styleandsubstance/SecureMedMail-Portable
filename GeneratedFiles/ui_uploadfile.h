/********************************************************************************
** Form generated from reading UI file 'uploadfile.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADFILE_H
#define UI_UPLOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "uploadfileoptions.h"

QT_BEGIN_NAMESPACE

class Ui_UploadFile
{
public:
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *pushButton;
    UploadFileOptions *uploadFileOptions;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName(QStringLiteral("UploadFile"));
        UploadFile->resize(599, 324);
        label = new QLabel(UploadFile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 47, 13));
        filePath = new QLineEdit(UploadFile);
        filePath->setObjectName(QStringLiteral("filePath"));
        filePath->setGeometry(QRect(120, 25, 251, 20));
        pushButton = new QPushButton(UploadFile);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 25, 75, 23));
        uploadFileOptions = new UploadFileOptions(UploadFile);
        uploadFileOptions->setObjectName(QStringLiteral("uploadFileOptions"));
        uploadFileOptions->setGeometry(QRect(0, 50, 601, 271));

        retranslateUi(UploadFile);

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QApplication::translate("UploadFile", "Form", 0));
        label->setText(QApplication::translate("UploadFile", "File:", 0));
        pushButton->setText(QApplication::translate("UploadFile", "Browse", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
