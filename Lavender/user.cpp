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

void User::setLevel(int level) // + level
{
    qjo["level"] = QJsonValue(level);
}

int User::getLevel()
{
    return qjo["level"].toInt();
}

void User::setExp(int exp)  // - + exp
{
    qjo["exp"] = QJsonValue(exp);
}

int User::getExp()
{
    return qjo["exp"].toInt();
}

void User::setCoin(int coin) // - + coin
{
    qjo["coin"] = QJsonValue(coin);
}

int User::getCoin()
{
    return qjo["coin"].toInt();
}

void User::setTime(int time)  // + time
{
    qjo["time"] = QJsonValue(time);
}

int User::getTime()
{
    return qjo["time"].toInt();
}
