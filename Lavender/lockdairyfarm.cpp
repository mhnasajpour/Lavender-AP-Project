#include "lockdairyfarm.h"
#include "ui_lockdairyfarm.h"

LockDairyFarm::LockDairyFarm(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                              ui(new Ui::LockDairyFarm),
                                                                              dairyFarm(_qjo),
                                                                              index(_index)
{
    ui->setupUi(this);

    if (!dairyFarm.isLevelEnough())
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label2->setHidden(true);
        ui->label->setText("گاوداری\nدر سطح " + QString::number(dairyFarm.getMinLevelRequiredE()) + " قابل\nدسترسی می باشد");
    }
    else if (dairyFarm.getDaysToFinishEstablishing() == -1 && !dairyFarm.canEstablish())
    {
        ui->unlock->setHidden(true);
        ui->label->setHidden(true);
    }
    else if (dairyFarm.getDaysToFinishEstablishing() > 0)
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label2->setHidden(true);
        ui->label->setText("گاوداری\nدر حال تاسیس است\n" + QString::number(dairyFarm.getDaysToFinishEstablishing()) + " روز صبر کنید");
    }
    else
    {
        ui->label->setHidden(true);
    }
}

LockDairyFarm::~LockDairyFarm()
{
    delete ui;
}

void LockDairyFarm::on_unlock_clicked()
{
    dairyFarm.startEstablishing();
    ui->unlock->setHidden(true);
    ui->coinPic->setHidden(true);
    ui->coinShow->setHidden(true);
    ui->nailPic->setHidden(true);
    ui->nailShow->setHidden(true);
    ui->shovelPic->setHidden(true);
    ui->shovelShow->setHidden(true);
    ui->label2->setHidden(true);
    ui->label->setHidden(false);
    ui->label->setText("گاوداری\nدر حال تاسیس است\n" + QString::number(dairyFarm.getDaysToFinishEstablishing()) + " روز صبر کنید");
}

void LockDairyFarm::on_door_clicked()
{
    CourtGame *cg = new CourtGame(dairyFarm.getQjo(), index);
    cg->show();
    close();
}

void LockDairyFarm::closeEvent(QCloseEvent *event)
{
    User tmp(dairyFarm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
