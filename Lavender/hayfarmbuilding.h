#ifndef HAYFARMBUILDING_H
#define HAYFARMBUILDING_H

#include "basefarm.h"
#include "baseupgrade.h"
#include "baseestablish.h"

class HayFarmBuilding: public BaseFarm, public BaseEstablish
{
public:
    HayFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoFarm();
    void passDayToFinishEstablishing();
    int getDaysToFinishEstablishing();
    bool canEstablish();
    void startEstablishing();
    void finishEstablishing();
    void startPlanting(int);
    bool canHarvest();
    void harvest();
    void setPlowingArea(int);
    int getPlowingArea();
    void passDayToFinishPlowing();
    int getDaysToFinishPlowing();
    bool canPlow();
    void startPlowing(int);
    void finishPlowing();
};

#endif // HAYFARMBUILDING_H
