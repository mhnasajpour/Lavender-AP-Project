#include "storagebuilding.h"

StorageBuilding::StorageBuilding(QJsonObject _qjo) : BaseStorage(_qjo)
{
    nailU = getLevelStorage();
    shovelU = getLevelStorage() - 1;
    coinU = pow(getLevelStorage(), 3) * 10;
    timeU = 5;
    minLevelRequiredU = 0;
    maxLevelRequiredU = getLevelPlayer();
    addToExpU = getLevelStorage() * 3;
}

QJsonObject StorageBuilding::getQjo()
{
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject StorageBuilding::getQjoStorage()
{
    qjo["storage"] = qjoStorage;
    return qjoStorage;
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
    if (getNail() < nailU)
        return false;
    if (getShovel() < shovelU)
        return false;
    if (getCoin() < coinU)
        return false;
    if (getLevelPlayer() < minLevelRequiredU)
        return false;
    if (getLevelStorage() >= maxLevelRequiredU)
        return false;
    return true;
}

void StorageBuilding::startUpgrading()
{
    if (!canUpgrade())
        return;
    addNail(-1 * nailU);
    addShovel(-1 * shovelU);
    changeCoin(-1 * coinU);
    qjoStorage["daysToFinishUpgrading"] = timeU;
}

void StorageBuilding::finishUpgrading()
{
    qjoStorage["level"] = getLevelStorage() + 1;
    maxCapacityStorage = ceil(maxCapacityStorage * 1.5);
    setExp(addToExpU);

    nailU++;
    shovelU++;
    coinU = pow(getLevelStorage(), 3) * 10;
    maxLevelRequiredU++;
    addToExpU += 3;
}