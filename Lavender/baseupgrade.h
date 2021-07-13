#ifndef BASEUPGRADE_H
#define BASEUPGRADE_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class BaseUpgrade
{
protected:
    int nailU;
    int shovelU;
    int coinU;
    int timeU;
    int minLevelRequiredU;
    int maxLevelRequiredU;
    int addToExpU;
public:
    virtual void passDayToFinishUpgrading() = 0;
    virtual int getDaysToFinishUpgrading() = 0;
    virtual bool canUpgrade() = 0;
    virtual void startUpgrading() = 0;
    virtual void finishUpgrading() = 0;
};

#endif // BASEUPGRADE_H
