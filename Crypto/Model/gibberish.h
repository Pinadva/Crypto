#ifndef GIBBERISH_H
#define GIBBERISH_H

#include "alphabets.h"
#include "icipher.h"

class Gibberish : public ICipher
{
public:
    Gibberish();

    QString encrypt(const QString &openText) override;

private:
    GibberishAlphabet alphabet;
};

#endif // GIBBERISH_H
