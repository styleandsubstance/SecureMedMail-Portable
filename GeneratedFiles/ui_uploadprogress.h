/********************************************************************************
** Form generated from reading UI file 'uploadprogress.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADPROGRESS_H
#define UI_UPLOADPROGRESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadProgress
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QProgressBar *compressionProgressBar;
    QProgressBar *encryptionProgressBar;
    QProgressBar *uploadProgressBar;

    void setupUi(QWidget *UploadProgress)
    {
        if (UploadProgress->objectName().isEmpty())
            UploadProgress->setObjectName(QStringLiteral("UploadProgress"));
        UploadProgress->resize(572, 185);
        label = new QLabel(UploadProgress);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 121, 16));
        label_2 = new QLabel(UploadProgress);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 121, 16));
        label_3 = new QLabel(UploadProgress);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 121, 16));
        compressionProgressBar = new QProgressBar(UploadProgress);
        compressionProgressBar->setObjectName(QStringLiteral("compressionProgressBar"));
        compressionProgressBar->setGeometry(QRect(170, 20, 331, 23));
        compressionProgressBar->setValue(0);
        encryptionProgressBar = new QProgressBar(UploadProgress);
        encryptionProgressBar->setObjectName(QStringLiteral("encryptionProgressBar"));
        encryptionProgressBar->setGeometry(QRect(170, 70, 331, 23));
        encryptionProgressBar->setValue(0);
        uploadProgressBar = new QProgressBar(UploadProgress);
        uploadProgressBar->setObjectName(QStringLiteral("uploadProgressBar"));
        uploadProgressBar->setGeometry(QRect(170, 120, 331, 23));
        uploadProgressBar->setValue(0);

        retranslateUi(UploadProgress);

        QMetaObject::connectSlotsByName(UploadProgress);
    } // setupUi

    void retranslateUi(QWidget *UploadProgress)
    {
        UploadProgress->setWindowTitle(QApplication::translate("UploadProgress", "Form", 0));
        label->setText(QApplication::translate("UploadProgress", "Compression Progress:", 0));
        label_2->setText(QApplication::translate("UploadProgress", "Encryption Progress:", 0));
        label_3->setText(QApplication::translate("UploadProgress", "Upload Progress:", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadProgress: public Ui_UploadProgress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADPROGRESS_H
