#ifndef BASEUSER_H
#define BASEUSER_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class BaseUser
{
protected:
    QJsonObject qjo;
    int upperBoundExp;
public:
    BaseUser(QJsonObject);
    virtual QJsonObject getQjo() = 0;
    int getLevelPlayer();
    void setExp(int);
    int getExp();
    void changeCoin(int);
    int getCoin();
    int getDay();
};

#endif // BASEUSER_H
