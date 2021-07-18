#include "courtgame.h"
#include "ui_courtgame.h"

CourtGame::CourtGame(QJsonObject qjo, int index, QWidget *parent) : QMainWindow(parent),
                                                                    ui(new Ui::CourtGame),
                                                                    user(qjo, index)
{
    ui->setupUi(this);
    ui->villageName->setText(user.getName());
    ui->level->setText(QString::number(user.getLevelPlayer()));
    ui->coinShow->setText(QString::number(user.getCoin()));
    ui->exp->setMaximum((powl(2, user.getLevelPlayer()) - 1) * 10);
    ui->exp->setValue(user.getExp());

    if (user.getWheatFarm().getFlag() == 1)
        ui->wheatFarm->setIcon(QIcon(":/wheatLand/lands/1.png"));
    else if (user.getWheatFarm().getFlag() == 2 && user.getWheatFarm().getDaysToFinishPlanting() == 2)
        ui->wheatFarm->setIcon(QIcon(":/wheatLand/lands/2.png"));
    else if (user.getWheatFarm().getFlag() == 2 && user.getWheatFarm().getDaysToFinishPlanting() == 1)
        ui->wheatFarm->setIcon(QIcon(":/wheatLand/lands/3.png"));
    else if (user.getWheatFarm().getFlag() == 3)
        ui->wheatFarm->setIcon(QIcon(":/wheatLand/lands/4.png"));

    if (user.getHayFarm().getFlag() == 4)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay1.png"));
    else if (user.getHayFarm().getFlag() == 5)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay1.png"));
    else if (user.getHayFarm().getFlag() == 1)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay2.png"));
    else if (user.getHayFarm().getFlag() == 2 && user.getHayFarm().getDaysToFinishPlanting() == 5)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay3.png"));
    else if (user.getHayFarm().getFlag() == 2 && user.getHayFarm().getDaysToFinishPlanting() == 4)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay4.png"));
    else if (user.getHayFarm().getFlag() == 2 && user.getHayFarm().getDaysToFinishPlanting() == 3)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay5.png"));
    else if (user.getHayFarm().getFlag() == 2 && user.getHayFarm().getDaysToFinishPlanting() == 2)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay6.png"));
    else if (user.getHayFarm().getFlag() == 2 && user.getHayFarm().getDaysToFinishPlanting() == 1)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay7.png"));
    else if (user.getHayFarm().getFlag() == 3)
        ui->hayFarm->setIcon(QIcon(":/hayLand/lands/hay8.png"));

    if (user.getHayFarm().getLevelFarm() > 0)
        ui->lockHayFarm->setHidden(true);
    if (user.getPoultryFarm().getLevelAnimalFarm() > 0)
        ui->lockPoultryFarm->setHidden(true);
    if (user.getDairyFarm().getLevelAnimalFarm() > 0)
        ui->lockDairyFarm->setHidden(true);
    if (user.getSheepfold().getLevelAnimalFarm() > 0)
        ui->lockSheepfold->setHidden(true);
    if (user.getLevelPlayer() > 1)
        ui->lockShop->setHidden(true);
}

CourtGame::~CourtGame()
{
    delete ui;
}

void CourtGame::on_level_clicked()
{
    mainMenu *level = new mainMenu(user);
    level->show();
    close();
}

void CourtGame::on_storage_clicked()
{
    Storage *st = new Storage(user.getQjo(), user.getIndex());
    st->show();
    close();
}

void CourtGame::on_silo_clicked()
{
    Silo *si = new Silo(user.getQjo(), user.getIndex());
    si->show();
    close();
}

void CourtGame::on_wheatFarm_clicked()
{
    WheatFarm *wheat = new WheatFarm(user.getQjo(), user.getIndex());
    wheat->show();
    close();
}

void CourtGame::on_hayFarm_clicked()
{
    if (user.getHayFarm().getLevelFarm() == 0)
        on_lockHayFarm_clicked();
    else
    {
        hayFarm *hay = new hayFarm(user.getQjo(), user.getIndex());
        hay->show();
        close();
    }
}

void CourtGame::on_lockHayFarm_clicked()
{
    lockHayFarm *llp = new lockHayFarm(user.getQjo(), user.getIndex());
    llp->show();
    close();
}

void CourtGame::on_poultryFarm_clicked()
{
    if (user.getPoultryFarm().getLevelAnimalFarm() == 0)
        on_lockPoultryFarm_clicked();
    else
    {
        PoultryFarm *p = new PoultryFarm(user.getQjo(), user.getIndex());
        p->show();
        close();
    }
}

void CourtGame::on_lockPoultryFarm_clicked()
{
    LockPoultryFarm *lpf = new LockPoultryFarm(user.getQjo(), user.getIndex());
    lpf->show();
    close();
}

void CourtGame::on_dairyFarm_clicked()
{
    if (user.getDairyFarm().getLevelAnimalFarm() == 0)
        on_lockDairyFarm_clicked();
    else
    {
        DairyFarm *df = new DairyFarm(user.getQjo(), user.getIndex());
        df->show();
        close();
    }
}

void CourtGame::on_lockDairyFarm_clicked()
{
    LockDairyFarm *ldf = new LockDairyFarm(user.getQjo(), user.getIndex());
    ldf->show();
    close();
}

void CourtGame::on_sheepfold_clicked()
{
    if (user.getSheepfold().getLevelAnimalFarm() == 0)
        on_lockSheepfold_clicked();
    else
    {
        Sheepfold *sp = new Sheepfold(user.getQjo(), user.getIndex());
        sp->show();
        close();
    }
}

void CourtGame::on_lockSheepfold_clicked()
{
    LockSheepfold *lsp = new LockSheepfold(user.getQjo(), user.getIndex());
    lsp->show();
    close();
}

void CourtGame::on_shop_clicked()
{
    if (user.getLevelPlayer() > 1)
    {
        Shop *sh = new Shop(user.getQjo(), user.getIndex());
        sh->show();
        close();
    }
}

void CourtGame::closeEvent(QCloseEvent *event)
{
    user.saveToFile();
    event->accept();
}
