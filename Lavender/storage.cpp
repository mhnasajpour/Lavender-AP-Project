#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
}

Storage::~Storage()
{
    delete ui;
}
