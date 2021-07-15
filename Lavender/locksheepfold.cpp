#include "locksheepfold.h"
#include "ui_locksheepfold.h"

LockSheepfold::LockSheepfold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LockSheepfold)
{
    ui->setupUi(this);
}

LockSheepfold::~LockSheepfold()
{
    delete ui;
}
