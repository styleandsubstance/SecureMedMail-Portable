#ifndef ENCRYPTIONPROGRESS_H
#define ENCRYPTIONPROGRESS_H

#include "CkBaseProgress.h"

#include "encryptionthread.h"

class EncryptionProgress : public CkBaseProgress
{
private:
    EncryptionThread *encryptionThread;

public:
    EncryptionProgress();
    virtual ~EncryptionProgress();

    void setEncryptionThread(EncryptionThread *val);

    void PercentDone(int pctDone, bool *abort);

};

#endif // ENCRYPTIONPROGRESS_H
