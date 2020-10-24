#ifndef CESAR_H
#define CESAR_H

#include "QChar"
#include "QString"
#include "alphabets.h"
#include "icipher.h"

class Cesar : public ICipher
{
public:
    Cesar(bool hasYo, int shift = 1);

    void encodingShift(const int &min, const int &max, int &code);
    QStringList brute(const QString &openText);

    // ICipher interface
public:
    QString encrypt(const QString &openText) override;

private:
    Abc abc;
    int _shift;
    bool _hasYo;
};

#endif // CESAR_H
