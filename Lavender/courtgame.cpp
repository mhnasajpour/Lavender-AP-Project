#include "courtgame.h"
#include "ui_courtgame.h"
#include "login.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include "mainmenu.h"
#include "storage.h"
#include "silo.h"
#include "wheatfarm.h"
#include "hayfarm.h"

CourtGame::CourtGame(QJsonObject qjo, int index, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame),
    user(qjo, index)
{
    ui->setupUi(this);
    ui->villageName->setText(user.getName());
    ui->level->setText(QString::number(user.getLevel()));
    ui->coinShow->setText(QString::number(user.getCoin()));
    ui->exp->setMaximum((powl(2, user.getLevel()) - 1) * 10);
    ui->exp->setValue(user.getExp());
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
    WheatFarm *wheat = new WheatFarm;
    wheat->show();
    close();
}


void CourtGame::on_hayFarm_clicked()
{
    hayFarm *hay = new hayFarm;
    hay->show();
    close();
}

