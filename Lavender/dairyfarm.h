#ifndef DAIRYFARM_H
#define DAIRYFARM_H

#include <QWidget>
#include "dairyfarmbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class DairyFarm;
}

class DairyFarm : public QWidget
{
    Q_OBJECT

public:
    explicit DairyFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~DairyFarm();

private slots:
    void on_door_clicked();
    void on_boardKey_clicked();
    void on_upgradeKey_clicked();
    void on_request_accepted();
    void on_request_rejected();
    void closeEvent(QCloseEvent *);

private:
    Ui::DairyFarm *ui;
    DairyFarmBuilding dairyFarm;
    int index;
};

#endif // DAIRYFARM_H