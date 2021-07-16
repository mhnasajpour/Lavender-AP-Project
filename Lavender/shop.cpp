#include "shop.h"
#include "ui_shop.h"

Shop::Shop(QJsonObject _qjo, int _index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shop),
    shop(_qjo),
    index(_index),
    category(0)
{
    ui->setupUi(this);

    setHiddenPack(true, 1);
    setHiddenPack(true, 2);
    setHiddenPack(true, 3);
    ui->coinShow->setText(QString::number(shop.getCoin()));
}

Shop::~Shop()
{
    delete ui;
}

void Shop::setHiddenPack(bool flag, int pack)
{
    switch (pack)
    {
    case 1:
        ui->label1->setHidden(flag);
        ui->pic1->setHidden(flag);
        ui->buy1->setHidden(flag);
        ui->sell1->setHidden(flag);
        break;
    case 2:
        ui->label2->setHidden(flag);
        ui->pic2->setHidden(flag);
        ui->buy2->setHidden(flag);
        ui->sell2->setHidden(flag);
        break;
    case 3:
        ui->label3->setHidden(flag);
        ui->pic3->setHidden(flag);
        ui->buy3->setHidden(flag);
        ui->sell3->setHidden(flag);
        break;
    }
}

void Shop::switchPack(int pack, QString lable, QString url, int buy, int sell)
{
    ui->label->setHidden(true);
    QString x = "          ";
    switch (pack)
    {
    case 1:
        ui->label1->setText(lable);
        ui->pic1->setPixmap(QPixmap(url));
        buy ? ui->buy1->setHidden(false), ui->buy1->setText("- " + QString::number(buy) + x) : ui->buy1->setHidden(true);
        ui->sell1->setText("+ " + QString::number(sell) + x);
        break;
    case 2:
        ui->label2->setText(lable);
        ui->pic2->setPixmap(QPixmap(url));
        buy ? ui->buy2->setHidden(false), ui->buy2->setText("- " + QString::number(buy) + x) : ui->buy2->setHidden(true);
        ui->sell2->setText("+ " + QString::number(sell) + x);
        break;
    case 3:
        ui->label3->setText(lable);
        ui->pic3->setPixmap(QPixmap(url));
        buy ? ui->buy3->setHidden(false), ui->buy3->setText("- " + QString::number(buy) + x) : ui->buy3->setHidden(true);
        ui->sell3->setText("+ " + QString::number(sell) + x);
        break;
    }
}

void Shop::setError(int flag)
{
    switch (flag)
    {
    case 0:
        ui->lineEdit->setText("عملیات با موفقیت انجام شد");
        break;
    case 1:
        ui->lineEdit->setText("در این سطح قابل دسترسی نیست");
        break;
    case 2:
        ui->lineEdit->setText("سکه کافی برای خرید محصول ندارید");
        break;
    case 3:
        ui->lineEdit->setText("ظرفیت کافی برای ذخیره محصول وجود ندارد");
        break;
    case 4:
        ui->lineEdit->setText("محصولی برای فروش وجود ندارد");
        break;
    }
    ui->coinShow->setText(QString::number(shop.getCoin()));
}

void Shop::on_door_clicked()
{
    CourtGame* cgp = new CourtGame(shop.getQjo(), index);
    cgp->show();
    close();
}


void Shop::on_product1_clicked()
{
    setHiddenPack(false, 1);
    setHiddenPack(false, 2);
    setHiddenPack(true, 3);
    category = 1;

    switchPack(1, "گندم", ":/shop/otherPic/shop/wheat.png", 3, 2);
    switchPack(2, "یونجه", ":/shop/otherPic/shop/hay.png", 6, 4);

    ui->label1->setGeometry(375, 40, 151, 101);
    ui->label2->setGeometry(710, 40, 151, 101);
    ui->pic1->setGeometry(310, 90, 281, 411);
    ui->pic2->setGeometry(665, 210, 241, 181);
    ui->buy1->setGeometry(390, 500, 121, 35);
    ui->sell1->setGeometry(390, 545, 121, 35);
    ui->buy2->setGeometry(725, 500, 121, 35);
    ui->sell2->setGeometry(725, 545, 121, 35);
}


