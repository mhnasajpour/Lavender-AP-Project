#include "silo.h"
#include "ui_silo.h"

Silo::Silo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Silo)
{
    ui->setupUi(this);
}

Silo::~Silo()
{
    delete ui;
}
