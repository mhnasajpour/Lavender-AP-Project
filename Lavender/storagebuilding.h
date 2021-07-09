#ifndef STORAGEBUILDING_H
#define STORAGEBUILDING_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class StorageBuilding
{
private:
    QJsonObject qjo;
    QJsonObject qjoStorage;
    int maxCapacity;
    int upperBoundExp;
public:
    QJsonObject getQjo();
    int getPlayerLevel();
    void setExp(int);
    int getExp();
    void changeCoin(int);
    int getCoin();
    int getDay();

    StorageBuilding(QJsonObject);
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
    int getLevel();
    int getUsedCapacity();
    bool addShovel(int);
    int getShovel();
    bool addNail(int);
    int getNail();
    bool addHay(int);
    int getHay();
    bool addEgg(int);
    int getEgg();
    bool addWool(int);
    int getWool();
    bool addMilk(int);
    QJsonArray getMilk();
    int getMaxCapacity();
};

#endif // STORAGEBUILDING_H
