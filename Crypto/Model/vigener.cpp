#include "vigener.h"

Vigener::Vigener(QString key, bool hasYo) : IKeyedCipher(hasYo)
{
    _key = key;
}

QString Vigener::getVigenerRow(const QChar &symbol)
{
    QString row;
    if (Abc::isRuUpper(symbol))
        row = _abc.ruUpperLine;
    else if (Abc::isRuLower(symbol))
        row = _abc.ruLowerLine;
    else if (symbol.isUpper())
        row = _abc.enUpperLine;
    else if (symbol.isLower())
        row = _abc.enLowerLine;
    if (!_hasYo)
        row = row.replace("ё", "").replace("Ё", "");

    return row;
}

QString Vigener::encrypt(const QString &openText)
{
    QString crypto;

    // i is for open text index
    // j is for key index
    QChar vigenerSymbol;
    for (int i = 0, j = 0; i < openText.length(); ++i, ++j, crypto += vigenerSymbol)
    {
        auto symbol   = openText.at(i);
        vigenerSymbol = symbol;
        if (j >= _key.length())
            j = 0;
        auto keySymbol = _key.at(j);

        if (!_abc.isWordSymbol(symbol))
        {
            --j;
            continue;
        }

        QString vigenerRow = getVigenerRow(symbol);

        int shift = _abc.getPosition(keySymbol, _hasYo) - 1;
        shift     = shift >= vigenerRow.count() ? vigenerRow.count() - 1 : shift;
        std::rotate(vigenerRow.begin(), vigenerRow.begin() + shift, vigenerRow.end());

        int position = _abc.getPosition(symbol, _hasYo) - 1;
        position     = position >= vigenerRow.count() ? vigenerRow.count() - 1 : position;

        vigenerSymbol = vigenerRow[position];
    }

    return crypto;
}

QString Vigener::decrypt(const QString &crypto)
{
    QString openText;

    QChar vigenerSymbol;
    for (int i = 0, j = 0; i < crypto.length(); ++i, ++j, openText += vigenerSymbol)
    {
        auto symbol   = crypto.at(i);
        vigenerSymbol = symbol;

        if (j >= _key.length())
            j = 0;
        auto keySymbol = _key.at(j);

        if (!_abc.isWordSymbol(symbol))
        {
            --j;
            continue;
        }

        QString vigenerRow = getVigenerRow(symbol);

        int shift = _abc.getPosition(keySymbol, _hasYo) - 1;
        shift     = shift >= vigenerRow.count() ? vigenerRow.count() - 1 : shift;
        std::rotate(vigenerRow.begin(), vigenerRow.begin() + shift, vigenerRow.end());

        int position = vigenerRow.indexOf(symbol);
        position     = position >= vigenerRow.count() ? vigenerRow.count() - 1 : position;
        position     = position < 0 ? 0 : position;

        vigenerRow    = getVigenerRow(symbol);
        vigenerSymbol = vigenerRow[position];
    }
    return openText;
}
