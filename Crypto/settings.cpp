#include "settings.h"

Settings::Settings() : QObject(nullptr)
{
    _settings = new QSettings("settings.ini", QSettings::IniFormat);
}

int Settings::getTab() const
{
    return _tab;
}

void Settings::setTab(const int &tab)
{
    if (_tab != tab)
        _tab = tab;
}

Settings &Settings::instance()
{
    static Settings self;
    return self;
}

void Settings::save()
{
    _settings->setValue("tab", _tab);
}

void Settings::load()
{
    _tab = _settings->value("tab", 0).toInt();
}
