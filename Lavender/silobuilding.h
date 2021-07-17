#ifndef SILOBUILDING_H
#define SILOBUILDING_H

#include "basesilo.h"
#include "baseupgrade.h"

class SiloBuilding : public BaseSilo, public BaseUpgrade
{
public:
    SiloBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
};

#endif // SILOBUILDING_H