#include "locklands.h"
#include "ui_locklands.h"

LockLands::LockLands(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LockLands)
{
    ui->setupUi(this);
}

LockLands::~LockLands()
{
    delete ui;
}
