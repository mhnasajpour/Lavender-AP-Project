#ifndef SILOBUILDING_H
#define SILOBUILDING_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class SiloBuilding
{
private:
    QJsonObject qjo;
    QJsonObject qjoStorage;
    QJsonObject qjoSilo;
    int maxCapacity;
    int upperBoundExp;
public:
    QJsonObject getQjo();
    QJsonObject getQjoSilo();
    int getPlayerLevel();
    void setExp(int);
    int getExp();
    void changeCoin(int);
    int getCoin();
    int getDay();

    int getUsedCapacity();
    bool addNail(int);
    int getNail();

    SiloBuilding(QJsonObject);
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
    int getLevel();
    bool addWheat(int);
    int getWheat();
    int getMaxCapacity();
};

#endif // SILOBUILDING_H
