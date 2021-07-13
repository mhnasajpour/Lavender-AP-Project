#include "dairyfarm.h"
#include "ui_dairyfarm.h"

DairyFarm::DairyFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DairyFarm)
{
    ui->setupUi(this);
}

DairyFarm::~DairyFarm()
{
    delete ui;
}
