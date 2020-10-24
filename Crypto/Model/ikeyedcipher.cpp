#include "ikeyedcipher.h"

IKeyedCipher::IKeyedCipher(bool hasYo) : ICipher(hasYo)
{
}

void IKeyedCipher::setKey(const QString &key)
{
    _key = key;
}
