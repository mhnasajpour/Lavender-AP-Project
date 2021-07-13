#include "baseuser.h"

BaseUser::BaseUser(QJsonObject _qjo)
{
    qjo = _qjo;
    upperBoundExp = (pow(2, qjo["level"].toInt()) - 1) * 10;
}

int BaseUser::getLevelPlayer()
{
    return qjo["level"].toInt();
}

void BaseUser::setExp(int add)
{
    if(getExp() + add >= upperBoundExp)
    {
        qjo["level"] = getLevelPlayer() + 1;
        qjo["exp"] = getExp() + add - upperBoundExp;
        //checkLevel();
    }
    else
    {
        qjo["exp"] = getExp() + add;
    }
}

int BaseUser::getExp()
{
    return qjo["exp"].toInt();
}

void BaseUser::changeCoin(int change)
{
    qjo["coin"] = getCoin() + change;
}

int BaseUser::getCoin()
{
    return qjo["coin"].toInt();
}

int BaseUser::getDay()
{
    return qjo["day"].toInt();
}
