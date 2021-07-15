#include "lockdairyfarm.h"
#include "ui_lockdairyfarm.h"

LockDairyFarm::LockDairyFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockDairyFarm)
{
    ui->setupUi(this);
}

LockDairyFarm::~LockDairyFarm()
{
    delete ui;
}
