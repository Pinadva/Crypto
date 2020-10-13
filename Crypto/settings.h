#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings &instance();
    void save();
    void load();

public slots:
    int getTab() const;
    void setTab(const int &value);

private:
    Settings();
    ~Settings()                = default;
    Settings(const Settings &) = delete;
    Settings(Settings &&)      = delete;
    Settings &operator=(const Settings &) = delete;
    Settings &operator=(Settings &&) = delete;

    QSettings *_settings;
    int _tab = 0;
};

#endif // SETTINGS_H
