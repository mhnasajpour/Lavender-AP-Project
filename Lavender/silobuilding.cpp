#include "silobuilding.h"
#include <QDebug>

QJsonObject SiloBuilding::getQjo()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject SiloBuilding::getQjoStorage()
{
    return qjoStorage;
}

QJsonObject SiloBuilding::getQjoSilo()
{
    return qjoSilo;
}

int SiloBuilding::getPlayerLevel()
{
    return qjo["level"].toInt();
}

void SiloBuilding::setExp(int add)
{
    if(getExp() + add >= upperBoundExp)
    {
        qjo["level"] = getLevel() + 1;
        qjo["exp"] = getExp() + add - upperBoundExp;
        //checkLevel();
    }
    else
    {
        qjo["exp"] = getExp() + add;
    }
}

int SiloBuilding::getExp()
{
    return qjo["exp"].toInt();
}

void SiloBuilding::changeCoin(int change)
{
    qjo["coin"] = getCoin() + change;
}

int SiloBuilding::getCoin()
{
    return qjo["coin"].toInt();
}

int SiloBuilding::getDay()
{
    return qjo["day"].toInt();
}

int SiloBuilding::getUsedCapacity()
{
    return qjoStorage["usedCapacity"].toInt();
}

bool SiloBuilding::addNail(int change)
{
    int storageMaxCapacity = 5;
    for(int i = 2; i <= qjoStorage["level"].toInt(); i++)
        storageMaxCapacity = ceil(storageMaxCapacity * 1.5);

    if(getUsedCapacity() + change > storageMaxCapacity || getNail() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["nail"] = getNail() + change;
    return true;
}

int SiloBuilding::getNail()
{
    return qjoStorage["nail"].toInt();
}

SiloBuilding::SiloBuilding(QJsonObject _qjo)
{
    qjo = _qjo;
    qjoStorage = qjo["storage"].toObject();
    qjoSilo = qjo["silo"].toObject();
    maxCapacity = pow(2, qjoSilo["level"].toInt() - 1) * 10;
    upperBoundExp = (pow(2, qjo["level"].toInt()) - 1) * 10;
}

void SiloBuilding::passDayToFinishUpgrading()
{
    qjoSilo["daysToFinishUpgrading"] = getDaysToFinishUpgrading() - 1;
}

int SiloBuilding::getDaysToFinishUpgrading()
{
    return qjoSilo["daysToFinishUpgrading"].toInt();
}

bool SiloBuilding::canUpgrade()
{
    if(getLevel() >= getPlayerLevel() - 1)
        return false;
    if(getNail() < getLevel() * 2)
        return false;
    if(getCoin() < pow(getLevel() * 2, 2) * 100)
        return false;
    return true;
}

void SiloBuilding::startUpgrading()
{
    if(!canUpgrade())
        return;
    qjoSilo["daysToFinishUpgrading"] = 4;
    addNail(-2 * getLevel());
    changeCoin(-100 * pow(getLevel() * 2, 2));
}

void SiloBuilding::finishUpgrading()
{
    qjoSilo["level"] = getLevel() + 1;
    maxCapacity *= 2;
    setExp(getLevel() * 2);
}

int SiloBuilding::getLevel()
{
    return qjoSilo["level"].toInt();
}

bool SiloBuilding::addWheat(int change)
{
    if(getWheat() + change > maxCapacity || getWheat() + change < 0)
        return false;
    qjoSilo["wheat"] = getWheat() + change;
    return true;
}

int SiloBuilding::getWheat()
{
    return qjoSilo["wheat"].toInt();
}

int SiloBuilding::getMaxCapacity()
{
    return maxCapacity;
}
