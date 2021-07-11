#include "levelup.h"
#include "ui_levelup.h"
#include <QMovie>

LevelUp::LevelUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelUp)
{
    ui->setupUi(this);

    QMovie *m = new QMovie(":/LevelUp/otherPic/levelUp.gif");
    ui->label->setMovie(m);
    m->start();
    connect(m, SIGNAL(finished()), this, SLOT(close()));
}

LevelUp::~LevelUp()
{
    delete ui;
}
