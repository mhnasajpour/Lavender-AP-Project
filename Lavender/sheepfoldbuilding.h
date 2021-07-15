#ifndef SHEEPFOLDBUILDING_H
#define SHEEPFOLDBUILDING_H

#include "baseanimalfarm.h"

class SheepFoldBuilding: public BaseAnimalFarm
{
public:
    SheepFoldBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoAnimalFarm();
    bool canFeed();
    void feed();
    bool canCollectProduct();
    void collectProduct();
};

#endif // SHEEPFOLDBUILDING_H
