#include "locklands.h"
#include "ui_locklands.h"

LockLands::LockLands(BaseEstablish& _bte, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LockLands),
    bte(_bte)
{
    ui->setupUi(this);
    if(!bte.isLevelEnough())
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
        ui->label->setText("این ساختمان\nدر سطح " + QString::number(bte.getMinLevelRequiredE()) + "\nقابل دسترسی می باشد");
    }
    else
    {
        if(bte.getDaysToFinishEstablishing() == -1)
        {
            ui->coinShow->setText(QString::number(bte.getCoinE()));
            ui->nailShow->setText(QString::number(bte.getNailE()));
            ui->shovelShow->setText(QString::number(bte.getShovelE()));
            if(!bte.canEstablish())
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
            ui->label->setText("این ساختمان در حال تاسیس میباشد\n" + QString::number(bte.getDaysToFinishEstablishing()) + " روز صبر کنید");
        }
    }
}

LockLands::~LockLands()
{
    delete ui;
}

void LockLands::on_unlock_clicked()
{
    bte.startEstablishing();
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
    ui->label->setText("این ساختمان در حال تاسیس میباشد\n" + QString::number(bte.getDaysToFinishEstablishing()) + " روز صبر کنید");
}
