#include "user.h"

User::User(QJsonObject _qjo, int _index) : BaseUser(_qjo),
                                           storage(_qjo),
                                           silo(_qjo),
                                           wheatFarm(_qjo),
                                           hayFarm(_qjo),
                                           poultryFarm((_qjo)),
                                           dairyFarm(_qjo),
                                           sheepFold(_qjo),
                                           shop(_qjo)
{
    index = _index;
}

QJsonObject User::getQjo()
{
    qjo["storage"] = storage.getQjoStorage();
    qjo["silo"] = silo.getQjoSilo();
    qjo["wheatFarm"] = wheatFarm.getQjoFarm();
    qjo["hayFarm"] = hayFarm.getQjoFarm();
    qjo["poultryFarm"] = poultryFarm.getQjoAnimalFarm();
    qjo["dairyFarm"] = dairyFarm.getQjoAnimalFarm();
    qjo["sheepfold"] = sheepFold.getQjoAnimalFarm();
    return qjo;
}

int User::getIndex()
{
    return index;
}

void User::checkDay()
{
    //check finishing upgrade of storage
    if (storage.getDaysToFinishUpgrading() != 0)
    {
        storage.passDayToFinishUpgrading();
        if (storage.getDaysToFinishUpgrading() == 0)
            storage.finishUpgrading();
    }

    //check spoiled milks in storage
    while (true)
    {
        if (storage.getMilk().size() == 0)
            break;
        if (storage.getMilk()[0].toInt() + 10 <= getDay())
            storage.addMilk(-1);
        else
            break;
    }

    //check finishing upgrade of silo
    if (silo.getDaysToFinishUpgrading() != 0)
    {
        silo.passDayToFinishUpgrading();
        if (silo.getDaysToFinishUpgrading() == 0)
            silo.finishUpgrading();
    }

    //check finishing upgrade of wheat farm
    if (wheatFarm.getDaysToFinishUpgrading() != 0)
    {
        wheatFarm.passDayToFinishUpgrading();
        if (wheatFarm.getDaysToFinishUpgrading() == 0)
            wheatFarm.finishUpgrading();
    }

    //check planting situation of wheat farm
    if (wheatFarm.getDaysToFinishPlanting() != 0)
    {
        wheatFarm.passDayToFinishPlanting();
        if (wheatFarm.getDaysToFinishPlanting() == 0)
            wheatFarm.finishPlanting();
    }

    //check establishing of hay farm
    if (hayFarm.getDaysToFinishEstablishing() > 0)
    {
        hayFarm.passDayToFinishEstablishing();
        if (hayFarm.getDaysToFinishEstablishing() == 0)
            hayFarm.finishEstablishing();
    }

    //check finishing upgrade of hay farm
    if (hayFarm.getDaysToFinishUpgrading() != 0)
    {
        hayFarm.passDayToFinishUpgrading();
        if (hayFarm.getDaysToFinishUpgrading() == 0)
            hayFarm.finishUpgrading();
    }

    //check planting situation of hay farm
    if (hayFarm.getDaysToFinishPlanting() != 0)
    {
        hayFarm.passDayToFinishPlanting();
        if (hayFarm.getDaysToFinishPlanting() == 0)
            hayFarm.finishPlanting();
    }

    //check plowing situation of hay farm
    if (hayFarm.getDaysToFinishPlowing() != 0)
    {
        hayFarm.passDayToFinishPlowing();
        if (hayFarm.getDaysToFinishPlowing() == 0)
            hayFarm.finishPlowing();
    }

    //check establishing of poultry farm
    if (poultryFarm.getDaysToFinishEstablishing() > 0)
    {
        poultryFarm.passDayToFinishEstablishing();
        if (poultryFarm.getDaysToFinishEstablishing() == 0)
            poultryFarm.finishEstablishing();
    }

    //check finishing upgrade of poultry farm
    if (poultryFarm.getDaysToFinishUpgrading() != 0)
    {
        poultryFarm.passDayToFinishUpgrading();
        if (poultryFarm.getDaysToFinishUpgrading() == 0)
            poultryFarm.finishUpgrading();
    }

    //check feeding of poultry farm
    if (poultryFarm.getDaysToFinishFeeding() != 0)
    {
        poultryFarm.passDayToFinishFeeding();
        if (poultryFarm.getDaysToFinishFeeding() == 0)
            poultryFarm.finishFeeding();
    }

    //check establishing of dairy farm
    if (dairyFarm.getDaysToFinishEstablishing() > 0)
    {
        dairyFarm.passDayToFinishEstablishing();
        if (dairyFarm.getDaysToFinishEstablishing() == 0)
            dairyFarm.finishEstablishing();
    }

    //check finishing upgrade of dairy farm
    if (dairyFarm.getDaysToFinishUpgrading() != 0)
    {
        dairyFarm.passDayToFinishUpgrading();
        if (dairyFarm.getDaysToFinishUpgrading() == 0)
            dairyFarm.finishUpgrading();
    }

    //check feeding of dairy farm
    if (dairyFarm.getDaysToFinishFeeding() != 0)
    {
        dairyFarm.passDayToFinishFeeding();
        if (dairyFarm.getDaysToFinishFeeding() == 0)
            dairyFarm.finishFeeding();
    }

    //check establishing of sheepfold
    if (sheepFold.getDaysToFinishEstablishing() > 0)
    {
        sheepFold.passDayToFinishEstablishing();
        if (sheepFold.getDaysToFinishEstablishing() == 0)
            sheepFold.finishEstablishing();
    }

    //check finishing upgrade of sheepfold
    if (sheepFold.getDaysToFinishUpgrading() != 0)
    {
        sheepFold.passDayToFinishUpgrading();
        if (sheepFold.getDaysToFinishUpgrading() == 0)
            sheepFold.finishUpgrading();
    }

    //check feeding of sheepfold
    if (sheepFold.getDaysToFinishFeeding() != 0)
    {
        sheepFold.passDayToFinishFeeding();
        if (sheepFold.getDaysToFinishFeeding() == 0)
            sheepFold.finishFeeding();
    }
}

bool User::setUsername(QString username)
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray arrUser = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();
    for (int i = 0; i < arrUser.size(); i++)
        if ((arrUser[i].toObject())["username"].toString() == username)
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
    for (int i = 0; i < arrUser.size(); i++)
        if ((arrUser[i].toObject())["email"].toString() == email)
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

HayFarmBuilding User::getHayFarm()
{
    return hayFarm;
}

PoultryFarmBuilding User::getPoultryFarm()
{
    return poultryFarm;
}

DairyFarmBuilding User::getDairyFarm()
{
    return dairyFarm;
}

SheepFoldBuilding User::getSheepfold()
{
    return sheepFold;
}

ShopBuilding User::getShop()
{
    return shop;
}

void User::saveToFile()
{
    ConnectToServer socket;
    QJsonDocument doc = QJsonDocument::fromJson(socket.get());

    QJsonArray arr = (doc.object())["users"].toArray();
    arr[index] = getQjo();
    QJsonObject main;
    main.insert("users", arr);
    doc.setObject(main);

    socket.set(doc.toJson());
}
