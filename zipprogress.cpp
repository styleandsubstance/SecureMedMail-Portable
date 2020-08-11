#include "zipprogress.h"

ZipProgress::ZipProgress()
{

}

ZipProgress::~ZipProgress()
{

}
void ZipProgress::setThread(MonitorableThread *val)
{
    this->thread = val;
}

void ZipProgress::PercentDone(int pctDone, bool *abort)
{
    this->thread->ReportProgress(pctDone);
}

