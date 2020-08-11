#ifndef GUIDFILEPROPERTIES_H
#define GUIDFILEPROPERTIES_H

#include <QString>

class GuidFileProperties
{
public:
    GuidFileProperties();
    ~GuidFileProperties();

    bool mustBeAccountMember;
    bool mustBeAuthenticated;
    QString filename;
    qint64 fileSize;
    bool isReady;
    bool isDeleted;

};

#endif // GUIDFILEPROPERTIES_H
