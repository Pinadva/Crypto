#include "cesar.h"

Cesar::Cesar(bool hasYo, int shift) : ICipher(hasYo)
{
    _shift = shift;
}

void Cesar::encodingShift(const int &min, const int &max, int &code)
{
    code += _shift;
    if (code > max)
        code = min + code - max - 1;
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
    for (const QChar &symbol : openText)
    {
        int code = symbol.unicode();

        // Russian alphabet
        if (Abc::isRuUpper(symbol) and !_hasYo and symbol != "Ё")
            encodingShift(1040, 1071, code);
        else if (Abc::isRuLower(symbol) and !_hasYo and symbol != "ё")
            encodingShift(1072, 1103, code);
        // English alphabet
        else if (65 <= code and code <= 90)
            encodingShift(65, 90, code);
        else if (97 <= code and code <= 122)
            encodingShift(97, 122, code);
        else if ((Abc::isRuUpper(symbol) or Abc::isRuLower(symbol)) and _hasYo)
        {
            int position;
            position = Abc::isRuUpper(symbol) ? abc.ruUpper[symbol] : abc.ruLower[symbol];

            encodingShift(1, 33, position);
            if (Abc::isRuUpper(symbol))
                result += abc.ruUpper.key(position);
            else
                result += abc.ruLower.key(position);
            continue;
        }

        result += QChar(code);
    }
    return result;
}
