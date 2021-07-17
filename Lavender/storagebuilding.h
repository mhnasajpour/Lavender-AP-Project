#ifndef STORAGEBUILDING_H
#define STORAGEBUILDING_H

#include "basestorage.h"
#include "baseupgrade.h"

class StorageBuilding : public BaseStorage, public BaseUpgrade
{
public:
    StorageBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
};

#endif // STORAGEBUILDING_H