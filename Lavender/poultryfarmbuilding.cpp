#include "poultryfarmbuilding.h"

PoultryFarmBuilding::PoultryFarmBuilding(QJsonObject _qjo):
    BaseAnimalFarm(_qjo)
{
    qjoAnimalFarm = _qjo["poultryFarm"].toObject();
    maxCapacityAnimalFarm = pow(2, getLevelAnimalFarm());

    nailU = 1;
    shovelU = 0;
    coinU = 10;
    timeU = 3;
    minLevelRequiredU = 3;
    maxLevelRequiredU = 10000;
    addToExpU = 5;

    nailE = 2;
    shovelE = 0;
    coinE = 10;
    timeE = 3;
    minLevelRequiredE = 2;
    addToExpE = 5;
}

QJsonObject PoultryFarmBuilding::getQjo()
{
    qjo["poultryFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject PoultryFarmBuilding::getQjoStorage()
{
    qjo["poultryFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject PoultryFarmBuilding::getQjoSilo()
{
    qjo["poultryFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject PoultryFarmBuilding::getQjoAnimalFarm()
{
    qjo["poultryFarm"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoAnimalFarm;
}

bool PoultryFarmBuilding::canFeed()
{
    if(getWheat() < getAnimals())
        return false;
    return true;
}

void PoultryFarmBuilding::Feed()
{
    if(!canFeed())
        return;
    addWheat(-1 * getAnimals());
    setExp(getAnimals());
    setFlag(2);
    qjoAnimalFarm["daysToFinishFeeding"] = 2;
}

bool PoultryFarmBuilding::canCollectProduct()
{
    if(getAnimals() + getUsedCapacity() > maxCapacityStorage)
        return false;
    if(getFlag() != 3)
        return false;
    return true;
}

void PoultryFarmBuilding::collectProduct()
{
    addEgg(getAnimals());
    setExp(getAnimals() * 2);
    setFlag(1);
}