void Shop::on_product2_clicked()
{
    setHiddenPack(false, 1);
    setHiddenPack(false, 2);
    setHiddenPack(false, 3);
    category = 2;

    switchPack(1, "تخم مرغ", ":/shop/otherPic/shop/egg.png", 0, 8);
    switchPack(2, "شیر", ":/shop/otherPic/shop/milk.png", 0, 12);
    switchPack(3, "پشم", ":/shop/otherPic/shop/wool.png", 0, 23);

    ui->label1->setGeometry(300, 40, 151, 101);
    ui->label2->setGeometry(540, 40, 151, 101);
    ui->label3->setGeometry(780, 40, 151, 101);
    ui->pic1->setGeometry(280, 190, 191, 251);
    ui->pic2->setGeometry(495, 170, 241, 271);
    ui->pic3->setGeometry(740, 210, 231, 221);
    ui->sell1->setGeometry(315, 500, 121, 35);
    ui->sell2->setGeometry(555, 500, 121, 35);
    ui->sell3->setGeometry(795, 500, 121, 35);
}


void Shop::on_product3_clicked()
{
    setHiddenPack(false, 1);
    setHiddenPack(false, 2);
    setHiddenPack(false, 3);
    category = 3;

    switchPack(1, "مرغ", ":/shop/otherPic/shop/poultry.png", 20, 15);
    switchPack(2, "گاو", ":/shop/otherPic/shop/cow.png", 70, 50);
    switchPack(3, "گوسفند", ":/shop/otherPic/shop/sheep.png", 80, 70);

    ui->label1->setGeometry(300, 40, 151, 101);
    ui->label2->setGeometry(540, 40, 151, 101);
    ui->label3->setGeometry(780, 40, 151, 101);
    ui->pic1->setGeometry(280, 190, 191, 251);
    ui->pic2->setGeometry(490, 170, 241, 271);
    ui->pic3->setGeometry(750, 210, 231, 221);
    ui->buy1->setGeometry(315, 500, 121, 35);
    ui->sell1->setGeometry(315, 545, 121, 35);
    ui->buy2->setGeometry(555, 500, 121, 35);
    ui->sell2->setGeometry(555, 545, 121, 35);
    ui->buy3->setGeometry(795, 500, 121, 35);
    ui->sell3->setGeometry(795, 545, 121, 35);
}


void Shop::on_product4_clicked()
{
    setHiddenPack(false, 1);
    setHiddenPack(false, 2);
    setHiddenPack(true, 3);
    category = 4;

    switchPack(1, "بیل", ":/shop/otherPic/shop/shovel.png", 50, 30);
    switchPack(2, "میخ", ":/shop/otherPic/shop/nail.png", 30, 20);

    ui->label1->setGeometry(375, 40, 151, 101);
    ui->label2->setGeometry(710, 40, 151, 101);
    ui->pic1->setGeometry(350, 200, 201, 191);
    ui->pic2->setGeometry(680, 220, 211, 171);
    ui->buy1->setGeometry(390, 500, 121, 35);
    ui->sell1->setGeometry(390, 545, 121, 35);
    ui->buy2->setGeometry(725, 500, 121, 35);
    ui->sell2->setGeometry(725, 545, 121, 35);
}


void Shop::on_buy1_clicked()
{
    switch (category)
    {
    case 1:
        setError(shop.buyWheat());
        break;
    case 3:
        setError(shop.buyPoultry());
        break;
    case 4:
        setError(shop.buyShovel());
        break;
    }
}


void Shop::on_sell1_clicked()
{
    switch (category)
    {
    case 1:
        setError(shop.sellWheat());
        break;
    case 2:
        setError(shop.sellEgg());
        break;
    case 3:
        setError(shop.sellPoultry());
        break;
    case 4:
        setError(shop.sellShovel());
        break;
    }
}


void Shop::on_buy2_clicked()
{
    switch (category)
    {
    case 1:
        setError(shop.buyHay());
        break;
    case 3:
        setError(shop.buyCattle());
        break;
    case 4:
        setError(shop.buyNail());
        break;
    }
}


void Shop::on_sell2_clicked()
{
    switch (category)
    {
    case 1:
        setError(shop.sellHay());
        break;
    case 2:
        setError(shop.sellMilk());
        break;
    case 3:
        setError(shop.sellCattle());
        break;
    case 4:
        setError(shop.sellNail());
        break;
    }
}

void Shop::on_buy3_clicked()
{
    setError(shop.buySheep());
}


void Shop::on_sell3_clicked()
{
    category == 2 ? setError(shop.sellWool()) : setError(shop.sellSheep());
}

void Shop::closeEvent(QCloseEvent *event)
{
    User tmp(shop.getQjo(), index);
    tmp.saveToFile();
    event->accept();
}
