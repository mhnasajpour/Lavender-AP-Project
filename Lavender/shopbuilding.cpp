#include "shopbuilding.h"

ShopBuilding::ShopBuilding(QJsonObject _qjo) : BaseSilo(_qjo)
{
    qjo = _qjo;
}

QJsonObject ShopBuilding::getQjo()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjo;
}

QJsonObject ShopBuilding::getQjoStorage()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoStorage;
}

QJsonObject ShopBuilding::getQjoSilo()
{
    qjo["silo"] = qjoSilo;
    qjo["storage"] = qjoStorage;
    return qjoSilo;
}

int ShopBuilding::buyWheat()
{
    if (getCoin() < 3)
        return 2;
    if (!addWheat(1))
        return 3;
    changeCoin(-3);
    setExp(1);
    return 0;
}

int ShopBuilding::sellWheat()
{
    if (!addWheat(-1))
        return 4;
    changeCoin(2);
    setExp(1);
    return 0;
}

int ShopBuilding::buyHay()
{
    if (getLevelPlayer() < 3)
        return 1;
    if (getCoin() < 6)
        return 2;
    if (!addHay(1))
        return 3;
    changeCoin(-6);
    setExp(2);
    return 0;
}

int ShopBuilding::sellHay()
{
    if (getLevelPlayer() < 3)
        return 1;
    if (!addHay(-1))
        return 4;
    changeCoin(4);
    setExp(2);
    return 0;
}

int ShopBuilding::sellEgg()
{
    if (getLevelPlayer() < 2)
        return 1;
    if (!addEgg(-1))
        return 4;
    changeCoin(8);
    setExp(3);
    return 0;
}

int ShopBuilding::sellMilk()
{
    if (getLevelPlayer() < 4)
        return 1;
    if (!addMilk(-1))
        return 4;
    changeCoin(12);
    setExp(5);
    return 0;
}

int ShopBuilding::sellWool()
{
    if (getLevelPlayer() < 6)
        return 1;
    if (!addWool(-1))
        return 4;
    changeCoin(23);
    setExp(10);
    return 0;
}

int ShopBuilding::buyPoultry()
{
    if (getLevelPlayer() < 2)
        return 1;
    if(!qjo["poultryFarm"].toObject()["level"].toInt())
        return 1;
    if (getCoin() < 20)
        return 2;
    if (qjo["poultryFarm"].toObject()["animals"].toInt() + 1 > pow(2, qjo["poultryFarm"].toObject()["level"].toInt()))
        return 3;
    QJsonObject tmp = qjo["poultryFarm"].toObject();
    tmp["animals"] = qjo["poultryFarm"].toObject()["animals"].toInt() + 1;
    qjo["poultryFarm"] = tmp;
    changeCoin(-20);
    setExp(5);
    return 0;
}

int ShopBuilding::sellPoultry()
{
    if (getLevelPlayer() < 2)
        return 1;
    if (qjo["poultryFarm"].toObject()["animals"].toInt() - 1 < 0)
        return 4;
    QJsonObject tmp = qjo["poultryFarm"].toObject();
    tmp["animals"] = qjo["poultryFarm"].toObject()["animals"].toInt() - 1;
    qjo["poultryFarm"] = tmp;
    changeCoin(15);
    setExp(5);
    return 0;
}

int ShopBuilding::buyCattle()
{
    if (getLevelPlayer() < 4)
        return 1;
    if(!qjo["dairyFarm"].toObject()["level"].toInt())
        return 1;
    if (getCoin() < 70)
        return 2;
    if (qjo["dairyFarm"].toObject()["animals"].toInt() + 1 > pow(2, qjo["dairyFarm"].toObject()["level"].toInt()))
        return 3;
    QJsonObject tmp = qjo["dairyFarm"].toObject();
    tmp["animals"] = qjo["dairyFarm"].toObject()["animals"].toInt() + 1;
    qjo["dairyFarm"] = tmp;
    changeCoin(-70);
    setExp(10);
    return 0;
}

int ShopBuilding::sellCattle()
{
    if (getLevelPlayer() < 4)
        return 1;
    if (qjo["dairyFarm"].toObject()["animals"].toInt() - 1 < 0)
        return 4;
    QJsonObject tmp = qjo["dairyFarm"].toObject();
    tmp["animals"] = qjo["dairyFarm"].toObject()["animals"].toInt() - 1;
    qjo["dairyFarm"] = tmp;
    changeCoin(50);
    setExp(10);
    return 0;
}

int ShopBuilding::buySheep()
{
    if (getLevelPlayer() < 6)
        return 1;
    if(!qjo["sheepfold"].toObject()["level"].toInt())
        return 1;
    if (getCoin() < 80)
        return 2;
    if (qjo["sheepfold"].toObject()["animals"].toInt() + 1 > pow(2, qjo["sheepfold"].toObject()["level"].toInt()))
        return 3;
    QJsonObject tmp = qjo["sheepfold"].toObject();
    tmp["animals"] = qjo["sheepfold"].toObject()["animals"].toInt() + 1;
    qjo["sheepfold"] = tmp;
    changeCoin(-80);
    setExp(15);
    return 0;
}

int ShopBuilding::sellSheep()
{
    if (getLevelPlayer() < 6)
        return 1;
    if (qjo["sheepfold"].toObject()["animals"].toInt() - 1 < 0)
        return 4;
    QJsonObject tmp = qjo["sheepfold"].toObject();
    tmp["animals"] = qjo["sheepfold"].toObject()["animals"].toInt() - 1;
    qjo["sheepfold"] = tmp;
    changeCoin(70);
    setExp(15);
    return 0;
}

int ShopBuilding::buyNail()
{
    if (getCoin() < 30)
        return 2;
    if (!addNail(1))
        return 3;
    changeCoin(-30);
    setExp(4);
    return 0;
}

int ShopBuilding::sellNail()
{
    if (!addNail(-1))
        return 4;
    changeCoin(20);
    setExp(4);
    return 0;
}

int ShopBuilding::buyShovel()
{
    if (getCoin() < 50)
        return 2;
    if (!addShovel(1))
        return 3;
    changeCoin(-50);
    setExp(8);
    return 0;
}

int ShopBuilding::sellShovel()
{
    if (!addShovel(-1))
        return 4;
    changeCoin(30);
    setExp(8);
    return 0;
}
