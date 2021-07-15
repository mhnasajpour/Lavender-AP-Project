#include "dairyfarmbuilding.h"

DairyFarmBuilding::DairyFarmBuilding(QJsonObject _qjo):
    BaseAnimalFarm(_qjo)
{
    qjoAnimalFarm = _qjo["dairyFarm"].toObject();
    maxCapacityAnimalFarm = pow(2, getLevelAnimalFarm());

    nailU = 2;
    shovelU = 0;
    coinU = 15;
    timeU = 5;
    minLevelRequiredU = 5;
    maxLevelRequiredU = 10000;
    addToExpU = 6;

    nailE = 3;
    shovelE = 1;
    coinE = 20;
    timeE = 5;
    minLevelRequiredE = 4;
    addToExpE = 10;
}

QJsonObject DairyFarmBuilding::getQjo()
{
    qjo["dairyFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject DairyFarmBuilding::getQjoStorage()
{
    qjo["dairyFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject DairyFarmBuilding::getQjoSilo()
{
    qjo["dairyFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject DairyFarmBuilding::getQjoAnimalFarm()
{
    qjo["dairyFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoAnimalFarm;
}

bool DairyFarmBuilding::canFeed()
{
    if(getHay() < getAnimals() * 2)
        return false;
    return true;
}

void DairyFarmBuilding::Feed()
{
    if(!canFeed())
        return;
    addHay(-2 * getAnimals());
    setExp(3 * getAnimals());
    setFlag(2);
    qjoAnimalFarm["daysToFinishFeeding"] = 3;
}

bool DairyFarmBuilding::canCollectProduct()
{
    if(getAnimals() + getUsedCapacity() > maxCapacityStorage)
        return false;
    if(getFlag() != 3)
        return false;
    return true;
}

void DairyFarmBuilding::collectProduct()
{
    addMilk(getAnimals());
    setExp(getAnimals() * 5);
    setFlag(1);
}
