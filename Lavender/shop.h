#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include "shopbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class Shop;
}

class Shop : public QWidget
{
    Q_OBJECT

public:
    explicit Shop(QJsonObject, int, QWidget *parent = nullptr);
    ~Shop();

private slots:
    void on_door_clicked();
    void on_product1_clicked();
    void on_product2_clicked();
    void on_product3_clicked();
    void on_product4_clicked();
    void on_buy1_clicked();
    void on_sell1_clicked();
    void on_buy2_clicked();
    void on_sell2_clicked();
    void on_buy3_clicked();
    void on_sell3_clicked();
    //void closeEvent(QCloseEvent *);

private:
    Ui::Shop *ui;
    ShopBuilding shop;
    int index;
    void setHiddenPack(bool, int);
    void switchPack(int, QString, QString, int, int);
    void setError(int);
    int category;
};

#endif // SHOP_H
