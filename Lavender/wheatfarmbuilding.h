#ifndef WHEATFARMBUILDING_H
#define WHEATFARMBUILDING_H

#include "basefarm.h"
#include "baseupgrade.h"

class WheatFarmBuilding: public BaseFarm
{
public:
    WheatFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoFarm();
    void startPlanting(int);
    bool canHarvest();
    void harvest();
};

#endif // WHEATFARMBUILDING_H
