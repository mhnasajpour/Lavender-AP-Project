#ifndef HAYFARM_H
#define HAYFARM_H

#include <QWidget>
#include "hayfarmbuilding.h"

namespace Ui {
class hayFarm;
}

class hayFarm : public QWidget
{
    Q_OBJECT

public:
    explicit hayFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~hayFarm();

private slots:
    void on_continueKey_clicked();

    void on_boardKey_clicked();

    void on_upgradeKey_clicked();

    void on_request_accepted();

    void on_request_rejected();

private:
    Ui::hayFarm *ui;
    HayFarmBuilding hay_farm;
    int index;
};

#endif // HAYFARM_H
