#include "silo.h"
#include "ui_silo.h"

Silo::Silo(QJsonObject _qjo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Silo)
{
    qjo = _qjo;
    ui->setupUi(this);
}

Silo::~Silo()
{
    delete ui;
}
