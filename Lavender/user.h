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
    //void checkLevel();
    bool setUsername(QString);
    QString getUsername();
    void setPassword(QString);
    void setName(QString);
    QString getName();
    bool setEmail(QString);
    QString getEmail();
    int getLevel();
    void setExp(int);
    int getExp();
    void changeCoin(int);
    int getCoin();
    void nextDay();
    int getDay();
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
    void saveToFile();
};

#endif // USER_H
