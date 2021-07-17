#include "silo.h"
#include "ui_silo.h"

Silo::Silo(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::Silo),
                                                            silo(_qjo),
                                                            index(_index)
{
    ui->setupUi(this);

    if (silo.getDaysToFinishUpgrading() != 0)
    {
        ui->textEdit->setText("سیلو در حال ارتقا است\n\n" + QString::number(silo.getDaysToFinishUpgrading()) + " روز باقی مانده است");
        ui->pushButton->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->shovelReq->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
        ui->upPic3->setHidden(true);
    }
    else
    {
        ui->man->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->shovelReq->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
        ui->upPic3->setHidden(true);
    }
    ui->request->setHidden(true);
    ui->level->setText(QString::number(silo.getLevelSilo()));
    ui->progressBar->setMaximum(silo.getMaxCapacitySilo());
    ui->progressBar->setValue(silo.getWheat());
    ui->wheatPic->setGeometry(silo.getWheat() * 254 / silo.getMaxCapacitySilo() + 485, 317, 26, 26);
    if (ui->wheatPic->x() > 612)
    {
        ui->progressBar->setAlignment(Qt::AlignRight);
        ui->progressBar->setAlignment(Qt::AlignVCenter);
    }
}

Silo::~Silo()
{
    delete ui;
}

void Silo::on_pushButton_clicked()
{
    ui->man->setHidden(false);
    if (silo.canUpgrade())
    {
        ui->coinReq->setText(QString::number(silo.getCoinU()));
        ui->nailReq->setText(QString::number(silo.getNailU()));
        ui->shovelReq->setText(QString::number(silo.getShoveU()));

        ui->coinReq->setHidden(false);
        ui->nailReq->setHidden(false);
        ui->shovelReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
        ui->upPic3->setHidden(false);
    }
    else
    {
        ui->textEdit->setHidden(false);
    }
}

void Silo::on_request_accepted()
{
    silo.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->pushButton->setHidden(true);
    ui->textEdit->setText("سیلو در حال ارتقا است\n\n" + QString::number(silo.getDaysToFinishUpgrading()) + " روز باقی مانده است");
}

void Silo::on_request_rejected()
{
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
    ui->man->setHidden(true);
}

void Silo::on_continueKey_clicked()
{
    CourtGame *cgp = new CourtGame(silo.getQjo(), index);
    cgp->show();
    close();
}

void Silo::closeEvent(QCloseEvent *event)
{
    User tmp(silo.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}