#ifndef MONITORABLETHREAD_H
#define MONITORABLETHREAD_H

#include <QTCore>

class MonitorableThread : public QThread
{
   Q_OBJECT
public:
    MonitorableThread();
    virtual ~MonitorableThread();

    void ReportProgress(int);

signals:
    void Progress(int);
};

#endif // MONITORABLETHREAD_H
