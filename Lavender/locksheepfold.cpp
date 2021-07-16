#include "locksheepfold.h"
#include "ui_locksheepfold.h"

LockSheepfold::LockSheepfold(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockSheepfold),
    sheepfold(_qjo),
    index(_index)
{
    ui->setupUi(this);

    if(!sheepfold.isLevelEnough())
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label2->setHidden(true);
        ui->label->setText("آغل\nدر سطح " + QString::number(sheepfold.getMinLevelRequiredE()) + " قابل\nدسترسی می باشد");
    }
    else if(sheepfold.getDaysToFinishEstablishing() == -1 && !sheepfold.canEstablish())
    {
        ui->unlock->setHidden(true);
        ui->label->setHidden(true);
    }
    else if(sheepfold.getDaysToFinishEstablishing() > 0){
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label2->setHidden(true);
        ui->label->setText("آغل\nدر حال تاسیس است\n" + QString::number(sheepfold.getDaysToFinishEstablishing()) + " روز صبر کنید");
    }
    else
    {
        ui->label->setHidden(true);
    }
}

LockSheepfold::~LockSheepfold()
{
    delete ui;
}

void LockSheepfold::on_unlock_clicked()
{
    sheepfold.startEstablishing();
    ui->unlock->setHidden(true);
    ui->coinPic->setHidden(true);
    ui->coinShow->setHidden(true);
    ui->nailPic->setHidden(true);
    ui->nailShow->setHidden(true);
    ui->shovelPic->setHidden(true);
    ui->shovelShow->setHidden(true);
    ui->label2->setHidden(true);
    ui->label->setHidden(false);
    ui->label->setText("آغل\nدر حال تاسیس است\n" + QString::number(sheepfold.getDaysToFinishEstablishing()) + " روز صبر کنید");
}


void LockSheepfold::on_door_clicked()
{
    CourtGame *cg = new CourtGame(sheepfold.getQjo(), index);
    cg->show();
    close();
}

void LockSheepfold::closeEvent(QCloseEvent *event)
{
    User tmp(sheepfold.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
