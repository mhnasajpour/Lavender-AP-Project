#ifndef LOCKHAYFARM_H
#define LOCKHAYFARM_H

#include <QWidget>
#include "hayfarmbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class lockHayFarm;
}

class lockHayFarm : public QWidget
{
    Q_OBJECT

public:
    explicit lockHayFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~lockHayFarm();

private slots:
    void on_unlock_clicked();
    void on_door_clicked();
    void closeEvent(QCloseEvent *);

private:
    Ui::lockHayFarm *ui;
    HayFarmBuilding hay_farm;
    int index;
};

#endif // LOCKHAYFARM_H
