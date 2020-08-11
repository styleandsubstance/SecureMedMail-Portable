#ifndef DECRYPTIONTHREAD_H
#define DECRYPTIONTHREAD_H

#include <QTCore>
#include "CkByteData.h"
#include "CkCrypt2.h"

#include "monitorablethread.h"

class ChilkatEncryptionProgress;

class DecryptionThread : public MonitorableThread
{
    Q_OBJECT

private:
    QString password;
    QString inputPath;
    QString decryptedPath;

public:
    DecryptionThread(QString password, QString inputPath, QString decryptedPath);
    ~DecryptionThread();

protected:
    void run();
};

#endif // DECRYPTIONTHREAD_H
