#ifndef ICIPHER_H
#define ICIPHER_H

#include <QHash>
#include <QString>

class ICipher
{
public:
    ICipher(bool hasYo = false);
    virtual ~ICipher();

    virtual QString encrypt(const QString &openText) = 0;
    virtual QString decrypt(const QString &crypto);

protected:
    bool _hasYo;
};

#endif // ICIPHER_H
