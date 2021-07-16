#ifndef WHEATFARM_H
#define WHEATFARM_H

#include <QWidget>
#include "wheatfarmbuilding.h"
#include "user.h"
#include <QJsonObject>

namespace Ui {
class WheatFarm;
}

class WheatFarm : public QWidget
{
    Q_OBJECT

public:
    explicit WheatFarm(QJsonObject, int, QWidget *parent = nullptr);
    ~WheatFarm();

private slots:
    void on_boardKey_clicked();
    void on_continueKey_clicked();
    void on_upgradeKey_clicked();
    void on_request_accepted();
    void on_request_rejected();
    void closeEvent(QCloseEvent*);

private:
    Ui::WheatFarm *ui;
    WheatFarmBuilding wheatFarm;
    int index;
};

#endif // WHEATFARM_H
