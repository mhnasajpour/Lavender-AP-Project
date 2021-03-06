#ifndef USER_H
#define USER_H

#include <connecttoserver.h>
#include "baseuser.h"
#include "storagebuilding.h"
#include "silobuilding.h"
#include "wheatfarmbuilding.h"
#include "hayfarmbuilding.h"
#include "poultryfarmbuilding.h"
#include "dairyfarmbuilding.h"
#include "sheepfoldbuilding.h"
#include "shopbuilding.h"

class User : public BaseUser
{
private:
    int index;
    StorageBuilding storage;
    SiloBuilding silo;
    WheatFarmBuilding wheatFarm;
    HayFarmBuilding hayFarm;
    PoultryFarmBuilding poultryFarm;
    DairyFarmBuilding dairyFarm;
    SheepFoldBuilding sheepFold;
    ShopBuilding shop;

public:
    User(QJsonObject _qjo, int _index);
    QJsonObject getQjo();
    int getIndex();
    void checkDay();
    bool setUsername(QString);
    QString getUsername();
    void setPassword(QString);
    void setName(QString);
    QString getName();
    bool setEmail(QString);
    QString getEmail();
    void nextDay();
    StorageBuilding getStorage();
    SiloBuilding getSilo();
    WheatFarmBuilding getWheatFarm();
    HayFarmBuilding getHayFarm();
    PoultryFarmBuilding getPoultryFarm();
    DairyFarmBuilding getDairyFarm();
    SheepFoldBuilding getSheepfold();
    ShopBuilding getShop();
    void saveToFile();
};

#endif // USER_H
