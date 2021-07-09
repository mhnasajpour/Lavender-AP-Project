#include "storagebuilding.h"
#include <QDebug>

QJsonObject StorageBuilding::getQjo()
{
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject StorageBuilding::getQjoStorage()
{
    return qjoStorage;
}

int StorageBuilding::getPlayerLevel()
{
    return qjo["level"].toInt();
}

void StorageBuilding::setExp(int add)
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

int StorageBuilding::getExp()
{
    return qjo["exp"].toInt();
}

void StorageBuilding::changeCoin(int change)
{
    qjo["coin"] = getCoin() + change;
}

int StorageBuilding::getCoin()
{
    return qjo["coin"].toInt();
}

int StorageBuilding::getDay()
{
    return qjo["day"].toInt();
}

StorageBuilding::StorageBuilding(QJsonObject _qjo)
{
    qjo = _qjo;
    qjoStorage = qjo["storage"].toObject();
    maxCapacity = 5;
    for(int i = 2; i <= getLevel(); i++)
        maxCapacity = ceil(maxCapacity * 1.5);
    upperBoundExp = (pow(2, qjo["level"].toInt()) - 1) * 10;
}

void StorageBuilding::passDayToFinishUpgrading()
{
    qjoStorage["daysToFinishUpgrading"] = getDaysToFinishUpgrading() - 1;
}

int StorageBuilding::getDaysToFinishUpgrading()
{
    return qjoStorage["daysToFinishUpgrading"].toInt();
}

bool StorageBuilding::canUpgrade()
{
    if(getLevel() == getPlayerLevel())
        return false;
    if(getNail() < getLevel())
        return false;
    if(getShovel() < getLevel() - 1)
        return false;
    if(getCoin() < pow(getLevel(), 3) * 10)
        return false;
    return true;
}

void StorageBuilding::startUpgrading()
{
    if(!canUpgrade())
        return;
    qjoStorage["daysToFinishUpgrading"] = 5;
    addNail(-1 * getLevel());
    addShovel(-1 * (getLevel() - 1));
    changeCoin(-10 * pow(getLevel(), 3));
}

void StorageBuilding::finishUpgrading()
{
    qjoStorage["level"] = getLevel() + 1;
    maxCapacity = ceil(maxCapacity * 1.5);
    setExp(getLevel() * 3);
}

int StorageBuilding::getLevel()
{
    return qjoStorage["level"].toInt();
}

int StorageBuilding::getUsedCapacity()
{
    return qjoStorage["usedCapacity"].toInt();
}

bool StorageBuilding::addShovel(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getShovel() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["shovel"] = getShovel() + change;
    return true;
}

int StorageBuilding::getShovel()
{
    return qjoStorage["shovel"].toInt();
}

bool StorageBuilding::addNail(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getNail() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["nail"] = getNail() + change;
    return true;
}

int StorageBuilding::getNail()
{
    return qjoStorage["nail"].toInt();
}

bool StorageBuilding::addHay(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getHay() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["hay"] = getHay() + change;
    return true;
}

int StorageBuilding::getHay()
{
    return qjoStorage["hay"].toInt();
}

bool StorageBuilding::addEgg(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getEgg() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["egg"] = getEgg() + change;
    return true;
}

int StorageBuilding::getEgg()
{
    return qjoStorage["egg"].toInt();
}

bool StorageBuilding::addWool(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getWool() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["wool"] = getWool() + change;
    return true;
}

int StorageBuilding::getWool()
{
    return qjoStorage["wool"].toInt();
}

bool StorageBuilding::addMilk(int change)
{
    if(getUsedCapacity() + change > maxCapacity || getMilk().size() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    QJsonArray milk = getMilk();
    for(int i = 0; i < change; i++)
        if(change > 0)
            milk.push_back(getDay());
        else
            milk.pop_front();
    qjoStorage["milk"] = milk;
    return true;
}

QJsonArray StorageBuilding::getMilk()
{
    return qjoStorage["milk"].toArray();
}

int StorageBuilding::getMaxCapacity()
{
    return maxCapacity;
}
