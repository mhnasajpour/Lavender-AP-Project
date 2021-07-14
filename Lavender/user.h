#ifndef USER_H
#define USER_H

#include "baseuser.h"
#include "storagebuilding.h"
#include "silobuilding.h"
#include "wheatfarmbuilding.h"
#include "hayfarmbuilding.h"

class User: public BaseUser
{
private:
    int index;
    StorageBuilding storage;
    SiloBuilding silo;
    WheatFarmBuilding wheatFarm;
    HayFarmBuilding hayFarm;
public:
    User(QJsonObject _qjo, int _index);
    QJsonObject getQjo();
    int getIndex();
    void checkDay();
    //void checkLevel();
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
    HayFarmBuilding& getHayFarm();
    /*PoultryFarm getPoultryFarm ();
    DairyFarm getDairyFarm ();
    Sheepfold getSheepfold ();
    void buy (QString str, int num);
    void sell (QString str, int num);
    ~User();*/
    void saveToFile();
};

#endif // USER_H
