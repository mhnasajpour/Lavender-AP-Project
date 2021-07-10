#include "silo.h"
#include "ui_silo.h"
#include "courtgame.h"

Silo::Silo(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Silo),
    silo(_qjo),
    index(_index)
{
    ui->setupUi(this);

    if(silo.getDaysToFinishUpgrading() != 0)
    {
        ui->textEdit->setText("سیلو در حال ارتقا است\n\n" + QString::number(silo.getDaysToFinishUpgrading()) + " روز باقی مانده است");
    }
    else
    {
        ui->man->setHidden(true);
        ui->coinReq->setHidden(true);
        ui->nailReq->setHidden(true);
        ui->textEdit->setHidden(true);
        ui->upPic1->setHidden(true);
        ui->upPic2->setHidden(true);
    }
    ui->request->setHidden(true);

    ui->level->setText(QString::number(silo.getLevel()));
    ui->progressBar->setMaximum(silo.getMaxCapacity());
    ui->progressBar->setValue(silo.getWheat());
    ui->wheatShow->setText(QString::number(silo.getWheat()));
}

Silo::~Silo()
{
    delete ui;
}

void Silo::on_pushButton_clicked()
{
    ui->man->setHidden(false);
    if(silo.canUpgrade())
    {
        ui->coinReq->setText(QString::number(100 * pow(silo.getLevel() * 2, 2)));
        ui->nailReq->setText(QString::number(2 * silo.getLevel()));

        ui->coinReq->setHidden(false);
        ui->nailReq->setHidden(false);
        ui->request->setHidden(false);
        ui->upPic1->setHidden(false);
        ui->upPic2->setHidden(false);
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
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("سیلو در حال ارتقا است\n\n" + QString::number(silo.getDaysToFinishUpgrading()) + " روز باقی مانده است");
}

void Silo::on_request_rejected()
{
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->man->setHidden(true);
}

void Silo::on_continueKey_clicked()
{
    CourtGame* cgp = new CourtGame(silo.getQjo(), index);
    cgp->show();
    close();
}

