#ifndef CESAR_H
#define CESAR_H

#include "QChar"
#include "QString"
#include "alphabets.h"
#include "icipher.h"

class Cesar : public ICipher
{
public:
    Cesar(int shift, bool hasYo);

    void encodingShift(const int &min, const int &max, int &code);
    bool isRuUpper(const QChar &symbol);
    bool isRuLower(const QChar &symbol);
    QStringList brute(const QString &openText);

    // ICipher interface
public:
    QString encrypt(const QString &openText) override;

private:
    CesarAlphabet alphabet;
    int _shift;
    bool _hasYo;
};

#endif // CESAR_H
