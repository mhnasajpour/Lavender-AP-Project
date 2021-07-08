#include "courtgame.h"
#include "ui_courtgame.h"
#include "login.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include "mainmenu.h"

CourtGame::CourtGame(QJsonObject qjo, int index, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame),
    user(qjo, index)
{
    ui->setupUi(this);
    ui->villageName->setText(user.getName());
    ui->level->setText(QString::number(user.getLevel()));
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

