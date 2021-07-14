#include "user.h"

User::User(QJsonObject _qjo, int _index):
    BaseUser(_qjo),
    storage(_qjo),
    silo(_qjo),
    wheatFarm(_qjo),
    hayFarm(_qjo)
{
    index = _index;
}

QJsonObject User::getQjo()
{
    qjo["storage"] = storage.getQjoStorage();
    qjo["silo"] = silo.getQjoSilo();
    qjo["wheatFarm"] = wheatFarm.getQjoFarm();
    qjo["hayFarm"] = hayFarm.getQjoFarm();
    return qjo;
}

int User::getIndex()
{
    return index;
}

void User::checkDay()
{
    //check finishing upgrade of storage
    if(storage.getDaysToFinishUpgrading() != 0)
    {
        storage.passDayToFinishUpgrading();
        if(storage.getDaysToFinishUpgrading() == 0)
            storage.finishUpgrading();
    }

    //check spoiled milks
    while(true)
    {
        if(storage.getMilk().size() == 0)
            break;
        if(storage.getMilk()[0].toInt() + 10 <= getDay())
            storage.addMilk(-1);
        else
            break;
    }

    //check finishing upgrade of silo
    if(silo.getDaysToFinishUpgrading() != 0)
    {
        silo.passDayToFinishUpgrading();
        if(silo.getDaysToFinishUpgrading() == 0)
            silo.finishUpgrading();
    }

    //check finishing upgrade of wheat farm
    if(wheatFarm.getDaysToFinishUpgrading() != 0)
    {
        wheatFarm.passDayToFinishUpgrading();
        if(wheatFarm.getDaysToFinishUpgrading() == 0)
            wheatFarm.finishUpgrading();
    }

    //check planting situation of wheat farm
    if(wheatFarm.getDaysToFinishPlanting() != 0)
    {
        wheatFarm.passDayToFinishPlanting();
        if(wheatFarm.getDaysToFinishPlanting() == 0)
            wheatFarm.finishPlanting();
    }

    //check finishing upgrade of hay farm
    if(hayFarm.getDaysToFinishUpgrading() != 0)
    {
        hayFarm.passDayToFinishUpgrading();
        if(hayFarm.getDaysToFinishUpgrading() == 0)
            hayFarm.finishUpgrading();
    }

    //check planting situation of hay farm
    if(hayFarm.getDaysToFinishPlanting() != 0)
    {
        hayFarm.passDayToFinishPlanting();
        if(hayFarm.getDaysToFinishPlanting() == 0)
            hayFarm.finishPlanting();
    }

    //check plowing situation of hay farm
    if(hayFarm.getDaysToFinishPlowing() != 0)
    {
        hayFarm.passDayToFinishPlowing();
        if(hayFarm.getDaysToFinishPlowing() == 0)
            hayFarm.finishPlowing();
    }

    //check establishing of hay farm
    if(hayFarm.getDaysToFinishEstablishing() > 0)
    {
        hayFarm.passDayToFinishEstablishing();
        if(hayFarm.getDaysToFinishEstablishing() == 0)
            hayFarm.finishEstablishing();
    }
}

bool User::setUsername(QString username)
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray arrUser = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();
    for(int i = 0; i < arrUser.size(); i++)
        if((arrUser[i].toObject())["username"].toString() == username)
            return false;
    qjo["username"] = username;
    return true;
}

QString User::getUsername()
{
    return qjo["username"].toString();
}

void User::setPassword(QString password)
{
    std::hash<QString> hashedPassword;
    qjo["password"] = QString::number((unsigned long)hashedPassword(password));
}

void User::setName(QString name)
{
    qjo["name"] = name;
}

QString User::getName()
{
    return qjo["name"].toString();
}

bool User::setEmail(QString email)
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray arrUser = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();
    for(int i = 0; i < arrUser.size(); i++)
        if((arrUser[i].toObject())["email"].toString() == email)
            return false;
    qjo["email"] = email;
    return true;
}

QString User::getEmail()
{
    return qjo["email"].toString();
}

void User::nextDay()
{
    qjo["day"] = getDay() + 1;
    setExp(1);
    checkDay();
}

StorageBuilding User::getStorage()
{
    return storage;
}

SiloBuilding User::getSilo()
{
    return silo;
}

WheatFarmBuilding User::getWheatFarm()
{
    return wheatFarm;
}

HayFarmBuilding &User::getHayFarm()
{
    return hayFarm;
}

void User::saveToFile()
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray arr = (doc.object())["users"].toArray();
    arr[index] = getQjo();
    QJsonObject main;
    main.insert("users", arr);
    doc.setObject(main);

    QFile file1("Users.json");
    file1.open(QIODevice::ReadWrite | QIODevice::Truncate);
    file1.write(doc.toJson());
    file1.close();
}
