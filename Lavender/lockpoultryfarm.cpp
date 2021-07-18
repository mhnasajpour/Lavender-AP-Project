#include "lockpoultryfarm.h"
#include "ui_lockpoultryfarm.h"

LockPoultryFarm::LockPoultryFarm(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                                  ui(new Ui::LockPoultryFarm),
                                                                                  poultryFarm(_qjo),
                                                                                  index(_index)
{
    ui->setupUi(this);

    if (!poultryFarm.isLevelEnough())
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->label->setGeometry(267, 222, 151, 271);
        ui->label->setText("مرغداری\nدر سطح " + QString::number(poultryFarm.getMinLevelRequiredE()) + "\nقابل دسترسی\nمی باشد");
    }
    else if (poultryFarm.getDaysToFinishEstablishing() == -1 && !poultryFarm.canEstablish())
        ui->unlock->setHidden(true);

    else if (poultryFarm.getDaysToFinishEstablishing() > 0)
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->label->setGeometry(267, 222, 151, 271);
        ui->label->setText("مرغداری در حال\nتاسیس میباشد\n" + QString::number(poultryFarm.getDaysToFinishEstablishing()) + " روز صبر کنید");
    }
}

LockPoultryFarm::~LockPoultryFarm()
{
    delete ui;
}

void LockPoultryFarm::on_unlock_clicked()
{
    poultryFarm.startEstablishing();
    ui->unlock->setHidden(true);
    ui->coinPic->setHidden(true);
    ui->coinShow->setHidden(true);
    ui->nailPic->setHidden(true);
    ui->nailShow->setHidden(true);
    ui->label->setGeometry(267, 222, 151, 271);
    ui->label->setText("مرغداری در حال\nتاسیس میباشد\n" + QString::number(poultryFarm.getDaysToFinishEstablishing()) + " روز صبر کنید");
}

void LockPoultryFarm::on_door_clicked()
{
    CourtGame *cg = new CourtGame(poultryFarm.getQjo(), index);
    cg->show();
    close();
}

void LockPoultryFarm::closeEvent(QCloseEvent *event)
{
    User tmp(poultryFarm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
