#include "courtgame.h"
#include "ui_courtgame.h"
#include "login.h"

CourtGame::CourtGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame)
{
    ui->setupUi(this);
    ui->progressBar->setStyleSheet("background-color: rgb(255, 0, 0)");
}

CourtGame::~CourtGame()
{
    delete ui;
}

