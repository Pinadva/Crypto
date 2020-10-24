#ifndef PRESENTER_H
#define PRESENTER_H

#include "cesar.h"
#include "gibberish.h"
#include "polybius_square.h"
#include "settings.h"
#include "status.h"
#include "view.h"
#include "vigener.h"

#include <QObject>
#include <QRegularExpressionMatch>
#include <QString>

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(View *view, QObject *parent = nullptr);

    void runGibberish(const QString &text);
    void runCesar(bool hasYo, const int &shift, const QString &openText);
    void runCesarBrute(bool hasYo, const QString &openText);
    void runVigener(bool hasYo, const QString &openText, const QString &key);
    void runVigenerDecrypt(bool hasYo, const QString &openText, const QString &key);
    void runPolybiusSquare(const QString &text);
    void runPolybiusSquareDecrypt(const QString &text);

private:
    bool isVigenerKeyValid(const QString &key);

signals:
    void statusChanged(const QString &msg, Status status);
    void readyViewGibbersin(const QString &crypto);
    void readyViewCesar(const QString &crypto);
    void readyViewVigener(const QString &crypto);
    void readyViewBruteCesar(const QStringList &brute);
    void readyViewPolybiusSquare(const QString &crypto);

private:
    View *_view = nullptr;
};

#endif // PRESENTER_H
