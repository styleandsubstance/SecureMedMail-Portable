#include "monitorablethread.h"

MonitorableThread::MonitorableThread()
{

}

MonitorableThread::~MonitorableThread()
{

}

void MonitorableThread::ReportProgress(int pctDone)
{
    emit Progress(pctDone);
}
