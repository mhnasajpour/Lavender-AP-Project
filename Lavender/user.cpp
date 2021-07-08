#include "user.h"

User::User(QJsonObject _qjo, int _index)
{
    qjo = _qjo;
    index = _index;
}

QJsonObject User::getQjo()
{
    return qjo;
}

int User::getIndex()
{
    return index;
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
    qjo["username"] = QJsonValue(username);
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
    qjo["name"] = QJsonValue(name);
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
    qjo["email"] = QJsonValue(email);
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
    int upperBoundExp = (powl(2, getLevel()) - 1) * 10;
    if(getExp() + add >= upperBoundExp)
    {
        qjo["level"] = getLevel() + 1;
        qjo["exp"] = QJsonValue(getExp() + add - upperBoundExp);
        //checkLevel
    }
    else
    {
        qjo["exp"] = QJsonValue(getExp() + add);
    }
}

int User::getExp()
{
    return qjo["exp"].toInt();
}

void User::changeCoin(int change)
{
    qjo["coin"] = QJsonValue(getCoin() + change);
}

int User::getCoin()
{
    return qjo["coin"].toInt();
}

void User::nextDay()
{
    qjo["time"] = QJsonValue(getDay() + 1);
}

int User::getDay()
{
    return qjo["time"].toInt();
}
