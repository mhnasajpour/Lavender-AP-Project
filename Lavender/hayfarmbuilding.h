#ifndef HAYFARMBUILDING_H
#define HAYFARMBUILDING_H

#include "basefarm.h"

class HayFarmBuilding: public BaseFarm
{
public:
    HayFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoFarm();
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
