#include "dairyfarm.h"
#include "ui_dairyfarm.h"

DairyFarm::DairyFarm(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                      ui(new Ui::DairyFarm),
                                                                      dairyFarm(_qjo),
                                                                      index(_index)
{
    ui->setupUi(this);

    ui->level->setText(QString::number(dairyFarm.getLevelAnimalFarm()));
    ui->capacity->setText("ظرفیت : " + QString::number(dairyFarm.getMaxCapacityAnimalFarm()));

    if (dairyFarm.getAnimals() == 0)
    {
        ui->size->setText("هیچ گاوی موجود نمی باشد !");
        ui->boardKey->setHidden(true);
        ui->description->setText("گاوداری خالی است !\nتعدادی گاو از\nفروشگاه خریداری کنید");
        ui->description->setGeometry(590, 515, 241, 91);
    }
    else
        ui->size->setText("تعداد گاو ها : " + QString::number(dairyFarm.getAnimals()));

    if (dairyFarm.getDaysToFinishUpgrading() != 0)
    {
        ui->upgradeKey->setHidden(true);
        ui->description->setHidden(true);
        ui->board->setHidden(true);
        ui->boardKey->setHidden(true);
        ui->request->setHidden(true);
        ui->textEdit->setText("گاوداری در حال ارتقا است\n" + QString::number(dairyFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
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

    if (dairyFarm.getAnimals() != 0)
    {
        if (dairyFarm.getFlag() == 1)
        {
            ui->boardKey->setText("غذا دادن");
            ui->description->setText("...گاو ها گرسنه اند\nاز انبار به آن ها " + QString::number(2 * dairyFarm.getAnimals()) + " یونجه بدهید");
        }
        else if (dairyFarm.getFlag() == 2)
        {
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(dairyFarm.getDaysToFinishFeeding()) + " روز دیگر شیر ها\nآماده است");
            ui->description->setGeometry(590, 515, 241, 91);
        }
        else
            ui->upgradeKey->setHidden(true);
    }
}

DairyFarm::~DairyFarm()
{
    delete ui;
}

void DairyFarm::on_door_clicked()
{
    CourtGame *cgp = new CourtGame(dairyFarm.getQjo(), index);
    cgp->show();
    close();
}

void DairyFarm::on_boardKey_clicked()
{
    if (dairyFarm.getFlag() == 1)
    {
        if (dairyFarm.canFeed())
        {
            dairyFarm.feed();
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(dairyFarm.getDaysToFinishFeeding()) + " روز دیگر شیر ها\nآماده است");
            ui->description->setGeometry(590, 515, 241, 91);
            if (!ui->man->isHidden())
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
            ui->textEdit->setText("\n     یونجه بیشتری\n       نیاز است");
        }
    }
    else if (dairyFarm.getFlag() == 3)
    {
        if (dairyFarm.canCollectProduct())
        {
            dairyFarm.collectProduct();
            ui->boardKey->setText("غذا دادن");
            ui->description->setText("...گاو ها گرسنه اند\nاز انبار به آن ها " + QString::number(2 * dairyFarm.getAnimals()) + " یونجه بدهید");
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

void DairyFarm::on_upgradeKey_clicked()
{
    ui->man->setHidden(false);
    if (dairyFarm.canUpgrade())
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
        ui->textEdit->setText("ارتقای گاوداری\nاکنون در دسترس نیست");
    }
}

void DairyFarm::on_request_accepted()
{
    dairyFarm.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("گاوداری در حال ارتقا است\n" + QString::number(dairyFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    ui->upgradeKey->setHidden(true);
    ui->description->setHidden(true);
    ui->board->setHidden(true);
    ui->boardKey->setHidden(true);
}

void DairyFarm::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
}

/*void DairyFarm::closeEvent(QCloseEvent *event)
{
    User tmp(dairyFarm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}*/
