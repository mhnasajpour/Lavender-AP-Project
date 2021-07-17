#ifndef POULTRYFARMBUILDING_H
#define POULTRYFARMBUILDING_H

#include "baseanimalfarm.h"

class PoultryFarmBuilding : public BaseAnimalFarm
{
public:
    PoultryFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoAnimalFarm();
    bool canFeed();
    void feed();
    bool canCollectProduct();
    void collectProduct();
};

#endif // POULTRYFARMBUILDING_H