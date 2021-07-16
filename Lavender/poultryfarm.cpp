#include "poultryfarm.h"
#include "ui_poultryfarm.h"
#include "courtgame.h"

PoultryFarm::PoultryFarm(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PoultryFarm),
    poultryFarm(_qjo),
    index(_index)
{
    ui->setupUi(this);

    ui->level->setText(QString::number(poultryFarm.getLevelAnimalFarm()));
    ui->capacity->setText("ظرفیت : " + QString::number(poultryFarm.getMaxCapacityAnimalFarm()));

    if(poultryFarm.getAnimals() == 0)
    {
        ui->size->setText("هیچ مرغی موجود نمی باشد !");
        ui->boardKey->setHidden(true);
        ui->description->setText("مرغداری خالی است !\nتعدادی مرغ از\nفروشگاه خریداری کنید");
        ui->description->setGeometry(600, 510, 241, 91);
    }
    else
        ui->size->setText("تعداد مرغ ها : " + QString::number(poultryFarm.getAnimals()));

    if(poultryFarm.getDaysToFinishUpgrading() != 0)
    {
        ui->upgradeKey->setHidden(true);
        ui->description->setHidden(true);
        ui->board->setHidden(true);
        ui->boardKey->setHidden(true);
        ui->request->setHidden(true);
        ui->textEdit->setText("مرغداری در حال ارتقا است\n" + QString::number(poultryFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    }
    else
    {
        ui->man->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->request->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
    }

    if(poultryFarm.getAnimals() != 0)
    {
        if(poultryFarm.getFlag() == 1)
        {
            ui->boardKey->setText("بذر دادن");
            ui->description->setText("...مرغ ها گرسنه اند\nاز سیلو به آن ها " + QString::number(poultryFarm.getAnimals()) + " گندم بدهید");
        }
        else if(poultryFarm.getFlag() == 2)
        {
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(poultryFarm.getDaysToFinishFeeding()) + " روز دیگر تخم مرغ ها\nآماده است");
            ui->description->setGeometry(600, 510, 241, 91);
        }
        else
            ui->upgradeKey->setHidden(true);
    }
}

PoultryFarm::~PoultryFarm()
{
    delete ui;
}

void PoultryFarm::on_door_clicked()
{
    CourtGame* cgp = new CourtGame(poultryFarm.getQjo(), index);
    cgp->show();
    close();
}


void PoultryFarm::on_boardKey_clicked()
{
    if(poultryFarm.getFlag() == 1)
    {
        if(poultryFarm.canFeed())
        {
            poultryFarm.feed();
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(poultryFarm.getDaysToFinishFeeding()) + " روز دیگر تخم مرغ ها\nآماده است");
            ui->description->setGeometry(600, 510, 241, 91);
            if(!ui->man->isHidden())
            {
                ui->man->setHidden(true);
                ui->textEdit->setHidden(true);
                ui->request->setHidden(true);
                ui->coinReq->setHidden(true);
                ui->nailReq->setHidden(true);
                ui->upPic1->setHidden(true);
                ui->upPic2->setHidden(true);
            }
        }
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n     گندم بیشتری\n       نیاز است");
        }
    }
    else if(poultryFarm.getFlag() == 3)
    {
        if(poultryFarm.canCollectProduct())
        {
            poultryFarm.collectProduct();
            ui->boardKey->setText("بذر دادن");
            ui->description->setText("...مرغ ها گرسنه اند\nاز سیلو به آن ها " + QString::number(poultryFarm.getAnimals()) + " گندم بدهید");
            ui->upgradeKey->setHidden(false);
        }
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n     ظرفیت انبار\n      کافی نیست");
        }
    }
}

void PoultryFarm::on_upgradeKey_clicked()
{
    ui->man->setHidden(false);
    if(poultryFarm.canUpgrade())
    {
        ui->coinReq->setHidden(false);
        ui->nailReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
        ui->textEdit->setText("ارتقای مرغداری\nاکنون در دسترس نیست");
    }
}

void PoultryFarm::on_request_accepted()
{
    poultryFarm.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("مرغداری در حال ارتقا است\n" + QString::number(poultryFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    ui->upgradeKey->setHidden(true);
    ui->description->setHidden(true);
    ui->board->setHidden(true);
    ui->boardKey->setHidden(true);
}

void PoultryFarm::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
}

void PoultryFarm::closeEvent(QCloseEvent *event)
{
    User tmp(poultryFarm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
