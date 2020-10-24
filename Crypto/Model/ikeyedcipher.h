#ifndef IKEYEDCIPHER_H
#define IKEYEDCIPHER_H

#include "icipher.h"

class IKeyedCipher : public ICipher
{
public:
    IKeyedCipher(bool hasYo = false);

    void setKey(const QString &key);

protected:
    QString _key;
};

#endif // IKEYEDCIPHER_H
