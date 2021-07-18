#ifndef COURTGAME_H
#define COURTGAME_H

#include <QMainWindow>
#include <QCloseEvent>
#include <user.h>
#include "login.h"
#include "mainmenu.h"
#include "storage.h"
#include "silo.h"
#include "wheatfarm.h"
#include "hayfarm.h"
#include "poultryfarm.h"
#include "dairyfarm.h"
#include "sheepfold.h"
#include "shop.h"
#include "lockhayfarm.h"
#include "lockpoultryfarm.h"
#include "lockdairyfarm.h"
#include "locksheepfold.h"

namespace Ui
{
    class CourtGame;
}

class CourtGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourtGame(QJsonObject qjo, int index, QWidget *parent = nullptr);
    ~CourtGame();

private slots:
    void on_level_clicked();
    void on_storage_clicked();
    void on_silo_clicked();
    void on_wheatFarm_clicked();
    void on_hayFarm_clicked();
    void on_lockHayFarm_clicked();
    void on_poultryFarm_clicked();
    void on_lockPoultryFarm_clicked();
    void on_dairyFarm_clicked();
    void on_lockDairyFarm_clicked();
    void on_sheepfold_clicked();
    void on_lockSheepfold_clicked();
    void on_shop_clicked();
    //void closeEvent(QCloseEvent *);

private:
    Ui::CourtGame *ui;
    User user;
};

#endif // COURTGAME_H
