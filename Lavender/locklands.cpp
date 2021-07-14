#include "locklands.h"
#include "ui_locklands.h"
#include "courtgame.h"

LockLands::LockLands(QJsonObject _qjo, int _index, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LockLands),
    hay_farm(_qjo),
    index(_index)
{
    ui->setupUi(this);
    if(!hay_farm.isLevelEnough())
    {
        ui->unlock->setHidden(true);
        ui->coin->setHidden(true);
        ui->coinPic->setHidden(true);
        ui->coinShow->setHidden(true);
        ui->nail->setHidden(true);
        ui->nailPic->setHidden(true);
        ui->nailShow->setHidden(true);
        ui->shovel->setHidden(true);
        ui->shovelPic->setHidden(true);
        ui->shovelShow->setHidden(true);
        ui->label->setGeometry(50, 80, 371, 191);
        ui->label->setText("این ساختمان\nدر سطح " + QString::number(hay_farm.getMinLevelRequiredE()) + "\nقابل دسترسی می باشد");
    }
    else
    {
        if(hay_farm.getDaysToFinishEstablishing() == -1)
        {
            ui->coinShow->setText(QString::number(hay_farm.getCoinE()));
            ui->nailShow->setText(QString::number(hay_farm.getNailE()));
            ui->shovelShow->setText(QString::number(hay_farm.getShovelE()));
            if(!hay_farm.canEstablish())
                ui->unlock->setHidden(true);
        }
        else
        {
            ui->unlock->setHidden(true);
            ui->coin->setHidden(true);
            ui->coinPic->setHidden(true);
            ui->coinShow->setHidden(true);
            ui->nail->setHidden(true);
            ui->nailPic->setHidden(true);
            ui->nailShow->setHidden(true);
            ui->shovel->setHidden(true);
            ui->shovelPic->setHidden(true);
            ui->shovelShow->setHidden(true);
            ui->label->setGeometry(50, 80, 371, 191);
            ui->label->setText("این ساختمان در حال تاسیس میباشد\n" + QString::number(hay_farm.getDaysToFinishEstablishing()) + " روز صبر کنید");
        }
    }
}

LockLands::~LockLands()
{
    delete ui;
}

void LockLands::on_unlock_clicked()
{
    hay_farm.startEstablishing();
    ui->unlock->setHidden(true);
    ui->coin->setHidden(true);
    ui->coinPic->setHidden(true);
    ui->coinShow->setHidden(true);
    ui->nail->setHidden(true);
    ui->nailPic->setHidden(true);
    ui->nailShow->setHidden(true);
    ui->shovel->setHidden(true);
    ui->shovelPic->setHidden(true);
    ui->shovelShow->setHidden(true);
    ui->label->setGeometry(50, 80, 371, 191);
    ui->label->setText("این ساختمان در حال تاسیس میباشد\n" + QString::number(hay_farm.getDaysToFinishEstablishing()) + " روز صبر کنید");
}
