#ifndef BASEESTABLISH_H
#define BASEESTABLISH_H

#include <QFile>
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class BaseEstablish
{
protected:
    int nailE;
    int shovelE;
    int coinE;
    int timeE;
    int minLevelRequiredE;
    int addToExpE;
public:
    int getNailE();
    int getShovelE();
    int getCoinE();
    int getMinLevelRequiredE();
    virtual bool isLevelEnough() {return 0;}
    virtual void passDayToFinishEstablishing() {return;}
    virtual int getDaysToFinishEstablishing() {return 0;}
    virtual bool canEstablish() {return 0;}
    virtual void startEstablishing() {return;}
    virtual void finishEstablishing() {return;}
};

#endif // BASEESTABLISH_H
