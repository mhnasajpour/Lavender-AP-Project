#ifndef HAYFARMBUILDING_H
#define HAYFARMBUILDING_H

#include "basefarm.h"
#include "baseestablish.h"

class HayFarmBuilding : public BaseFarm, public BaseEstablish
{
public:
    HayFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoFarm();
    void passDayToFinishEstablishing();
    int getDaysToFinishEstablishing();
    bool isLevelEnough();
    bool canEstablish();
    void startEstablishing();
    void finishEstablishing();
    void finishUpgrading();
    void startPlanting(int);
    bool canHarvest();
    void harvest();
    void passDayToFinishPlowing();
    int getDaysToFinishPlowing();
    bool canPlow();
    void startPlowing();
    void finishPlowing();
};

#endif // HAYFARMBUILDING_H