#ifndef LOCKDAIRYFARM_H
#define LOCKDAIRYFARM_H

#include <QWidget>
#include "dairyfarmbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class LockDairyFarm;
}

class LockDairyFarm : public QWidget
{
    Q_OBJECT

public:
    explicit LockDairyFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~LockDairyFarm();

private slots:
    void on_unlock_clicked();
    void on_door_clicked();
    void closeEvent(QCloseEvent *);

private:
    Ui::LockDairyFarm *ui;
    DairyFarmBuilding dairyFarm;
    int index;
};

#endif // LOCKDAIRYFARM_H