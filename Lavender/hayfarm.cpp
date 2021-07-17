#include "hayfarm.h"
#include "ui_hayfarm.h"

hayFarm::hayFarm(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                  ui(new Ui::hayFarm),
                                                                  hay_farm(_qjo),
                                                                  index(_index)
{
    ui->setupUi(this);

    ui->level->setText(QString::number(hay_farm.getLevelFarm()));
    ui->area->setText("مساحت مزرعه: " + QString::number(hay_farm.getMaxArea()) + " هکتار");

    if (hay_farm.getDaysToFinishUpgrading() != 0)
    {
        ui->upgradeKey->setHidden(true);
        ui->description->setHidden(true);
        ui->board->setHidden(true);
        ui->boardKey->setHidden(true);
        ui->spinBox->setHidden(true);
        ui->request->setHidden(true);
        ui->textEdit->setText("مزرعه در حال ارتقا است\n\n" + QString::number(hay_farm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
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

    if (hay_farm.getFlag() == 1)
    {
        ui->spinBox->setMaximum(std::min(hay_farm.getMaxArea(), hay_farm.getHay()));
        ui->spinBox->setValue(-1);
    }
    else if (hay_farm.getFlag() == 2)
    {
        ui->description->setText("در حال رشد محصولات\n" + QString::number(hay_farm.getDaysToFinishPlanting()) + " روز صبر کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("داشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
        ui->upgradeKey->setHidden(true);
    }
    else if (hay_farm.getFlag() == 3)
    {
        ui->description->setText("محصولات شما (" + QString::number(hay_farm.getPlantingArea() * 2) + " یونجه)\nآماده برداشت است\nآن ها را به انبار منتقل کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("برداشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->upgradeKey->setHidden(true);
    }
    else if (hay_farm.getFlag() == 4)
    {
        ui->description->setText("قبل از کشت باید مزرعه را شخم بزنید\nشخم زدن " + QString::number(hay_farm.getMaxArea() * 5) + " سکه هزینه دارد");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("شخم زدن");
        ui->boardKey->setGeometry(770, 490, 80, 25);
    }
    else
    {
        ui->description->setText("مزرعه در حال آماده سازی\nبرای کشت است\nعملیات فردا به اتمام می رسد");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("آماده سازی");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
        ui->upgradeKey->setHidden(true);
    }
}

hayFarm::~hayFarm()
{
    delete ui;
}

void hayFarm::on_continueKey_clicked()
{
    CourtGame *cgp = new CourtGame(hay_farm.getQjo(), index);
    cgp->show();
    close();
}

void hayFarm::on_boardKey_clicked()
{
    if (hay_farm.getFlag() == 1 && ui->spinBox->value() != 0)
    {
        hay_farm.setPlantingArea(ui->spinBox->value());
        hay_farm.startPlanting(hay_farm.getPlantingArea());

        ui->description->setText("در حال رشد محصولات\n" + QString::number(hay_farm.getDaysToFinishPlanting()) + " روز صبر کنید");
        ui->spinBox->setHidden(true);
        ui->boardKey->setText("داشت");
        ui->boardKey->setGeometry(770, 490, 80, 25);
        ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
        ui->upgradeKey->setHidden(true);
        if (!ui->man->isHidden())
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
    else if (hay_farm.getFlag() == 3)
    {
        if (hay_farm.canHarvest())
        {
            hay_farm.harvest();
            ui->boardKey->setText("شخم زدن");
            ui->boardKey->setGeometry(770, 490, 80, 25);
            ui->description->setText("قبل از کشت باید مزرعه را شخم بزنید\nشخم زدن " + QString::number(hay_farm.getMaxArea() * 5) + " سکه هزینه دارد");
            ui->upgradeKey->setHidden(false);
        }
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n ظرفیت انبار\n کافی نیست");
        }
    }
    else if (hay_farm.getFlag() == 4)
    {
        if (hay_farm.canPlow())
        {
            hay_farm.startPlowing();
            ui->description->setText("مزرعه در حال آماده سازی\nبرای کشت است\nعملیات فردا به اتمام می رسد");
            ui->spinBox->setHidden(true);
            ui->boardKey->setText("آماده سازی");
            ui->boardKey->setGeometry(770, 490, 80, 25);
            ui->boardKey->setCursor(QCursor(Qt::ArrowCursor));
            ui->upgradeKey->setHidden(true);
            if (!ui->man->isHidden())
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
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n سکه بیشتری\n نیاز است");
        }
    }
}

void hayFarm::on_upgradeKey_clicked()
{
    ui->man->setHidden(false);
    if (hay_farm.canUpgrade())
    {
        ui->coinReq->setText(QString::number(hay_farm.getCoinU()));
        ui->shovelReq->setText(QString::number(hay_farm.getShoveU()));

        ui->coinReq->setHidden(false);
        ui->shovelReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
        ui->textEdit->setText("ارتقای مزرعه اکنون در دسترس نیست");
    }
}

void hayFarm::on_request_accepted()
{
    hay_farm.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("مزرعه در حال ارتقا است\n\n" + QString::number(hay_farm.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    ui->upgradeKey->setHidden(true);
    ui->description->setHidden(true);
    ui->board->setHidden(true);
    ui->boardKey->setHidden(true);
    ui->spinBox->setHidden(true);
}

void hayFarm::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
}

void hayFarm::closeEvent(QCloseEvent *event)
{
    User tmp(hay_farm.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}