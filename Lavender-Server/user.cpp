#include "user.h"
#include "ui_user.h"

User::User(QByteArray text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    ui->textEdit->setText(text);
}

User::~User()
{
    delete ui;
}
