#include "poultryfarm.h"
#include "ui_poultryfarm.h"

PoultryFarm::PoultryFarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PoultryFarm)
{
    ui->setupUi(this);
}

PoultryFarm::~PoultryFarm()
{
    delete ui;
}
