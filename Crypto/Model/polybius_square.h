#ifndef POLYBIUSSQUARE_H
#define POLYBIUSSQUARE_H

#include "alphabets.h"
#include "icipher.h"

class PolybiusSquare : public ICipher
{
public:
    PolybiusSquare();

    QString encrypt(const QString &openText) override;

private:
    PolibiusSquareAlphabet alphabet;

    // ICipher interface
public:
    QString decrypt(const QString &crypto) override;
};

#endif // POLYBIUSSQUARE_H
