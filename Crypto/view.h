#ifndef VIEW_H
#define VIEW_H

#include <QObject>

class View : public QObject
{
    Q_OBJECT
public:
    explicit View(QObject *parent = nullptr);

public slots:
    void viewCesarBrute(const QStringList &brute);

signals:
    void showCesarBrute(const QString &text);
};

#endif // VIEW_H
