#ifndef LOCKPOULTRYFARM_H
#define LOCKPOULTRYFARM_H

#include <QWidget>
#include "poultryfarmbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class LockPoultryFarm;
}

class LockPoultryFarm : public QWidget
{
    Q_OBJECT

public:
    explicit LockPoultryFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~LockPoultryFarm();

private slots:
    void on_unlock_clicked();
    void on_door_clicked();
    void closeEvent(QCloseEvent *);

private:
    Ui::LockPoultryFarm *ui;
    PoultryFarmBuilding poultryFarm;
    int index;
};

#endif // LOCKPOULTRYFARM_H
