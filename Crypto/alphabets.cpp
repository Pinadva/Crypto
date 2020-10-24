#include "alphabets.h"

GibberishAlphabet::GibberishAlphabet()
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

Abc::Abc()
{
    // Russian Upper
    ruUpper.insert("А", 1);
    ruUpper.insert("Б", 2);
    ruUpper.insert("В", 3);
    ruUpper.insert("Г", 4);
    ruUpper.insert("Д", 5);
    ruUpper.insert("Е", 6);
    ruUpper.insert("Ё", 7);
    ruUpper.insert("Ж", 8);
    ruUpper.insert("З", 9);
    ruUpper.insert("И", 10);
    ruUpper.insert("Й", 11);
    ruUpper.insert("К", 12);
    ruUpper.insert("Л", 13);
    ruUpper.insert("М", 14);
    ruUpper.insert("Н", 15);
    ruUpper.insert("О", 16);
    ruUpper.insert("П", 17);
    ruUpper.insert("Р", 18);
    ruUpper.insert("С", 19);
    ruUpper.insert("Т", 20);
    ruUpper.insert("У", 21);
    ruUpper.insert("Ф", 22);
    ruUpper.insert("Х", 23);
    ruUpper.insert("Ц", 24);
    ruUpper.insert("Ч", 25);
    ruUpper.insert("Ш", 26);
    ruUpper.insert("Щ", 27);
    ruUpper.insert("Ъ", 28);
    ruUpper.insert("Ы", 29);
    ruUpper.insert("Ь", 30);
    ruUpper.insert("Э", 31);
    ruUpper.insert("Ю", 32);
    ruUpper.insert("Я", 33);
    // Russian lower
    ruLower.insert("а", 1);
    ruLower.insert("б", 2);
    ruLower.insert("в", 3);
    ruLower.insert("г", 4);
    ruLower.insert("д", 5);
    ruLower.insert("е", 6);
    ruLower.insert("ё", 7);
    ruLower.insert("ж", 8);
    ruLower.insert("з", 9);
    ruLower.insert("и", 10);
    ruLower.insert("й", 11);
    ruLower.insert("к", 12);
    ruLower.insert("л", 13);
    ruLower.insert("м", 14);
    ruLower.insert("н", 15);
    ruLower.insert("о", 16);
    ruLower.insert("п", 17);
    ruLower.insert("р", 18);
    ruLower.insert("с", 19);
    ruLower.insert("т", 20);
    ruLower.insert("у", 21);
    ruLower.insert("ф", 22);
    ruLower.insert("х", 23);
    ruLower.insert("ц", 24);
    ruLower.insert("ч", 25);
    ruLower.insert("ш", 26);
    ruLower.insert("щ", 27);
    ruLower.insert("ъ", 28);
    ruLower.insert("ы", 29);
    ruLower.insert("ь", 30);
    ruLower.insert("э", 31);
    ruLower.insert("ю", 32);
    ruLower.insert("я", 33);
    // English Upper
    enUpper.insert("A", 1);
    enUpper.insert("B", 2);
    enUpper.insert("C", 3);
    enUpper.insert("D", 4);
    enUpper.insert("E", 5);
    enUpper.insert("F", 6);
    enUpper.insert("G", 7);
    enUpper.insert("H", 8);
    enUpper.insert("I", 9);
    enUpper.insert("J", 10);
    enUpper.insert("K", 11);
    enUpper.insert("L", 12);
    enUpper.insert("M", 13);
    enUpper.insert("N", 14);
    enUpper.insert("O", 15);
    enUpper.insert("P", 16);
    enUpper.insert("Q", 17);
    enUpper.insert("R", 18);
    enUpper.insert("S", 19);
    enUpper.insert("T", 20);
    enUpper.insert("U", 21);
    enUpper.insert("V", 22);
    enUpper.insert("W", 23);
    enUpper.insert("X", 24);
    enUpper.insert("Y", 25);
    enUpper.insert("Z", 26);

    // English lower
    enLower.insert("a", 1);
    enLower.insert("b", 2);
    enLower.insert("c", 3);
    enLower.insert("d", 4);
    enLower.insert("e", 5);
    enLower.insert("f", 6);
    enLower.insert("g", 7);
    enLower.insert("h", 8);
    enLower.insert("i", 9);
    enLower.insert("j", 10);
    enLower.insert("k", 11);
    enLower.insert("l", 12);
    enLower.insert("m", 13);
    enLower.insert("n", 14);
    enLower.insert("o", 15);
    enLower.insert("p", 16);
    enLower.insert("q", 17);
    enLower.insert("r", 18);
    enLower.insert("s", 19);
    enLower.insert("t", 20);
    enLower.insert("u", 21);
    enLower.insert("v", 22);
    enLower.insert("w", 23);
    enLower.insert("x", 24);
    enLower.insert("y", 25);
    enLower.insert("z", 26);
}

bool Abc::isRuLower(const QChar &symbol)
{
    const ushort &code = symbol.unicode();
    return (1072 <= code and code <= 1103) or code == 1105;
}

bool Abc::isRuUpper(const QChar &symbol)
{
    const ushort &code = symbol.unicode();
    return (1040 <= code and code <= 1071) or code == 1025;
}

bool Abc::isWordSymbol(const QChar &symbol)
{
    if (isRuUpper(symbol))
        return true;
    else if (isRuLower(symbol))
        return true;
    else if (symbol.isUpper())
        return true;
    else if (symbol.isLower())
        return true;

    return false;
}

int Abc::getPosition(const QChar &symbol, bool hasYo)
{
    int position = 1;
    if (isRuUpper(symbol) and !hasYo)
        position = symbol.unicode() - 1039;
    else if (isRuLower(symbol) and !hasYo)
        position = symbol.unicode() - 1071;
    else if (isRuUpper(symbol))
        position = ruUpper[symbol];
    else if (isRuLower(symbol))
        position = ruLower[symbol];
    else if (symbol.isUpper())
        position = symbol.unicode() - 64;
    else if (symbol.isLower())
        position = symbol.unicode() - 96;

    if (position <= 0)
        position = 1;

    return position;
}
