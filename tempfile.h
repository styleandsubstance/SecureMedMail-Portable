#ifndef TEMPFILE_H
#define TEMPFILE_H

#include <QUuid>
#include <QDir>

class TempFile {

public:
    static QString GetTempFilePathWithExtension(QString extension) {
        QString uid = QUuid::createUuid().toString().remove(0, 1);
        uid.chop(1);
        return QDir::tempPath() + "/" + uid + ".tmp";
    }

};


#endif // TEMPFILE_H

