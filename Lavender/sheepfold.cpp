#include "sheepfold.h"
#include "ui_sheepfold.h"

Sheepfold::Sheepfold(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sheepfold)
{
    ui->setupUi(this);
}

Sheepfold::~Sheepfold()
{
    delete ui;
}
