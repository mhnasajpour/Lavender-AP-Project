#include "sheepfoldbuilding.h"

SheepFoldBuilding::SheepFoldBuilding(QJsonObject _qjo) : BaseAnimalFarm(_qjo)
{
    qjoAnimalFarm = _qjo["sheepfold"].toObject();
    maxCapacityAnimalFarm = pow(2, getLevelAnimalFarm());

    nailU = 3;
    shovelU = 1;
    coinU = 50;
    timeU = 9;
    minLevelRequiredU = 7;
    maxLevelRequiredU = 10000;
    addToExpU = 15;

    nailE = 4;
    shovelE = 2;
    coinE = 50;
    timeE = 10;
    minLevelRequiredE = 6;
    addToExpE = 20;
}

QJsonObject SheepFoldBuilding::getQjo()
{
    qjo["sheepfold"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject SheepFoldBuilding::getQjoStorage()
{
    qjo["sheepfold"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject SheepFoldBuilding::getQjoSilo()
{
    qjo["sheepfold"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject SheepFoldBuilding::getQjoAnimalFarm()
{
    qjo["sheepfold"] = qjoAnimalFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoAnimalFarm;
}

bool SheepFoldBuilding::canFeed()
{
    if (getHay() < getAnimals())
        return false;
    return true;
}

void SheepFoldBuilding::feed()
{
    if (!canFeed())
        return;
    addHay(-1 * getAnimals());
    setExp(7 * getAnimals());
    setFlag(2);
    qjoAnimalFarm["daysToFinishFeeding"] = 10;
}

bool SheepFoldBuilding::canCollectProduct()
{
    if (getAnimals() + getUsedCapacity() > maxCapacityStorage)
        return false;
    if (getCoin() < getAnimals())
        return false;
    if (getFlag() != 3)
        return false;
    return true;
}

void SheepFoldBuilding::collectProduct()
{
    addWool(getAnimals());
    changeCoin(-1 * getAnimals());
    setExp(getAnimals() * 9);
    setFlag(1);
}