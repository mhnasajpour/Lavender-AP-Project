#include "basefarm.h"

BaseFarm::BaseFarm(QJsonObject _qjo):
    BaseSilo(_qjo)
{
}

void BaseFarm::passDayToFinishUpgrading()
{
    qjoFarm["daysToFinishUpgrading"] = getDaysToFinishUpgrading() - 1;
}

int BaseFarm::getDaysToFinishUpgrading()
{
    return qjoFarm["daysToFinishUpgrading"].toInt();
}

bool BaseFarm::canUpgrade()
{
    if(getNail() < nailU)
        return false;
    if(getShovel() < shovelU)
        return false;
    if(getCoin() < coinU)
        return false;
    if(getLevelPlayer() < minLevelRequiredU)
        return false;
    return true;
}

void BaseFarm::startUpgrading()
{
    if(!canUpgrade())
        return;
    addNail(-1 * nailU);
    addShovel(-1 * shovelU);
    changeCoin(-1 * coinU);
    qjoFarm["daysToFinishUpgrading"] = timeU;
}

void BaseFarm::finishUpgrading()
{
    qjoFarm["level"] = getLevelFarm() + 1;
    maxArea *= 2;
    setExp(addToExpU);

    shovelU = maxArea;
    coinU = maxArea * 5;
    addToExpU = maxArea * 3;
}

void BaseFarm::passDayToFinishEstablishing()
{
    qjoFarm["daysToFinishEstablishing"] = getDaysToFinishEstablishing() - 1;
}

int BaseFarm::getDaysToFinishEstablishing()
{
    return qjoFarm["daysToFinishEstablishing"].toInt();
}

bool BaseFarm::isLevelEnough()
{
    if(getLevelPlayer() < minLevelRequiredE)
        return false;
    return true;
}

bool BaseFarm::canEstablish()
{
    if(getNail() < nailE)
        return false;
    if(getShovel() < shovelE)
        return false;
    if(getCoin() < coinE)
        return false;
    if(getLevelPlayer() < minLevelRequiredE)
        return false;
    return true;
}

void BaseFarm::startEstablishing()
{
    if(!canEstablish())
        return;
    addNail(-1 * nailE);
    addShovel(-1 * shovelE);
    changeCoin(-1 * coinE);
    qjoFarm["daysToFinishEstablishing"] = timeE;
}

void BaseFarm::finishEstablishing()
{
    qjoFarm["level"] = 1;
    setExp(addToExpE);
}

int BaseFarm::getLevelFarm()
{
    return qjoFarm["level"].toInt();
}

void BaseFarm::setPlantingArea(int plantingArea)
{
    qjoFarm["plantingArea"] = plantingArea;
}

int BaseFarm::getPlantingArea()
{
    return qjoFarm["plantingArea"].toInt();
}

void BaseFarm::setFlag(int flag)
{
    qjoFarm["flag"] = flag;
}

int BaseFarm::getFlag()
{
    return qjoFarm["flag"].toInt();
}

void BaseFarm::passDayToFinishPlanting()
{
    qjoFarm["daysToFinishPlanting"] = getDaysToFinishPlanting() - 1;
}

int BaseFarm::getDaysToFinishPlanting()
{
    return qjoFarm["daysToFinishPlanting"].toInt();
}

void BaseFarm::finishPlanting()
{
    setFlag(3);
}

int BaseFarm::getMaxArea()
{
    return maxArea;
}
