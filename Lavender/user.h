#ifndef USER_H
#define USER_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class User
{
private:
    QJsonObject qjo;
    int index;
public:
    User(QJsonObject _qjo, int _index);
    QJsonObject getQjo();
    int getIndex();
    //void checkDay();
    bool setUsername(QString);
    QString getUsername();
    void setPassword(QString);
    void setName(QString);
    QString getName();
    bool setEmail(QString);
    QString getEmail();
    void setLevel(int);
    int getLevel();
    void setExp(int);
    int getExp();
    void setCoin(int);
    int getCoin();
    void setTime(int);
    int getTime();
    /*Storage getStorage ();
    Silo getSilo ();
    PoultryFarm getPoultryFarm ();
    DairyFarm getDairyFarm ();
    Sheepfold getSheepfold ();
    WheatFarm getWheatFarm ();
    HayFarm getHayFarm ();
    void buy (QString str, int num);
    void sell (QString str, int num);
    ~User();*/
};

#endif // USER_H
