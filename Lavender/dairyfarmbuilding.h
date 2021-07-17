#ifndef DAIRYFARMBUILDING_H
#define DAIRYFARMBUILDING_H

#include "baseanimalfarm.h"

class DairyFarmBuilding : public BaseAnimalFarm
{
public:
    DairyFarmBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoAnimalFarm();
    bool canFeed();
    void feed();
    bool canCollectProduct();
    void collectProduct();
};

#endif // DAIRYFARMBUILDING_H