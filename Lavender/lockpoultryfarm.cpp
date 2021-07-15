#include "lockpoultryfarm.h"
#include "ui_lockpoultryfarm.h"

LockPoultryFarm::LockPoultryFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockPoultryFarm)
{
    //ui->label->setGeometry(270, 222, 151, 271);
    ui->setupUi(this);
}

LockPoultryFarm::~LockPoultryFarm()
{
    delete ui;
}
