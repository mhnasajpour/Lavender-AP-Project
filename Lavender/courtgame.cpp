#include "courtgame.h"
#include "ui_courtgame.h"
#include "login.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

CourtGame::CourtGame(QJsonObject qjo, int index, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CourtGame),
    user(qjo, index)
{
    ui->setupUi(this);
}

CourtGame::~CourtGame()
{
    delete ui;
}

void CourtGame::saveToFile()
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray arr = (doc.object())["users"].toArray();
    arr[user.getIndex()] = QJsonObject(user.getQjo());
    QJsonObject main;
    main.insert("users", arr);
    doc.setObject(main);

    QFile file1("Users.json");
    file1.open(QIODevice::ReadWrite | QIODevice::Truncate);
    file1.write(doc.toJson());
    file1.close();
}
