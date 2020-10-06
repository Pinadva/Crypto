#include "cesar.h"

Cesar::Cesar(int shift, bool hasYo) : ICipher()
{
    _shift = shift;
    _hasYo = hasYo;
}

void Cesar::encodingShift(const int &min, const int &max, int &code)
{
    code += _shift;
    if (code > max)
        code = min + code - max - 1;
}

bool Cesar::isRuUpper(const QChar &symbol)
{
    const ushort &code = symbol.unicode();
    return (1040 <= code and code <= 1071) or code == 1025;
}

bool Cesar::isRuLower(const QChar &symbol)
{
    const ushort &code = symbol.unicode();
    return (1040 <= code and code <= 1103) or code == 1105;
}

QStringList Cesar::brute(const QString &openText)
{
    QStringList list;
    for (int i = 1; i < 33; ++i)
    {
        _shift = i;
        list << encrypt(openText);
    }
    return list;
}

QString Cesar::encrypt(const QString &openText)
{
    QString result;
    for (QChar symbol : openText)
    {
        int code = symbol.unicode();

        // Russian alphabet
        if (isRuUpper(symbol) and !_hasYo and symbol != "Ё")
            encodingShift(1040, 1071, code);
        else if (isRuLower(symbol) and !_hasYo and symbol != "ё")
            encodingShift(1072, 1103, code);
        // English alphabet
        else if (65 <= code and code <= 90)
            encodingShift(65, 90, code);
        else if (97 <= code and code <= 122)
            encodingShift(97, 122, code);
        else if ((isRuUpper(symbol) or isRuLower(symbol)) and _hasYo)
        {
            int position;
            position = isRuUpper(symbol) ? alphabet.ruUpper[symbol] : alphabet.ruLower[symbol];

            encodingShift(1, 33, position);
            if (isRuUpper(symbol))
                result += alphabet.ruUpper.key(position);
            else
                result += alphabet.ruLower.key(position);
            continue;
        }

        result += QChar(code);
    }
    return result;
}
