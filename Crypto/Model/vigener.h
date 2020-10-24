#ifndef VIGENER_H
#define VIGENER_H

#include "alphabets.h"
#include "cesar.h"
#include "ikeyedcipher.h"

#include <algorithm>

class Vigener : public IKeyedCipher
{
public:
    explicit Vigener(QString key, bool hasYo = false);
    QString getVigenerRow(const QChar &symbol);
    // ICipher interface
public:
    QString encrypt(const QString &openText) override;
    QString decrypt(const QString &crypto) override;

private:
    Abc _abc;
};

#endif // VIGENER_H
