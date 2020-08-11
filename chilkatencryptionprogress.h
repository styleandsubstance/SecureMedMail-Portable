#ifndef CHILKATENCRYPTIONPROGRESS_H
#define CHILKATENCRYPTIONPROGRESS_H

#include "CkBaseProgress.h"

#include "monitorablethread.h"


class ChilkatEncryptionProgress : public CkBaseProgress
{
private:
    MonitorableThread *monitorableThread;


public:
    ChilkatEncryptionProgress();
    virtual ~ChilkatEncryptionProgress();

    void setThread(MonitorableThread *val);

    void PercentDone(int pctDone, bool *abort);

};

#endif // CHILKATENCRYPTIONPROGRESS_H
