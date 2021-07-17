#include "ranking.h"
#include "ui_ranking.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <algorithm>
using namespace std;

inline void swap(QJsonValueRef v1, QJsonValueRef v2)
{
    QJsonValue temp(v1);
    v1 = QJsonValue(v2);
    v2 = temp;
}

long totalExp(int level, int exp)
{
    long ans = 0;
    for(int i = 1; i < level; i++)
        ans += 10 * (pow(2, i) - 1) + i;
    return ans + exp;
}

bool compare(QJsonValue a, QJsonValue b)
{
    long user1 = totalExp(a.toObject()["level"].toInt(), a.toObject()["exp"].toInt());
    long user2 = totalExp(b.toObject()["level"].toInt(), b.toObject()["exp"].toInt());

    if(user1 != user2)
        return user1 > user2;

    return a.toObject()["coin"].toInt() > b.toObject()["coin"].toInt();
}

Ranking::Ranking(QString _username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ranking)
{
    ui->setupUi(this);

    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QJsonArray arr = (doc.object())["users"].toArray();
    file.close();

    sort(arr.begin(), arr.end(), compare);

    //for(int i )

    for(int i = 0; i < arr.size() && i < 30; i++)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        QTableWidgetItem *widgetItem1 = new QTableWidgetItem(arr[i].toObject()["name"].toString());
        QTableWidgetItem *widgetItem2 = new QTableWidgetItem(QString::number(totalExp(arr[i].toObject()["level"].toInt(), arr[i].toObject()["exp"].toInt())));
        QTableWidgetItem *widgetItem3 = new QTableWidgetItem(QString::number(arr[i].toObject()["level"].toInt()));
        QTableWidgetItem *widgetItem4 = new QTableWidgetItem(QString::number(arr[i].toObject()["coin"].toInt()));

        widgetItem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        widgetItem2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        widgetItem3->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        widgetItem4->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, widgetItem1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, widgetItem2);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, widgetItem3);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, widgetItem4);
    }
}

Ranking::~Ranking()
{
    delete ui;
}
