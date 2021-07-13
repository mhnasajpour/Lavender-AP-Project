#include "basestorage.h"

BaseStorage::BaseStorage(QJsonObject _qjo):
    BaseUser(_qjo)
{
    qjoStorage = _qjo["storage"].toObject();
    maxCapacityStorage = 5;
    for(int i = 2; i <= getLevelStorage(); i++)
        maxCapacityStorage = ceil(maxCapacityStorage * 1.5);
}

int BaseStorage::getLevelStorage()
{
    return qjoStorage["level"].toInt();
}

int BaseStorage::getUsedCapacity()
{
    return qjoStorage["usedCapacity"].toInt();
}

bool BaseStorage::addShovel(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getShovel() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["shovel"] = getShovel() + change;
    return true;
}

int BaseStorage::getShovel()
{
    return qjoStorage["shovel"].toInt();
}

bool BaseStorage::addNail(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getNail() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["nail"] = getNail() + change;
    return true;
}

int BaseStorage::getNail()
{
    return qjoStorage["nail"].toInt();
}

bool BaseStorage::addHay(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getHay() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["hay"] = getHay() + change;
    return true;
}

int BaseStorage::getHay()
{
    return qjoStorage["hay"].toInt();
}

bool BaseStorage::addEgg(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getEgg() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["egg"] = getEgg() + change;
    return true;
}

int BaseStorage::getEgg()
{
    return qjoStorage["egg"].toInt();
}

bool BaseStorage::addWool(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getWool() + change < 0)
        return false;
    qjoStorage["usedCapacity"] = getUsedCapacity() + change;
    qjoStorage["wool"] = getWool() + change;
    return true;
}

int BaseStorage::getWool()
{
    return qjoStorage["wool"].toInt();
}

bool BaseStorage::addMilk(int change)
{
    if(getUsedCapacity() + change > maxCapacityStorage || getMilk().size() + change < 0)
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

QJsonArray BaseStorage::getMilk()
{
    return qjoStorage["milk"].toArray();
}

int BaseStorage::getMaxCapacityStorage()
{
    return maxCapacityStorage;
}
