#include "baseanimalfarm.h"

BaseAnimalFarm::BaseAnimalFarm(QJsonObject _qjo):
    BaseSilo(_qjo)
{
}

void BaseAnimalFarm::passDayToFinishEstablishing()
{
    qjoAnimalFarm["daysToFinishEstablishing"] = getDaysToFinishEstablishing() - 1;
}

int BaseAnimalFarm::getDaysToFinishEstablishing()
{
    return qjoAnimalFarm["daysToFinishEstablishing"].toInt();
}

bool BaseAnimalFarm::isLevelEnough()
{
    if(getLevelPlayer() < minLevelRequiredE)
        return false;
    return true;
}

bool BaseAnimalFarm::canEstablish()
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

void BaseAnimalFarm::startEstablishing()
{
    if(!canEstablish())
        return;
    addNail(-1 * nailE);
    addShovel(-1 * shovelE);
    changeCoin(-1 * coinE);
    qjoAnimalFarm["daysToFinishEstablishing"] = timeE;
}

void BaseAnimalFarm::finishEstablishing()
{
    qjoAnimalFarm["level"] = 1;
    setExp(addToExpE);
}

void BaseAnimalFarm::passDayToFinishUpgrading()
{
    qjoAnimalFarm["daysToFinishUpgrading"] = getDaysToFinishUpgrading() - 1;
}

int BaseAnimalFarm::getDaysToFinishUpgrading()
{
    return qjoAnimalFarm["daysToFinishUpgrading"].toInt();
}

bool BaseAnimalFarm::canUpgrade()
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

void BaseAnimalFarm::startUpgrading()
{
    if(!canUpgrade())
        return;
    addNail(-1 * nailU);
    addShovel(-1 * shovelU);
    changeCoin(-1 * coinU);
    qjoAnimalFarm["daysToFinishUpgrading"] = timeU;
}

void BaseAnimalFarm::finishUpgrading()
{
    qjoAnimalFarm["level"] = getLevelAnimalFarm() + 1;
    maxCapacityAnimalFarm *= 2;
    setExp(addToExpU);
}

int BaseAnimalFarm::getLevelAnimalFarm()
{
    return qjoAnimalFarm["level"].toInt();
}

bool BaseAnimalFarm::addAnimals(int change)
{
    if(getAnimals() + change > maxCapacityAnimalFarm || getAnimals() + change < 0)
        return false;
    qjoAnimalFarm["animals"] = getAnimals() + change;
    return true;
}

int BaseAnimalFarm::getAnimals()
{
    return qjoAnimalFarm["animals"].toInt();
}

void BaseAnimalFarm::setFlag(int flag)
{
    qjoAnimalFarm["flag"] = flag;
}

int BaseAnimalFarm::getFlag()
{
    return qjoAnimalFarm["flag"].toInt();
}

void BaseAnimalFarm::passDayToFinishFeeding()
{
    qjoAnimalFarm["daysToFinishFeeding"] = getDaysToFinishFeeding() - 1;
}

int BaseAnimalFarm::getDaysToFinishFeeding()
{
    return qjoAnimalFarm["daysToFinishFeeding"].toInt();
}

void BaseAnimalFarm::finishFeeding()
{
    setFlag(3);
}

int BaseAnimalFarm::getMaxCapacityAnimalFarm()
{
    return maxCapacityAnimalFarm;
}
