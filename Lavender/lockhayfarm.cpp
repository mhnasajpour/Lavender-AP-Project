#include "lockhayfarm.h"
#include "ui_lockhayfarm.h"

lockHayFarm::lockHayFarm(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                          ui(new Ui::lockHayFarm),
                                                                          hay_farm(_qjo),
                                                                          index(_index)
{
    ui->setupUi(this);
    if (!hay_farm.isLevelEnough())
    {
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label->setGeometry(350, 270, 321, 181);
        ui->label->setText("مزرعه یونجه\nدر سطح " + QString::number(hay_farm.getMinLevelRequiredE()) + "\nقابل دسترسی می باشد");
    }
    else if (hay_farm.getDaysToFinishEstablishing() == -1 && !hay_farm.canEstablish())
        ui->unlock->setHidden(true);

    else if (hay_farm.getDaysToFinishEstablishing() > 0)
    {
        ui->pic->setPixmap(QPixmap(":/product/otherPic/product/unlockHay2.jpg"));
        ui->unlock->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label->setGeometry(350, 270, 321, 181);
        ui->label->setText("مزرعه یونجه\nدر حال تاسیس میباشد\n" + QString::number(hay_farm.getDaysToFinishEstablishing()) + " روز صبر کنید");
    }
}

lockHayFarm::~lockHayFarm()
{
    delete ui;
}

void lockHayFarm::on_unlock_clicked()
{
    ui->pic->setPixmap(QPixmap(":/product/otherPic/product/unlockHay2.jpg"));
    hay_farm.startEstablishing();
    ui->unlock->setHidden(true);
    ui->coinPic->setHidden(true);
    ui->coinShow->setHidden(true);
    ui->nailPic->setHidden(true);
    ui->nailShow->setHidden(true);
    ui->shovelPic->setHidden(true);
    ui->shovelShow->setHidden(true);
    ui->label->setGeometry(350, 270, 321, 181);
    ui->label->setText("مزرعه یونجه\nدر حال تاسیس میباشد\n" + QString::number(hay_farm.getDaysToFinishEstablishing()) + " روز صبر کنید");
}

void lockHayFarm::on_door_clicked()
{
    CourtGame *cg = new CourtGame(hay_farm.getQjo(), index);
    cg->show();
    close();
}

void lockHayFarm::closeEvent(QCloseEvent *event)
{
    User tmp(hay_farm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
