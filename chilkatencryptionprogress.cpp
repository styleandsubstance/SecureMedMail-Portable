#include "chilkatencryptionprogress.h"

ChilkatEncryptionProgress::ChilkatEncryptionProgress()
{

}

ChilkatEncryptionProgress::~ChilkatEncryptionProgress()
{

}

void ChilkatEncryptionProgress::setThread(MonitorableThread *val)
{
    this->monitorableThread = val;
}

void ChilkatEncryptionProgress::PercentDone(int pctDone, bool *abort)
{
    this->monitorableThread->ReportProgress(pctDone);
}
