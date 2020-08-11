#include "extractionthread.h"

ExtractionThread::ExtractionThread(QString zipFilePath, QString extractionPath)
{
    this->zipFilePath = zipFilePath;
    this->extractionPath = extractionPath;
}

ExtractionThread::~ExtractionThread()
{

}

void ExtractionThread::run()
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

    success = zip.OpenZip(this->zipFilePath.toStdString().c_str());
    if (success != true)
    {
        qDebug() << zip.lastErrorText();
        delete zipProgress;
        return;
    }

    long unzipCount;

    unzipCount = zip.Unzip(this->extractionPath.toStdString().c_str());
    if (unzipCount < 0) {
        return;
    }
    else {
        return;
    }

    delete zipProgress;
}
