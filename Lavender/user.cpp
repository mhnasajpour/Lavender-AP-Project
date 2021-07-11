#include "user.h"

User::User(QJsonObject _qjo, int _index):
    storage(_qjo),
    silo(_qjo),
    wheatFarm(_qjo)
{
    qjo = _qjo;
    index = _index;
    upperBoundExp = (pow(2, qjo["level"].toInt()) - 1) * 10;
}

QJsonObject User::getQjo()
{
    qjo["storage"] = storage.getQjoStorage();
    qjo["silo"] = silo.getQjoSilo();
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
    qjo["wheatFarm"] = wheatFarm.getQjoWheatFarm();
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

int User::getLevel()
{
    return qjo["level"].toInt();
}

void User::setExp(int add)
{
    if(getExp() + add >= upperBoundExp)
    {
        qjo["level"] = getLevel() + 1;
        qjo["exp"] = getExp() + add - upperBoundExp;
        //checkLevel();
    }
    else
    {
        qjo["exp"] = getExp() + add;
    }
}

int User::getExp()
{
    return qjo["exp"].toInt();
}

void User::changeCoin(int change)
{
    qjo["coin"] = getCoin() + change;
}

int User::getCoin()
{
    return qjo["coin"].toInt();
}

void User::nextDay()
{
    qjo["day"] = getDay() + 1;
    setExp(1);
    checkDay();
}

int User::getDay()
{
    return qjo["day"].toInt();
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
