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
    virtual bool isLevelEnough() = 0;
    virtual void passDayToFinishEstablishing() = 0;
    virtual int getDaysToFinishEstablishing() = 0;
    virtual bool canEstablish() = 0;
    virtual void startEstablishing() = 0;
    virtual void finishEstablishing() = 0;
};

#endif // BASEESTABLISH_H