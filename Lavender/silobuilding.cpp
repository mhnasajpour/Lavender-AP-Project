#include "silobuilding.h"

SiloBuilding::SiloBuilding(QJsonObject _qjo):
    BaseSilo(_qjo)
{
    nailU = getLevelSilo() * 2;
    shovelU = getLevelSilo() - 2;
    if(shovelU < 0)
        shovelU = 0;
    coinU = pow(getLevelSilo() * 2, 2) * 100;
    timeU = 4;
    minLevelRequiredU = 0;
    maxLevelRequiredU = getLevelPlayer() - 1;
    addToExpU = getLevelSilo() * 2;
}

QJsonObject SiloBuilding::getQjo()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject SiloBuilding::getQjoStorage()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject SiloBuilding::getQjoSilo()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
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
    if(getNail() < nailU)
        return false;
    if(getShovel() < shovelU)
        return false;
    if(getCoin() < coinU)
        return false;
    if(getLevelPlayer() < minLevelRequiredU)
        return false;
    if(getLevelSilo() >= maxLevelRequiredU)
        return false;
    return true;
}

void SiloBuilding::startUpgrading()
{
    if(!canUpgrade())
        return;
    addNail(-1 * nailU);
    addShovel(-1 * shovelU);
    changeCoin(-1 * coinU);
    qjoSilo["daysToFinishUpgrading"] = timeU;
}

void SiloBuilding::finishUpgrading()
{
    qjoSilo["level"] = getLevelSilo() + 1;
    maxCapacitySilo *= 2;
    setExp(addToExpU);

    nailU+= 2;
    shovelU++;
    coinU = pow(getLevelSilo() * 2, 2) * 100;
    maxLevelRequiredU++;
    addToExpU += 2;
}
