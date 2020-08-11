#ifndef ZIPPROGRESS_H
#define ZIPPROGRESS_H


#include "CkZipProgressW.h"
#include "monitorablethread.h"



class ZipProgress : public CkZipProgressW
{
private:
    MonitorableThread *thread;

public:
    ZipProgress();
    virtual ~ZipProgress();

    void setThread(MonitorableThread *val);

    void PercentDone(int pctDone, bool *abort);
};


#endif // ZIPPROGRESS_H
