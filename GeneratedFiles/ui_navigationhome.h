/********************************************************************************
** Form generated from reading UI file 'navigationhome.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATIONHOME_H
#define UI_NAVIGATIONHOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NavigationHome
{
public:
    QLabel *label;
    QLabel *label_2;
    QRadioButton *uploadDiscDriveRadioButton;
    QRadioButton *uploadRadioButton;
    QRadioButton *uploadFolderRadioButton;
    QRadioButton *downloadRadioButton;

    void setupUi(QWidget *NavigationHome)
    {
        if (NavigationHome->objectName().isEmpty())
            NavigationHome->setObjectName(QStringLiteral("NavigationHome"));
        NavigationHome->resize(572, 331);
        label = new QLabel(NavigationHome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 381, 61));
        QFont font;
        font.setFamily(QStringLiteral("MS Sans Serif"));
        font.setPointSize(48);
        label->setFont(font);
        label_2 = new QLabel(NavigationHome);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 351, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Sans Serif"));
        font1.setPointSize(16);
        label_2->setFont(font1);
        uploadDiscDriveRadioButton = new QRadioButton(NavigationHome);
        uploadDiscDriveRadioButton->setObjectName(QStringLiteral("uploadDiscDriveRadioButton"));
        uploadDiscDriveRadioButton->setGeometry(QRect(50, 160, 121, 17));
        QFont font2;
        font2.setPointSize(10);
        uploadDiscDriveRadioButton->setFont(font2);
        uploadDiscDriveRadioButton->setChecked(true);
        uploadRadioButton = new QRadioButton(NavigationHome);
        uploadRadioButton->setObjectName(QStringLiteral("uploadRadioButton"));
        uploadRadioButton->setGeometry(QRect(50, 180, 101, 17));
        uploadRadioButton->setFont(font2);
        uploadFolderRadioButton = new QRadioButton(NavigationHome);
        uploadFolderRadioButton->setObjectName(QStringLiteral("uploadFolderRadioButton"));
        uploadFolderRadioButton->setGeometry(QRect(50, 200, 121, 17));
        uploadFolderRadioButton->setFont(font2);
        downloadRadioButton = new QRadioButton(NavigationHome);
        downloadRadioButton->setObjectName(QStringLiteral("downloadRadioButton"));
        downloadRadioButton->setGeometry(QRect(50, 220, 131, 17));
        downloadRadioButton->setFont(font2);

        retranslateUi(NavigationHome);

        QMetaObject::connectSlotsByName(NavigationHome);
    } // setupUi

    void retranslateUi(QWidget *NavigationHome)
    {
        NavigationHome->setWindowTitle(QApplication::translate("NavigationHome", "Form", 0));
        label->setText(QApplication::translate("NavigationHome", "Welcome", 0));
        label_2->setText(QApplication::translate("NavigationHome", "What would you like to do?", 0));
        uploadDiscDriveRadioButton->setText(QApplication::translate("NavigationHome", "Upload Disc Drive", 0));
        uploadRadioButton->setText(QApplication::translate("NavigationHome", "Upload a File", 0));
        uploadFolderRadioButton->setText(QApplication::translate("NavigationHome", "Upload a Folder", 0));
        downloadRadioButton->setText(QApplication::translate("NavigationHome", "Download a File", 0));
    } // retranslateUi

};

namespace Ui {
    class NavigationHome: public Ui_NavigationHome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATIONHOME_H
