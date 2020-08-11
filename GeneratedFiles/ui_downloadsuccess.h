/********************************************************************************
** Form generated from reading UI file 'downloadsuccess.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADSUCCESS_H
#define UI_DOWNLOADSUCCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DownloadSuccess
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DownloadSuccess)
    {
        if (DownloadSuccess->objectName().isEmpty())
            DownloadSuccess->setObjectName(QStringLiteral("DownloadSuccess"));
        DownloadSuccess->resize(388, 152);
        buttonBox = new QDialogButtonBox(DownloadSuccess);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 100, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);

        retranslateUi(DownloadSuccess);
        QObject::connect(buttonBox, SIGNAL(accepted()), DownloadSuccess, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DownloadSuccess, SLOT(reject()));

        QMetaObject::connectSlotsByName(DownloadSuccess);
    } // setupUi

    void retranslateUi(QDialog *DownloadSuccess)
    {
        DownloadSuccess->setWindowTitle(QApplication::translate("DownloadSuccess", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DownloadSuccess: public Ui_DownloadSuccess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADSUCCESS_H
