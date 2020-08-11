#include "zipthread.h"
//#include "zipprogress.h"

ZipThread::ZipThread(QString path,  QString zipPath)
{
    this->path = path;
    this->zipPath = zipPath;
}

ZipThread::~ZipThread()
{

}

void ZipThread::run()
{
    CkZip zip;

    bool success;

    //  Any string unlocks the component for the 1st 30-days.
    success = zip.UnlockComponent("SACHINZIP_OOwCpDzypRtP");
    if (success != true)
    {
        qDebug() << zip.lastErrorText();
        return;
    }

    ZipProgress *zipProgress = new ZipProgress();
    zipProgress->setThread((MonitorableThread *)this);
    zip.put_EventCallbackObject((CkZipProgress *)zipProgress);

    success = zip.NewZip(this->zipPath.toStdString().c_str());
    if (success != true)
    {
        qDebug() << zip.lastErrorText();
        delete zipProgress;
        return;
    }

    if ( QDir(this->path).exists() ) {
        bool recurse = true;
        QString directoryWildCard = this->path + "\\*";

        //success = zip.AppendFiles("C:\\Users\\sdoshi\\Desktop\\Pics\\*", recurse);
        success = zip.AppendFiles(directoryWildCard.toStdString().c_str(), recurse);
        if (success != true)
        {
            qDebug() << zip.lastErrorText();
            delete zipProgress;
            return;
        }
    }
    else {
        bool saveExtraPath = false;
        success = zip.AppendOneFileOrDir(this->path.toStdString().c_str(), saveExtraPath);
        if (success != true)
        {
            qDebug() << zip.lastErrorText();
            delete zipProgress;
            return;
        }
    }

    success = zip.WriteZipAndClose();
    if (success != true)
    {
        qDebug() << zip.lastErrorText();
        delete zipProgress;
        return;
    }

    delete zipProgress;

}

//void ZipThread::ReportProgress(int pctDone)
//{
//    emit Progress(pctDone);
//}
