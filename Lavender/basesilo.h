#ifndef BASESILO_H
#define BASESILO_H

#include "basestorage.h"

class BaseSilo: public BaseStorage
{
protected:
    QJsonObject qjoSilo;
    int maxCapacitySilo;
public:
    BaseSilo(QJsonObject);
    virtual QJsonObject getQjo() = 0;
    virtual QJsonObject getQjoStorage() = 0;
    virtual QJsonObject getQjoSilo() = 0;
    int getLevelSilo();
    bool addWheat(int);
    int getWheat();
    int getMaxCapacitySilo();
};

#endif // BASESILO_H
