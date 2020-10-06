#ifndef ALPHABETS_H
#define ALPHABETS_H

#include <QHash>
#include <QString>

struct GibberishAlphabet
{
    QHash<QString, QString> alphabet;

    GibberishAlphabet()
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
};

struct CesarAlphabet
{
    QHash<QString, int> ruUpper;
    QHash<QString, int> ruLower;

    CesarAlphabet()
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
    }
};

#endif // ALPHABETS_H
