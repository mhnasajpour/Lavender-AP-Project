#include "signup.h"
#include "ui_signup.h"

void Signup::addUser(QString _name, QString _email, QString _username, unsigned long _password)
{
    QJsonObject root, storage, silo, poultryFarm, dairyFarm, sheepfold, wheatFarm, hayFarm;
    root.insert("name", _name);
    root.insert("email", _email);
    root.insert("username", _username);
    root.insert("password", QString::number(_password));
    root.insert("level", 1);
    root.insert("exp", 0);
    root.insert("coin", 20);
    root.insert("day", 0);

    storage.insert("level", 1);
    storage.insert("daysToFinishUpgrading", 0);
    storage.insert("usedCapacity", 2);
    storage.insert("shovel", 0);
    storage.insert("nail", 1);
    storage.insert("hay", 1);
    storage.insert("egg", 0);
    QJsonArray milk;
    storage.insert("milk", milk);
    storage.insert("wool", 0);

    silo.insert("level", 1);
    silo.insert("daysToFinishUpgrading", 0);
    silo.insert("wheat", 1);

    poultryFarm.insert("level", 0);
    poultryFarm.insert("daysToFinishUpgrading", 0);
    poultryFarm.insert("daysToFinishEstablishing", -1);
    poultryFarm.insert("daysToFinishFeeding", 0);
    poultryFarm.insert("animals", 0);
    poultryFarm.insert("flag", 1);

    dairyFarm.insert("level", 0);
    dairyFarm.insert("daysToFinishUpgrading", 0);
    dairyFarm.insert("daysToFinishEstablishing", -1);
    dairyFarm.insert("daysToFinishFeeding", 0);
    dairyFarm.insert("animals", 0);
    dairyFarm.insert("flag", 1);

    sheepfold.insert("level", 0);
    sheepfold.insert("daysToFinishUpgrading", 0);
    sheepfold.insert("daysToFinishEstablishing", -1);
    sheepfold.insert("daysToFinishFeeding", 0);
    sheepfold.insert("animals", 0);
    sheepfold.insert("flag", 1);

    wheatFarm.insert("level", 1);
    wheatFarm.insert("daysToFinishUpgrading", 0);
    wheatFarm.insert("plantingArea", 0);
    wheatFarm.insert("daysToFinishPlanting", 0);
    wheatFarm.insert("flag", 1);

    hayFarm.insert("level", 0);
    hayFarm.insert("daysToFinishUpgrading", 0);
    hayFarm.insert("daysToFinishEstablishing", -1);
    hayFarm.insert("plantingArea", 0);
    hayFarm.insert("daysToFinishPlanting", 0);
    hayFarm.insert("daysToFinishPlowing", 0);
    hayFarm.insert("flag", 4);

    root.insert("storage", storage);
    root.insert("silo", silo);
    root.insert("poultryFarm", poultryFarm);
    root.insert("dairyFarm", dairyFarm);
    root.insert("sheepfold", sheepfold);
    root.insert("wheatFarm", wheatFarm);
    root.insert("hayFarm", hayFarm);

    ConnectToServer socket;

    QJsonDocument doc = QJsonDocument::fromJson(socket.get());
    QJsonArray arr = (doc.object())["users"].toArray();
    arr.append(root);
    QJsonObject main;
    main.insert("users", arr);
    doc.setObject(main);

    socket.set(doc.toJson());
}

int Signup::check(QString _username, QString _email)
{
    ConnectToServer socket;
    QJsonArray users = ((QJsonDocument::fromJson(socket.get())).object())["users"].toArray();

    for (int i = 0; i < users.size(); i++)
    {
        if ((users[i].toObject())["email"].toString() == _email)
            return 2;
        if ((users[i].toObject())["username"].toString() == _username)
            return 1;
    }
    return 3;
}

Signup::Signup(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::Signup)
{
    ui->setupUi(this);
    ui->nextKey->setHidden(true);
    ui->message->setHidden(true);
    ui->eye1->setHidden(true);
    ui->eye2->setHidden(true);
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
    if (ui->inputName->text() == "")
    {
        ui->inputName->setPlaceholderText("is empty");
        isGood = false;
    }
    if (ui->inputUsername->text() == "")
    {
        ui->inputUsername->setPlaceholderText("is empty");
        isGood = false;
    }
    if (ui->inputPassword->text() == "")
    {
        ui->inputPassword->setPlaceholderText("is empty");
        isGood = false;
    }
    if (ui->inputRepeat->text() == "")
    {
        ui->inputRepeat->setPlaceholderText("is empty");
        isGood = false;
    }
    if (ui->inputEmail->text() == "")
    {
        ui->inputEmail->setPlaceholderText("is empty");
        isGood = false;
    }
    if (ui->inputPassword->text() != ui->inputRepeat->text())
    {
        ui->inputPassword->setPlaceholderText("not same");
        ui->inputPassword->setText("");
        ui->inputRepeat->setPlaceholderText("not same");
        ui->inputRepeat->setText("");
        ui->eye1->setHidden(true);
        ui->eye2->setHidden(true);
        isGood = false;
    }
    if (check(ui->inputUsername->text(), ui->inputEmail->text()) != 3)
    {
        if (check(ui->inputUsername->text(), ui->inputEmail->text()) == 1)
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
    if (isGood)
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

void Signup::on_eye1_pressed()
{
    ui->inputPassword->setEchoMode(QLineEdit::Normal);
}

void Signup::on_eye1_released()
{
    ui->inputPassword->setEchoMode(QLineEdit::Password);
}

void Signup::on_eye2_pressed()
{
    ui->inputRepeat->setEchoMode(QLineEdit::Normal);
}

void Signup::on_eye2_released()
{
    ui->inputRepeat->setEchoMode(QLineEdit::Password);
}

void Signup::on_inputPassword_textEdited(const QString &arg1)
{
    if (arg1 == "")
        ui->eye1->setHidden(true);
    else
        ui->eye1->setHidden(false);
}

void Signup::on_inputRepeat_textEdited(const QString &arg1)
{
    if (arg1 == "")
        ui->eye2->setHidden(true);
    else
        ui->eye2->setHidden(false);
}
