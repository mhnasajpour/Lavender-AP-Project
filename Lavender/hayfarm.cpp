#include "hayfarm.h"
#include "ui_hayfarm.h"

hayFarm::hayFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hayFarm)
{
    ui->setupUi(this);
}

hayFarm::~hayFarm()
{
    delete ui;
}
