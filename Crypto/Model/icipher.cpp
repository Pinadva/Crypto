#include "icipher.h"

ICipher::ICipher(bool hasYo)
{
    _hasYo = hasYo;
}

ICipher::~ICipher()
{
}

QString ICipher::decrypt(const QString &)
{
    return "";
}
