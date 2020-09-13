#include "gibberish.h"

Gibberish::Gibberish() : ICipher()
{
    // english
    // BCDFGHJKLM
    // ZXWVTSRQPN
    // upper case
    alphabet.insert("B", "Z");
    alphabet.insert("C", "X");
    alphabet.insert("D", "W");
    alphabet.insert("F", "V");
    alphabet.insert("G", "T");
    alphabet.insert("H", "S");
    alphabet.insert("J", "R");
    alphabet.insert("K", "Q");
    alphabet.insert("L", "P");
    alphabet.insert("M", "N");
    // lower case
    alphabet.insert("b", "z");
    alphabet.insert("c", "x");
    alphabet.insert("d", "w");
    alphabet.insert("f", "v");
    alphabet.insert("g", "t");
    alphabet.insert("h", "s");
    alphabet.insert("f", "r");
    alphabet.insert("k", "q");
    alphabet.insert("l", "p");
    alphabet.insert("m", "n");

    // russian
    // БВГДЖЗКЛМН
    // ЩШЧЦХФТСРП
    // upper case
    alphabet.insert("Б", "Щ");
    alphabet.insert("В", "Ш");
    alphabet.insert("Г", "Ч");
    alphabet.insert("Д", "Ц");
    alphabet.insert("Ж", "Х");
    alphabet.insert("З", "Ф");
    alphabet.insert("К", "Т");
    alphabet.insert("Л", "С");
    alphabet.insert("М", "Р");
    alphabet.insert("Н", "П");
    // lower case
    alphabet.insert("б", "щ");
    alphabet.insert("в", "ш");
    alphabet.insert("г", "ч");
    alphabet.insert("д", "ц");
    alphabet.insert("ж", "х");
    alphabet.insert("з", "ф");
    alphabet.insert("к", "т");
    alphabet.insert("л", "с");
    alphabet.insert("м", "р");
    alphabet.insert("н", "п");
}

QString Gibberish::encrypt(const QString &openText) // бббщщщ
{
    QString result;
    for (QString item : openText){
        QString letter = alphabet.value(item, alphabet.key(item));
        if (letter.isEmpty())
            letter = item;
        result.append(letter);
    }

    return result;
}
