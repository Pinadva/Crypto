#ifndef ICIPHER_H
#define ICIPHER_H

#include <QString>

class ICipher
{
public:
    ICipher();
    virtual ~ICipher();

    virtual QString encrypt(const QString &openText) = 0;
};

#endif // ICIPHER_H
