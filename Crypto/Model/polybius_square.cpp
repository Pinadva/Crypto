#include "polybius_square.h"

PolybiusSquare::PolybiusSquare()
{
}

QString PolybiusSquare::encrypt(const QString &openText)
{
    QString result;
    for (QString item : openText)
    {
        QString letter = alphabet.abc.value(item, alphabet.abc.key(item));
        if (letter.isEmpty())
            letter = item;
        result.append(letter);
    }

    return result;
}

QString PolybiusSquare::decrypt(const QString &crypto)
{
    QString result;
    for (int i = 0; i < crypto.length(); i += 2)
    {
        QString item;
        item += crypto[i];
        if (i + 1 < crypto.length())
            item += crypto[i + 1];
        QString letter = alphabet.abc.value(item, alphabet.abc.key(item));
        if (letter.isEmpty())
            letter = item;
        result.append(letter);
    }

    return result;
}
