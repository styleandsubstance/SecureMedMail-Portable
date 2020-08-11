#ifndef DOWNLOADPROGRESS_H
#define DOWNLOADPROGRESS_H

#include <QWidget>

#include "downloadfileform.h"
#include "downloadthread.h"
#include "decryptionthread.h"
#include "extractionthread.h"
#include "tempfile.h"


namespace Ui {
class DownloadProgress;
}

class DownloadProgress : public QWidget
{
    Q_OBJECT

private:
    DownloadFileForm *downloadFileForm;
    QString downloadedFile;
    QString decryptedFile;
    QString guid;
    QString extractionPath;

    DownloadThread *downloadThread;
    DecryptionThread *decryptionThread;
    ExtractionThread *extractionThread;


public:
    explicit DownloadProgress(QWidget *parent = 0);
    ~DownloadProgress();

    void Start(DownloadFileForm *downloadFileForm);

private:
    Ui::DownloadProgress *ui;

public slots:
    void setDownloadProgressBar(int val);
    void setDecryptionProgressBar(int val);
    void setExtractionProgressBar(int val);
    void DecryptionFinished(void);
    void ExtractionFinished();
    void DownloadFinished();
    void DownloadSuccess(QString guid, QString filename);

};

#endif // DOWNLOADPROGRESS_H
