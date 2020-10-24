#include "view.h"

View::View(QObject *parent) : QObject(parent)
{
}

void View::viewCesarBrute(const QStringList &brute)
{
    QString text;
    for (auto item : brute)
        text += QString::number(brute.indexOf(item) + 1) + " " + item + "\n";
    showCesarBrute(text);
}
