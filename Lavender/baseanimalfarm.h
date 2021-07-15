#ifndef BASEANIMALFARM_H
#define BASEANIMALFARM_H

#include "basesilo.h"
#include "baseupgrade.h"
#include "baseestablish.h"

class BaseAnimalFarm: public BaseSilo, public BaseUpgrade, public BaseEstablish
{
protected:
    QJsonObject qjoAnimalFarm;
    int maxCapacityAnimalFarm;
public:
    BaseAnimalFarm(QJsonObject);
    virtual QJsonObject getQjo() = 0;
    virtual QJsonObject getQjoStorage() = 0;
    virtual QJsonObject getQjoSilo() = 0;
    virtual QJsonObject getQjoAnimalFarm() = 0;
    void passDayToFinishEstablishing();
    int getDaysToFinishEstablishing();
    bool isLevelEnough();
    bool canEstablish();
    void startEstablishing();
    void finishEstablishing();
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    virtual void finishUpgrading() = 0;
    int getLevelAnimalFarm();
    bool addAnimals(int);
    int getAnimals();
    void setFlag(int);
    int getFlag();
    void passDayToFinishFeeding();
    int getDaysToFinishFeeding();
    virtual bool canFeed() = 0;
    virtual void Feed() = 0;
    void finishFeeding();
    virtual bool canCollectProduct() = 0;
    virtual void collectProduct() = 0;
    int getMaxCapacityAnimalFarm();
};

#endif // BASEANIMALFARM_H
