#ifndef POULTRYFARM_H
#define POULTRYFARM_H

#include <QWidget>
#include "poultryfarmbuilding.h"

namespace Ui {
class PoultryFarm;
}

class PoultryFarm : public QWidget
{
    Q_OBJECT

public:
    explicit PoultryFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~PoultryFarm();

private slots:
    void on_door_clicked();

    void on_boardKey_clicked();

    void on_upgradeKey_clicked();

    void on_request_accepted();

    void on_request_rejected();

private:
    Ui::PoultryFarm *ui;
    PoultryFarmBuilding poultryFarm;
    int index;
};

#endif // POULTRYFARM_H
