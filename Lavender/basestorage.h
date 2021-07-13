#ifndef BASESTORAGE_H
#define BASESTORAGE_H

#include "baseuser.h"

class BaseStorage: public BaseUser
{
protected:
    QJsonObject qjoStorage;
    int maxCapacityStorage;
public:
    BaseStorage(QJsonObject);
    virtual QJsonObject getQjo() = 0;
    virtual QJsonObject getQjoStorage() = 0;
    int getLevelStorage();
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
    int getMaxCapacityStorage();
};

#endif // BASESTORAGE_H
