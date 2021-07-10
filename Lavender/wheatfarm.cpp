#include "wheatfarm.h"
#include "ui_wheatfarm.h"

WheatFarm::WheatFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WheatFarm)
{
    ui->setupUi(this);
}

WheatFarm::~WheatFarm()
{
    delete ui;
}
