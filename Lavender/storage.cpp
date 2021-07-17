#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QJsonObject _qjo, int _index, QWidget *parent) : QWidget(parent),
                                                                  ui(new Ui::Storage),
                                                                  storage(_qjo),
                                                                  index(_index)
{
    ui->setupUi(this);

    if (storage.getDaysToFinishUpgrading() != 0)
    {
        ui->pushButton->setHidden(true);
        ui->textEdit->setText("انبار در حال ارتقا است\n\n" + QString::number(storage.getDaysToFinishUpgrading()) + " روز باقی مانده است");
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

    ui->level->setText(QString::number(storage.getLevelStorage()));
    ui->progressBar->setMaximum(storage.getMaxCapacityStorage());
    ui->progressBar->setValue(storage.getUsedCapacity());
    ui->eggShow->setText(QString::number(storage.getEgg()));
    ui->milkShow->setText(QString::number(storage.getMilk().size()));
    ui->woolShow->setText(QString::number(storage.getWool()));
    ui->hayShow->setText(QString::number(storage.getHay()));
    ui->shovelShow->setText(QString::number(storage.getShovel()));
    ui->nailShow->setText(QString::number(storage.getNail()));
    if (ui->progressBar->value() * 100 / ui->progressBar->maximum() > 50)
    {
        ui->progressBar->setAlignment(Qt::AlignRight);
        ui->progressBar->setAlignment(Qt::AlignVCenter);
    }
}

Storage::~Storage()
{
    delete ui;
}

void Storage::on_pushButton_clicked()
{
    ui->man->setHidden(false);
    if (storage.canUpgrade())
    {
        ui->coinReq->setText(QString::number(storage.getCoinU()));
        ui->nailReq->setText(QString::number(storage.getNailU()));
        ui->shovelReq->setText(QString::number(storage.getShoveU()));

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

void Storage::on_request_accepted()
{
    storage.startUpgrading();

    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
    ui->textEdit->setHidden(false);
    ui->textEdit->setText("انبار در حال ارتقا است\n\n" + QString::number(storage.getDaysToFinishUpgrading()) + " روز باقی مانده است");

    ui->shovelShow->setText(QString::number(storage.getShovel()));
    ui->nailShow->setText(QString::number(storage.getNail()));
    ui->progressBar->setValue(storage.getUsedCapacity());
    ui->pushButton->setHidden(true);
}

void Storage::on_request_rejected()
{
    ui->man->setHidden(true);
    ui->coinReq->setHidden(true);
    ui->nailReq->setHidden(true);
    ui->shovelReq->setHidden(true);
    ui->request->setHidden(true);
    ui->textEdit->setHidden(true);
    ui->upPic1->setHidden(true);
    ui->upPic2->setHidden(true);
    ui->upPic3->setHidden(true);
}

void Storage::on_continueKey_clicked()
{
    CourtGame *cgp = new CourtGame(storage.getQjo(), index);
    cgp->show();
    close();
}

void Storage::closeEvent(QCloseEvent *event)
{
    User tmp(storage.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}