#include "wheatfarmbuilding.h"
#include <QDebug>

QJsonObject WheatFarmBuilding::getQjo()
{
    qjo["wheatFarm"] = qjoWheatFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject WheatFarmBuilding::getQjoStorage()
{
    qjo["wheatFarm"] = qjoWheatFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject WheatFarmBuilding::getQjoSilo()
{
    qjo["wheatFarm"] = qjoWheatFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

QJsonObject WheatFarmBuilding::getQjoWheatFarm()
{
    qjo["wheatFarm"] = qjoWheatFarm;
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoWheatFarm;
}

int WheatFarmBuilding::getPlayerLevel()
{
    return qjo["level"].toInt();
}

void WheatFarmBuilding::setExp(int add)
{
    if(getExp() + add >= upperBoundExp)
    {
        qjo["level"] = getPlayerLevel() + 1;
        qjo["exp"] = getExp() + add - upperBoundExp;
        //checkLevel();
    }
    else
    {
        qjo["exp"] = getExp() + add;
    }
}

int WheatFarmBuilding::getExp()
{
    return qjo["exp"].toInt();
}

void WheatFarmBuilding::changeCoin(int change)
{
    qjo["coin"] = getCoin() + change;    
}

int WheatFarmBuilding::getCoin()
{
    return qjo["coin"].toInt();
}

int WheatFarmBuilding::getDay()
{
    return qjo["day"].toInt();
}

int WheatFarmBuilding::getUsedCapacity()
{
    return qjoStorage["usedCapacity"].toInt();
}

bool WheatFarmBuilding::addShovel(int change)
{
    int storageMaxCapacity = 5;
    for(int i = 2; i <= qjoStorage["level"].toInt(); i++)
        storageMaxCapacity = ceil(storageMaxCapacity * 1.5);

    if(getUsedCapacity() + change > storageMaxCapacity || getShovel() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["shovel"] = getShovel() + change;
    return true;
}

int WheatFarmBuilding::getShovel()
{
    return qjoStorage["shovel"].toInt();
}

bool WheatFarmBuilding::addWheat(int change)
{
    int maxCapacitySilo = pow(2, qjoSilo["level"].toInt() - 1) * 10;
    if(getWheat() + change > maxCapacitySilo || getWheat() + change < 0)
        return false;
    qjoSilo["wheat"] = getWheat() + change;
    return true;
}

int WheatFarmBuilding::getWheat()
{
    return qjoSilo["wheat"].toInt();
}

WheatFarmBuilding::WheatFarmBuilding(QJsonObject _qjo)
{
    qjo = _qjo;
    qjoStorage = qjo["storage"].toObject();
    qjoSilo = qjo["silo"].toObject();
    qjoWheatFarm = qjo["wheatFarm"].toObject();
    maxPlantingArea = pow(2, qjoWheatFarm["level"].toInt() - 1) * 5;
    upperBoundExp = (pow(2, qjo["level"].toInt()) - 1) * 10;
}

void WheatFarmBuilding::passDayToFinishUpgrading()
{
    qjoWheatFarm["daysToFinishUpgrading"] = getDaysToFinishUpgrading() - 1;
}

int WheatFarmBuilding::getDaysToFinishUpgrading()
{
    return qjoWheatFarm["daysToFinishUpgrading"].toInt();
}

bool WheatFarmBuilding::canUpgrade()
{
    if(getPlayerLevel() < 2)
        return false;
    if(getShovel() < maxPlantingArea)
        return false;
    if(getCoin() < maxPlantingArea * 5)
        return false;
    return true;
}

void WheatFarmBuilding::startUpgrading()
{
    if(!canUpgrade())
        return;
    qjoWheatFarm["daysToFinishUpgrading"] = 2;
    addShovel(maxPlantingArea);
    changeCoin(-5 * maxPlantingArea);
}

void WheatFarmBuilding::finishUpgrading()
{
    qjoWheatFarm["level"] = getLevel() + 1;
    maxPlantingArea *= 2;
    setExp(maxPlantingArea * 3);
}

int WheatFarmBuilding::getLevel()
{
    return qjoWheatFarm["level"].toInt();
}

void WheatFarmBuilding::setPlantingArea(int plantingArea)
{
    qjoWheatFarm["plantingArea"] = plantingArea;
}

int WheatFarmBuilding::getPlantingArea()
{
    return qjoWheatFarm["plantingArea"].toInt();
}

void WheatFarmBuilding::setFlag(int flag)
{
    qjoWheatFarm["flag"] = flag;
}

int WheatFarmBuilding::getFlag()
{
    return qjoWheatFarm["flag"].toInt();
}

void WheatFarmBuilding::passDayToFinishPlanting()
{
    qjoWheatFarm["daysToFinishPlanting"] = getDaysToFinishPlanting() - 1;
}

int WheatFarmBuilding::getDaysToFinishPlanting()
{
    return qjoWheatFarm["daysToFinishPlanting"].toInt();
}

void WheatFarmBuilding::startPlanting(int plantingArea)
{
    setPlantingArea(plantingArea);
    setFlag(2);
    qjoWheatFarm["daysToFinishPlanting"] = 2;
    addWheat(-1 * plantingArea);
    setExp(plantingArea);
}

void WheatFarmBuilding::finishPlanting()
{
    setFlag(3);
}

bool WheatFarmBuilding::canHarvest()
{
    int maxCapacitySilo = pow(2, qjoSilo["level"].toInt() - 1) * 10;
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

int WheatFarmBuilding::getMaxPlantingArea()
{
    return maxPlantingArea;
}
