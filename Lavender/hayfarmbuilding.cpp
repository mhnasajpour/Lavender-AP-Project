#include "hayfarmbuilding.h"

HayFarmBuilding::HayFarmBuilding(QJsonObject _qjo) : BaseFarm(_qjo)
{
    qjoFarm = _qjo["hayFarm"].toObject();
    maxArea = pow(2, getLevelFarm() + 1);

    nailU = 0;
    shovelU = maxArea * 2;
    coinU = maxArea * 5;
    timeU = 3;
    minLevelRequiredU = 4;
    maxLevelRequiredU = 10000;
    addToExpU = maxArea * 3;

    nailE = 1;
    shovelE = 1;
    coinE = 15;
    timeE = 3;
    minLevelRequiredE = 3;
    addToExpE = 6;
}

QJsonObject HayFarmBuilding::getQjo()
{
    qjo["hayFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject HayFarmBuilding::getQjoStorage()
{
    qjo["hayFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject HayFarmBuilding::getQjoSilo()
{
    qjo["hayFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject HayFarmBuilding::getQjoFarm()
{
    qjo["hayFarm"] = qjoFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoFarm;
}

void HayFarmBuilding::passDayToFinishEstablishing()
{
    qjoFarm["daysToFinishEstablishing"] = getDaysToFinishEstablishing() - 1;
}

int HayFarmBuilding::getDaysToFinishEstablishing()
{
    return qjoFarm["daysToFinishEstablishing"].toInt();
}

bool HayFarmBuilding::isLevelEnough()
{
    if (getLevelPlayer() < minLevelRequiredE)
        return false;
    return true;
}

bool HayFarmBuilding::canEstablish()
{
    if (getNail() < nailE)
        return false;
    if (getShovel() < shovelE)
        return false;
    if (getCoin() < coinE)
        return false;
    if (getLevelPlayer() < minLevelRequiredE)
        return false;
    return true;
}

void HayFarmBuilding::startEstablishing()
{
    if (!canEstablish())
        return;
    addNail(-1 * nailE);
    addShovel(-1 * shovelE);
    changeCoin(-1 * coinE);
    qjoFarm["daysToFinishEstablishing"] = timeE;
}

void HayFarmBuilding::finishEstablishing()
{
    qjoFarm["level"] = 1;
    setExp(addToExpE);
}

void HayFarmBuilding::finishUpgrading()
{
    qjoFarm["level"] = getLevelFarm() + 1;
    maxArea *= 2;
    setExp(addToExpU);

    shovelU = maxArea * 2;
    coinU = maxArea * 5;
    addToExpU = maxArea * 3;
}

void HayFarmBuilding::startPlanting(int plantingArea)
{
    setPlantingArea(plantingArea);
    setFlag(2);
    qjoFarm["daysToFinishPlanting"] = 4;
    addHay(-1 * plantingArea);
    setExp(plantingArea * 2);
}

bool HayFarmBuilding::canHarvest()
{
    if (getUsedCapacity() + (getPlantingArea() * 2) > maxCapacityStorage)
        return false;
    return true;
}

void HayFarmBuilding::harvest()
{
    setFlag(4);
    addHay(2 * getPlantingArea());
    setExp(getPlantingArea() * 2);
    setPlantingArea(0);
}

void HayFarmBuilding::passDayToFinishPlowing()
{
    qjoFarm["daysToFinishPlowing"] = getDaysToFinishPlowing() - 1;
}

int HayFarmBuilding::getDaysToFinishPlowing()
{
    return qjoFarm["daysToFinishPlowing"].toInt();
}

bool HayFarmBuilding::canPlow()
{
    if (getCoin() < maxArea * 5)
        return false;
    return true;
}

void HayFarmBuilding::startPlowing()
{
    setFlag(5);
    qjoFarm["daysToFinishPlowing"] = 1;
    changeCoin(-5 * maxArea);
    setExp(maxArea);
}

void HayFarmBuilding::finishPlowing()
{
    setFlag(1);
}