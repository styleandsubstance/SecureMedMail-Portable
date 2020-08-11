#-------------------------------------------------
#
# Project created by QtCreator 2015-03-16T17:44:16
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SecureMedMail
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    navigationhome.cpp \
    downloadsuccess.cpp \
    uploadfileoptions.cpp \
    uploadfileattributesform.cpp \
    uploadfileproperty.cpp \
    uploadprogress.cpp \
    uploadfile.cpp \
    httpsession.cpp \
    logindialog.cpp \
    zipthread.cpp \
    zipprogress.cpp \
    encryptionthread.cpp \
    uploadthread.cpp \
    encryptionprogress.cpp \
    uploadfileorfolderform.cpp \
    uploadsuccessdialog.cpp \
    downloadfile.cpp \
    guidfileproperties.cpp \
    downloadprogress.cpp \
    decryptionthread.cpp \
    extractionthread.cpp \
    chilkatencryptionprogress.cpp \
    monitorablethread.cpp \
    downloadthread.cpp \
    downloadfileform.cpp

HEADERS  += mainwindow.h \
    navigationhome.h \
    downloadsuccess.h \
    uploadfileoptions.h \
    uploadfileproperty.h \
    uploadprogress.h \
    appsettings.h \
    uploadfileattributesform.h \
    uploadfile.h \
    httpsession.h \
    logindialog.h \
    webserviceurls.h \
    zipthread.h \
    zipprogress.h \
    tempfile.h \
    encryptionthread.h \
    uploadthread.h \
    encryptionprogress.h \
    uploadfileorfolderform.h \
    uploadsuccessdialog.h \
    downloadfile.h \
    guidfileproperties.h \
    downloadprogress.h \
    decryptionthread.h \
    extractionthread.h \
    chilkatencryptionprogress.h \
    monitorablethread.h \
    downloadthread.h \
    downloadfileform.h

FORMS    += mainwindow.ui \
    navigationhome.ui \
    downloadsuccess.ui \
    uploadfileoptions.ui \
    uploadprogress.ui \
    uploadfile.ui \
    logindialog.ui \
    uploadsuccessdialog.ui \
    downloadfile.ui \
    downloadprogress.ui

RESOURCES +=

unix|win32: LIBS += -L$$PWD/../../../Applications/Chilkat/chilkat-9.5.0-x86-vc12/libs/ -lChilkatRel

INCLUDEPATH += $$PWD/../../../Applications/Chilkat/chilkat-9.5.0-x86-vc12/include
DEPENDPATH += $$PWD/../../../Applications/Chilkat/chilkat-9.5.0-x86-vc12/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../../Applications/Chilkat/chilkat-9.5.0-x86-vc12/libs/ChilkatRel.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../../../Applications/Chilkat/chilkat-9.5.0-x86-vc12/libs/libChilkatRel.a

win32:LIBS += -L"C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Lib/" -lAdvapi32 -lws2_32 -lcrypt32 -lrpcrt4 -ldnsapi -lwininet
