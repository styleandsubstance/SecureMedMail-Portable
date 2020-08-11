/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "navigationhome.h"
#include "uploadfile.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *nextButton;
    QPushButton *backButton;
    QStackedWidget *containerWidget;
    NavigationHome *navigationHome;
    UploadFile *uploadFile;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(612, 424);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setEnabled(true);
        nextButton->setGeometry(QRect(150, 380, 75, 23));
        backButton = new QPushButton(centralWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setEnabled(false);
        backButton->setGeometry(QRect(60, 380, 75, 23));
        containerWidget = new QStackedWidget(centralWidget);
        containerWidget->setObjectName(QStringLiteral("containerWidget"));
        containerWidget->setGeometry(QRect(10, 10, 572, 351));
        navigationHome = new NavigationHome();
        navigationHome->setObjectName(QStringLiteral("navigationHome"));
        containerWidget->addWidget(navigationHome);
        uploadFile = new UploadFile();
        uploadFile->setObjectName(QStringLiteral("uploadFile"));
        containerWidget->addWidget(uploadFile);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 612, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        nextButton->setText(QApplication::translate("MainWindow", "Next ->", 0));
        backButton->setText(QApplication::translate("MainWindow", "<- Back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
