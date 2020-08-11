#ifndef ZIPTHREAD_H
#define ZIPTHREAD_H

#include <QTCore>
#include <QDebug>
#include <QDir>
#include "CkZip.h"

#include "monitorablethread.h"
#include "zipprogress.h"

//class ZipProgress;


class ZipThread : public MonitorableThread
{
    Q_OBJECT

private:
    QString path;
    QString zipPath;

public:
    ZipThread(QString path, QString zipPath);
    ~ZipThread();

//    void ReportProgress(int);

protected:
    void run();

signals:
//    void Progress(int);


};

#endif // ZIPTHREAD_H
