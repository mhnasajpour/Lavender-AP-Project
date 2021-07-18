#include "sheepfold.h"
#include "ui_sheepfold.h"

Sheepfold::Sheepfold(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                      ui(new Ui::Sheepfold),
                                                                      sheepfold(_qjo),
                                                                      index(_index)
{
    ui->setupUi(this);

    ui->level->setText(QString::number(sheepfold.getLevelAnimalFarm()));
    ui->capacity->setText("ظرفیت : " + QString::number(sheepfold.getMaxCapacityAnimalFarm()));

    if (sheepfold.getAnimals() == 0)
    {
        ui->size->setText("گوسفندی موجود نیست !");
        ui->boardKey->setHidden(true);
        ui->description->setText("آغل خالی است !\nتعدادی گوسفند از\nفروشگاه خریداری کنید");
        ui->description->setGeometry(90, 500, 241, 91);
    }
    else
        ui->size->setText("تعداد گوسفند ها : " + QString::number(sheepfold.getAnimals()));

    if (sheepfold.getDaysToFinishUpgrading() != 0)
    {
        ui->upgradeKey->setHidden(true);
        ui->description->setHidden(true);
        ui->board->setHidden(true);
        ui->boardKey->setHidden(true);
        ui->request->setHidden(true);
        ui->textEdit->setText("آغل در حال ارتقا است\n" + QString::number(sheepfold.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    }
    else
    {
        ui->man->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->request->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->shovelReq->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
        ui->upPic3->setHidden(true);
    }

    if (sheepfold.getAnimals() != 0)
    {
        if (sheepfold.getFlag() == 1)
        {
            ui->boardKey->setText("غذا دادن");
            ui->description->setText("...گوسفند ها گرسنه اند\nاز انبار به آن ها " + QString::number(sheepfold.getAnimals()) + " یونجه بدهید");
        }
        else if (sheepfold.getFlag() == 2)
        {
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(sheepfold.getDaysToFinishFeeding()) + " روز دیگر پشم ها\nآماده است");
            ui->description->setGeometry(90, 500, 241, 91);
        }
        else
            ui->upgradeKey->setHidden(true);
    }
}

Sheepfold::~Sheepfold()
{
    delete ui;
}

void Sheepfold::on_door_clicked()
{
    CourtGame *cgp = new CourtGame(sheepfold.getQjo(), index);
    cgp->show();
    close();
}

void Sheepfold::on_boardKey_clicked()
{
    if (sheepfold.getFlag() == 1)
    {
        if (sheepfold.canFeed())
        {
            sheepfold.feed();
            ui->upgradeKey->setHidden(true);
            ui->boardKey->setHidden(true);
            ui->description->setText("...اندکی صبر کنید\n" + QString::number(sheepfold.getDaysToFinishFeeding()) + " روز دیگر پشم ها\nآماده است");
            ui->description->setGeometry(90, 500, 241, 91);
            if (!ui->man->isHidden())
            {
                ui->man->setHidden(true);
                ui->textEdit->setHidden(true);
                ui->request->setHidden(true);
                ui->coinReq->setHidden(true);
                ui->nailReq->setHidden(true);
                ui->shovelReq->setHidden(true);
                ui->upPic1->setHidden(true);
                ui->upPic2->setHidden(true);
                ui->upPic3->setHidden(true);
            }
        }
        else
        {
            ui->man->setHidden(false);
            ui->textEdit->setHidden(false);
            ui->textEdit->setText("\n     یونجه بیشتری\n       نیاز است");
        }
    }
    else if (sheepfold.getFlag() == 3)
    {
        if (sheepfold.canCollectProduct())
        {
            sheepfold.collectProduct();
            ui->boardKey->setText("غذا دادن");
            ui->description->setText("...گوسفند ها گرسنه اند\nاز انبار به آن ها " + QString::number(sheepfold.getAnimals()) + " یونجه بدهید");
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

void Sheepfold::on_upgradeKey_clicked()
{
    ui->man->setHidden(false);
    if (sheepfold.canUpgrade())
    {
        ui->coinReq->setHidden(false);
        ui->nailReq->setHidden(false);
        ui->request->setHidden(false);
        ui->shovelReq->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
        ui->upPic3->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
        ui->textEdit->setText("ارتقای آغل\nاکنون در دسترس نیست");
    }
}

void Sheepfold::on_request_accepted()
{
    sheepfold.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("آغل در حال ارتقا است\n" + QString::number(sheepfold.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    ui->upgradeKey->setHidden(true);
    ui->description->setHidden(true);
    ui->board->setHidden(true);
    ui->boardKey->setHidden(true);
}

void Sheepfold::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
}

/*void Sheepfold::closeEvent(QCloseEvent *event)
{
    User tmp(sheepfold.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}*/
