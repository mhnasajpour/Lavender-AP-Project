#ifndef BASEFARM_H
#define BASEFARM_H

#include "basesilo.h"
#include "baseupgrade.h"
#include "baseestablish.h"

class BaseFarm: public BaseSilo, public BaseUpgrade, public BaseEstablish
{
protected:
    QJsonObject qjoFarm;
    int maxArea;
public:
    BaseFarm(QJsonObject);
    virtual QJsonObject getQjo() = 0;
    virtual QJsonObject getQjoStorage() = 0;
    virtual QJsonObject getQjoSilo() = 0;
    virtual QJsonObject getQjoFarm() = 0;
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
    void passDayToFinishEstablishing();
    int getDaysToFinishEstablishing();
    bool isLevelEnough();
    bool canEstablish();
    void startEstablishing();
    void finishEstablishing();
    int getLevelFarm();
    void setPlantingArea(int);
    int getPlantingArea();
    void setFlag(int);
    int getFlag();
    void passDayToFinishPlanting();
    int getDaysToFinishPlanting();
    virtual void startPlanting(int) = 0;
    void finishPlanting();
    virtual bool canHarvest() = 0;
    virtual void harvest() = 0;
    int getMaxArea();
};

#endif // BASEFARM_H
