#ifndef EXTRACTIONTHREAD_H
#define EXTRACTIONTHREAD_H

#include <QtCore>
#include <QDebug>
#include <QDir>

#include "CkZip.h"
#include "monitorablethread.h"
#include "zipprogress.h"


class ExtractionThread : public MonitorableThread
{
    Q_OBJECT
private:
    QString zipFilePath;
    QString extractionPath;

public:
    ExtractionThread(QString zipFilePath, QString extractionPath);
    ~ExtractionThread();

protected:
    void run();

};

#endif // EXTRACTIONTHREAD_H
