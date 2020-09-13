#ifndef GIBBERISH_H
#define GIBBERISH_H

#include "icipher.h"

#include <QHash>
#include <QString>

class Gibberish : public ICipher
{
public:
    Gibberish();

    QString encrypt(const QString &openText) override;

private:
    QHash<QString, QString> alphabet;
};

#endif // GIBBERISH_H
