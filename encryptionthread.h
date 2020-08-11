#ifndef ENCRYPTIONTHREAD_H
#define ENCRYPTIONTHREAD_H


#include <QTCore>
#include "CkByteData.h"
#include "CkCrypt2.h"
#include "monitorablethread.h"
#include "chilkatencryptionprogress.h"

//class EncryptionProgress;

class EncryptionThread : public MonitorableThread
{
    Q_OBJECT
public:

private:
    QString password;
    QString inputPath;
    QString encryptedPath;

public:
    EncryptionThread(QString password, QString inputPath, QString encryptedPath);
    ~EncryptionThread();

//    void ReportProgress(int);

protected:
    void run();

//signals:
//    void Progress(int);

};

#endif // ENCRYPTIONTHREAD_H
