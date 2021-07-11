#ifndef WHEATFARMBUILDING_H
#define WHEATFARMBUILDING_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class WheatFarmBuilding
{
private:
    QJsonObject qjo;
    QJsonObject qjoStorage;
    QJsonObject qjoSilo;
    QJsonObject qjoWheatFarm;
    int maxPlantingArea;
    int upperBoundExp;
public:
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    QJsonObject getQjoWheatFarm();
    int getPlayerLevel();
    void setExp(int);
    int getExp();
    void changeCoin(int);
    int getCoin();
    int getDay();

    int getUsedCapacity();
    bool addShovel(int);
    int getShovel();

    bool addWheat(int);
    int getWheat();

    WheatFarmBuilding(QJsonObject);
    void passDayToFinishUpgrading();
    int getDaysToFinishUpgrading();
    bool canUpgrade();
    void startUpgrading();
    void finishUpgrading();
    int getLevel();
    void setPlantingArea(int);
    int getPlantingArea();
    void setFlag(int);
    int getFlag();
    void passDayToFinishPlanting();
    int getDaysToFinishPlanting();
    void startPlanting(int);
    void finishPlanting();
    bool canHarvest();
    void harvest();
    int getMaxPlantingArea();
};

#endif // WHEATFARMBUILDING_H
