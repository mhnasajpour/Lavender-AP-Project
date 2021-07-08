#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>

void Signup::addUser(QString _name, QString _email, QString _username, unsigned long _password)
{
    QJsonObject root, storage, silo, poultryFarm, dairyFarm, sheepFold, wheatFarm, hayFarm;
    root.insert("name", _name);
    root.insert("email", _email);
    root.insert("username", _username);
    root.insert("password", QString::number(_password));
    root.insert("level", 1);
    root.insert("exp", 0);
    root.insert("coin", 20);
    root.insert("time", 0);

    storage.insert("level", 1);
    storage.insert("usedCapacity", 2);
    storage.insert("shovel", 0);
    storage.insert("nail", 1);
    storage.insert("hay", 1);
    storage.insert("egg", 0);
    QJsonArray milk;
    storage.insert("milk", milk);
    storage.insert("wool", 0);

    silo.insert("level", 1);
    silo.insert("wheat", 1);

    poultryFarm.insert("level", 0);
    poultryFarm.insert("poultry", 0);
    poultryFarm.insert("feedTime", 0);
    poultryFarm.insert("flag", 1);

    dairyFarm.insert("level", 0);
    dairyFarm.insert("cattle", 0);
    dairyFarm.insert("feedTime", 0);
    dairyFarm.insert("flag", 1);

    sheepFold.insert("level", 0);
    sheepFold.insert("sheep", 0);
    sheepFold.insert("feedTime", 0);
    sheepFold.insert("flag", 1);

    wheatFarm.insert("level", 1);
    wheatFarm.insert("plantingArea", 5);
    wheatFarm.insert("timeProcess", 0);
    wheatFarm.insert("flag", 1);

    hayFarm.insert("level", 0);
    hayFarm.insert("plantingArea", 4);
    hayFarm.insert("timeProcess", 0);
    hayFarm.insert("flag", 1);

    root.insert("storage", storage);
    root.insert("silo", silo);
    root.insert("poultryFarm", poultryFarm);
    root.insert("dairyFarm", dairyFarm);
    root.insert("sheepFold", sheepFold);
    root.insert("wheatFarm", wheatFarm);
    root.insert("hayFarm", hayFarm);

    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();

    QJsonArray arr = (doc.object())["users"].toArray();
    arr.append(root);
    QJsonObject main;
    main.insert("users", arr);
    doc.setObject(main);

    QFile file1("Users.json");
    file1.open(QIODevice::ReadWrite | QIODevice::Truncate);
    file1.write(doc.toJson());
    file1.close();
}

int Signup::check(QString _username, QString _email)
{
    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray user = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();

    for(int i = 0; i < user.size(); i++)
    {
        if((user[i].toObject())["email"].toString() == _email)
            return 2;
        if((user[i].toObject())["username"].toString() == _username)
            return 1;
    }
    return 3;
}

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signup)
{
    isShowPassword1 = false;
    isShowPassword2 = false;
    ui->setupUi(this);
    ui->nextKey->setHidden(true);
    ui->message->setHidden(true);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_returnKey_clicked()
{
    Login *l = new Login;
    l->show();
    close();
}


void Signup::on_nextKey_clicked()
{
    Login *l = new Login;
    l->show();
    close();
}

void Signup::on_acceptKey_clicked()
{
    bool isGood = true;
    if(ui->inputName->text() == "")
    {
        ui->inputName->setPlaceholderText("is empty");
        isGood = false;
    }
    if(ui->inputUsername->text() == "")
    {
        ui->inputUsername->setPlaceholderText("is empty");
        isGood = false;
    }
    if(ui->inputPassword->text() == "")
    {
        ui->inputPassword->setPlaceholderText("is empty");
        isGood = false;
    }
    if(ui->inputRepeat->text() == "")
    {
        ui->inputRepeat->setPlaceholderText("is empty");
        isGood = false;
    }
    if(ui->inputEmail->text() == "")
    {
        ui->inputEmail->setPlaceholderText("is empty");
        isGood = false;
    }
    if(ui->inputPassword->text() != ui->inputRepeat->text())
    {
        ui->inputPassword->setPlaceholderText("not same");
        ui->inputPassword->setText("");
        ui->inputRepeat->setPlaceholderText("not same");
        ui->inputRepeat->setText("");
        isGood = false;
    }
    if(check(ui->inputUsername->text(), ui->inputEmail->text()) != 3)
    {
        if(check(ui->inputUsername->text(), ui->inputEmail->text()) == 1)
        {
            ui->inputUsername->setPlaceholderText("was taken");
            ui->inputUsername->setText("");
        }
        else
        {
            ui->inputEmail->setPlaceholderText("was taken");
            ui->inputEmail->setText("");
        }
        isGood = false;
    }
    if(isGood)
    {
        std::hash<QString> hashedPassword;
        unsigned long i = hashedPassword(ui->inputPassword->text());
        addUser(ui->inputName->text(), ui->inputEmail->text(), ui->inputUsername->text(), i);
        ui->message->setHidden(false);
        ui->nextKey->setHidden(false);
        ui->acceptKey->setHidden(true);
        ui->returnKey->setHidden(true);

        ui->inputName->setReadOnly(true);
        ui->inputEmail->setReadOnly(true);
        ui->inputUsername->setReadOnly(true);
        ui->inputPassword->setReadOnly(true);
        ui->inputRepeat->setReadOnly(true);

        ui->inputName->setClearButtonEnabled(false);
        ui->inputEmail->setClearButtonEnabled(false);
        ui->inputUsername->setClearButtonEnabled(false);
        ui->inputPassword->setClearButtonEnabled(false);
        ui->inputRepeat->setClearButtonEnabled(false);

        ui->inputName->clearFocus();
        ui->inputEmail->clearFocus();
        ui->inputUsername->clearFocus();
        ui->inputPassword->clearFocus();
        ui->inputRepeat->clearFocus();
    }
}


void Signup::on_eye1_clicked()
{
    if(isShowPassword1){
        ui->inputPassword->setEchoMode(QLineEdit::Password);
        isShowPassword1 = false;
    }
    else{
        ui->inputPassword->setEchoMode(QLineEdit::Normal);
        isShowPassword1 = true;
    }
}


void Signup::on_eye2_clicked()
{
    if(isShowPassword2){
        ui->inputRepeat->setEchoMode(QLineEdit::Password);
        isShowPassword2 = false;
    }
    else{
        ui->inputRepeat->setEchoMode(QLineEdit::Normal);
        isShowPassword2 = true;
    }
}

