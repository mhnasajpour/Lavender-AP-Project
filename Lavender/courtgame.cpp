#include "courtgame.h"
#include "ui_courtgame.h"
#include "login.h"

CourtGame::CourtGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame)
{
    ui->setupUi(this);
}

CourtGame::~CourtGame()
{
    delete ui;
}

