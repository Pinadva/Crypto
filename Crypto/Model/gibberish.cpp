#include "gibberish.h"

Gibberish::Gibberish() : ICipher()
{
}

QString Gibberish::encrypt(const QString &openText) // бббщщщ
{
    QString result;
    for (QString item : openText)
    {
        QString letter = alphabet.alphabet.value(item, alphabet.alphabet.key(item));
        if (letter.isEmpty())
            letter = item;
        result.append(letter);
    }

    return result;
}
