#ifndef SHOPBUILDING_H
#define SHOPBUILDING_H

#include "basesilo.h"

class ShopBuilding: public BaseSilo
{
    QJsonObject qjoShop;
public:
    ShopBuilding(QJsonObject);
    QJsonObject getQjo();
    QJsonObject getQjoStorage();
    QJsonObject getQjoSilo();
    int buyWheat();
    int sellWheat();
    int buyHay();
    int sellHay();
    int sellEgg();
    int sellMilk();
    int sellWool();
    int buyPoultry();
    int sellPoultry();
    int buyCattle();
    int sellCattle();
    int buySheep();
    int sellSheep();
    int buyNail();
    int sellNail();
    int buyShovel();
    int sellShovel();
};

#endif // SHOPBUILDING_H
