#include "presenter.h"

Presenter::Presenter(View *view, QObject *parent) : QObject(parent)
{
    _view = view;
}

void Presenter::runGibberish(const QString &text)
{
    Gibberish gibberish;
    QString crypto = gibberish.encrypt(text);
    emit readyViewGibbersin(crypto);
}

void Presenter::runCesar(bool hasYo, const int &shift, const QString &openText)
{
    Cesar cesar(hasYo, shift);
    QString crypto = cesar.encrypt(openText);
    Settings::instance().save();
    emit readyViewCesar(crypto);
}

void Presenter::runCesarBrute(bool hasYo, const QString &openText)
{
    Cesar cesar(hasYo);
    QStringList brute = cesar.brute(openText);
    Settings::instance().save();
    emit readyViewBruteCesar(brute);
}

void Presenter::runVigener(bool hasYo, const QString &openText, const QString &key)
{
    if (key.isEmpty() or openText.isEmpty())
        return;
    if (!isVigenerKeyValid(key))
        return;

    Vigener vigener(key, hasYo);
    QString crypto = vigener.encrypt(openText);
    Settings::instance().save();
    emit readyViewVigener(crypto);
}

void Presenter::runVigenerDecrypt(bool hasYo, const QString &openText, const QString &key)
{
    if (key.isEmpty() or openText.isEmpty())
        return;
    if (!isVigenerKeyValid(key))
        return;

    Vigener vigener(key, hasYo);
    QString crypto = vigener.decrypt(openText);
    Settings::instance().save();
    emit readyViewVigener(crypto);
}

bool Presenter::isVigenerKeyValid(const QString &key)
{
    QRegularExpression regexp(R"(^([A-Za-zА-Яа-яёЁ])+$)");
    if (!regexp.match(key).hasMatch())
    {
        emit statusChanged("Ключ содержит неверные символы", ERROR);
        return false;
    }
    else
        emit statusChanged("", INFO);
    return true;
}
