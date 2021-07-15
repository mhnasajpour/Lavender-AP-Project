#include "wheatfarmbuilding.h"

WheatFarmBuilding::WheatFarmBuilding(QJsonObject _qjo):
    BaseFarm(_qjo)
{
    qjoFarm = _qjo["wheatFarm"].toObject();
    maxArea = pow(2, getLevelFarm() - 1) * 5;

    nailU = 0;
    shovelU = maxArea;
    coinU = maxArea * 5;
    timeU = 2;
    minLevelRequiredU = 2;
    maxLevelRequiredU = 10000;
    addToExpU = maxArea * 3;
}

QJsonObject WheatFarmBuilding::getQjo()
{
    qjo["wheatFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject WheatFarmBuilding::getQjoStorage()
{
    qjo["wheatFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject WheatFarmBuilding::getQjoSilo()
{
    qjo["wheatFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject WheatFarmBuilding::getQjoFarm()
{
    qjo["wheatFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoFarm;
}

void WheatFarmBuilding::finishUpgrading()
{
    qjoFarm["level"] = getLevelFarm() + 1;
    maxArea *= 2;
    setExp(addToExpU);

    shovelU = maxArea;
    coinU = maxArea * 5;
    addToExpU = maxArea * 3;
}

void WheatFarmBuilding::startPlanting(int plantingArea)
{
    setPlantingArea(plantingArea);
    setFlag(2);
    qjoFarm["daysToFinishPlanting"] = 2;
    addWheat(-1 * plantingArea);
    setExp(plantingArea);
}

bool WheatFarmBuilding::canHarvest()
{
    if(getWheat() + (getPlantingArea() * 2) > maxCapacitySilo)
        return false;
    return true;
}

void WheatFarmBuilding::harvest()
{
    setFlag(1);
    addWheat(2 * getPlantingArea());
    setExp(getPlantingArea());
    setPlantingArea(0);
}
