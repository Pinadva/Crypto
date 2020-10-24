#ifndef ALPHABETS_H
#define ALPHABETS_H

#include <QChar>
#include <QHash>
#include <QString>

typedef QHash<QString, int> HashStrInt;
typedef QHash<QString, QString> HashStrStr;

struct GibberishAlphabet
{
    HashStrStr alphabet;

    GibberishAlphabet();
};

struct PolibiusSquareAlphabet
{
    HashStrStr abc;

    PolibiusSquareAlphabet();
};

struct Abc
{
    HashStrInt ruUpper;
    HashStrInt ruLower;
    HashStrInt enUpper;
    HashStrInt enLower;
    const QString ruUpperLine = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    const QString ruLowerLine = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    const QString enUpperLine = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const QString enLowerLine = "abcdefghijklmnopqrstuvwxyz";

    Abc();
    static bool isRuLower(const QChar &symbol);
    static bool isRuUpper(const QChar &symbol);
    bool isWordSymbol(const QChar &symbol);
    int getPosition(const QChar &symbol, bool hasYo = true);
};

#endif // ALPHABETS_H
