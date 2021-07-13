#include "basesilo.h"

BaseSilo::BaseSilo(QJsonObject _qjo):
    BaseStorage(_qjo)
{
    qjoSilo = qjo["silo"].toObject();
    maxCapacitySilo = pow(2, qjoSilo["level"].toInt() - 1) * 10;
}

int BaseSilo::getLevelSilo()
{
    return qjoSilo["level"].toInt();
}

bool BaseSilo::addWheat(int change)
{
    if(getWheat() + change > maxCapacitySilo || getWheat() + change < 0)
        return false;
    qjoSilo["wheat"] = getWheat() + change;
    return true;
}

int BaseSilo::getWheat()
{
    return qjoSilo["wheat"].toInt();
}

int BaseSilo::getMaxCapacitySilo()
{
    return maxCapacitySilo;
}
