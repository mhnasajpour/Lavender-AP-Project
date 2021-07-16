#include "wheatfarm.h"
#include "ui_wheatfarm.h"
#include <algorithm>
#include <courtgame.h>

WheatFarm::WheatFarm(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WheatFarm),
    wheatFarm(_qjo),
    index(_index)
{
    ui->setupUi(this);

    ui->level->setText(QString::number(wheatFarm.getLevelFarm()));
    ui->area->setText("مساحت مزرعه: " + QString::number(wheatFarm.getMaxArea()) + " هکتار");

    if(wheatFarm.getDaysToFinishUpgrading() != 0)
    {
        ui->upgradeKey->setHidden(true);
        ui->description->setHidden(true);
        ui->board->setHidden(true);
        ui->boardKey->setHidden(true);
        ui->spinBox->setHidden(true);
        ui->request->setHidden(true);
        ui->textEdit->setText("مزرعه در حال ارتقا است\n\n" + QString::number(wheatFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    }
    else
    {
        ui->man->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->request->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->shovelReq->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
    }

    if(wheatFarm.getFlag() == 1)
    {
        ui->spinBox->setMaximum(std::min(wheatFarm.getMaxArea(), wheatFarm.getWheat()));
        ui->spinBox->setValue(-1);
    }
    else if(wheatFarm.getFlag() == 2)
    {
        ui->description->setText("در حال رشد محصولات\n" + QString::number(wheatFarm.getDaysToFinishPlanting()) + " روز صبر کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("داشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
        ui->upgradeKey->setHidden(true);
    }
    else
    {
        ui->description->setText("محصولات شما (" + QString::number(wheatFarm.getPlantingArea() * 2) + " گندم)\nآماده برداشت است\nآن ها را به سیلو منتقل کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("برداشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->upgradeKey->setHidden(true);
    }
}

WheatFarm::~WheatFarm()
{
    delete ui;
}

void WheatFarm::on_boardKey_clicked()
{
    if(wheatFarm.getFlag() == 1 && ui->spinBox->value() != 0)
    {
        wheatFarm.setPlantingArea(ui->spinBox->value());
        wheatFarm.startPlanting(wheatFarm.getPlantingArea());

        ui->description->setText("در حال رشد محصولات\n" + QString::number(wheatFarm.getDaysToFinishPlanting()) + " روز صبر کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("داشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
        ui->upgradeKey->setHidden(true);
        if(!ui->man->isHidden())
        {
            ui->man->setHidden(true);
            ui->request->setHidden(true);
            ui->upPic1->setHidden(true);
            ui->upPic2->setHidden(true);
            ui->shovelReq->setHidden(true);
            ui->coinReq->setHidden(true);
            ui->textEdit->setHidden(true);
        }
    }
    else if (wheatFarm.getFlag() == 3)
    {
        if(wheatFarm.canHarvest())
        {
            wheatFarm.harvest();
            ui->spinBox->setHidden(false);
            ui->boardKey->setText("کاشت");
            ui->boardKey->setGeometry(720, 490, 80, 25);
            ui->spinBox->setMaximum(std::min(wheatFarm.getMaxArea(), wheatFarm.getWheat()));
            ui->spinBox->setValue(-1);
            ui->description->setText("زمین آماده کشت گندم است...\nمساحت زیر کشت را انتخاب کنید");
            ui->upgradeKey->setHidden(false);
        }
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n ظرفیت سیلو\n کافی نیست");
        }
    }
}

void WheatFarm::on_continueKey_clicked()
{
    CourtGame* cgp = new CourtGame(wheatFarm.getQjo(), index);
    cgp->show();
    close();
}

void WheatFarm::on_upgradeKey_clicked()
{
    ui->man->setHidden(false);
    if(wheatFarm.canUpgrade())
    {
        ui->coinReq->setText(QString::number(wheatFarm.getCoinU()));
        ui->shovelReq->setText(QString::number(wheatFarm.getShoveU()));

        ui->coinReq->setHidden(false);
        ui->shovelReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
    }
}

void WheatFarm::on_request_accepted()
{
    wheatFarm.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("مزرعه در حال ارتقا است\n\n" + QString::number(wheatFarm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    ui->upgradeKey->setHidden(true);
    ui->description->setHidden(true);
    ui->board->setHidden(true);
    ui->boardKey->setHidden(true);
    ui->spinBox->setHidden(true);
}

void WheatFarm::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
}

void WheatFarm::closeEvent(QCloseEvent *event)
{
    User tmp(wheatFarm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
