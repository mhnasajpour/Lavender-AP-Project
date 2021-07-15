#ifndef POULTRYFARMBUILDING_H
#define POULTRYFARMBUILDING_H

#include "baseanimalfarm.h"

class PoultryFarmBuilding: public BaseAnimalFarm
{
public:
    PoultryFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoAnimalFarm();
    void finishUpgrading();
    bool canFeed();
    void Feed();
    bool canCollectProduct();
    void collectProduct();
};

#endif // POULTRYFARMBUILDING_H
