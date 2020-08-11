#include "encryptionprogress.h"

EncryptionProgress::EncryptionProgress()
{

}

EncryptionProgress::~EncryptionProgress()
{

}

void EncryptionProgress::setEncryptionThread(EncryptionThread *val)
{
    this->encryptionThread = val;
}

void EncryptionProgress::PercentDone(int pctDone, bool *abort)
{
    this->encryptionThread->ReportProgress(pctDone);
}
