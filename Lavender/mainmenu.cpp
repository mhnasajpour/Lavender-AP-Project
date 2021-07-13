#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "login.h"
#include "courtgame.h"
#include "daynight.h"

mainMenu::mainMenu(User _user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainMenu),
    user(_user)
{
    ui->setupUi(this);

    ui->levelShow->setText(QString::number(user.getLevelPlayer()));
    ui->expShow->setText(QString::number(user.getExp()));
    ui->coinShow->setText(QString::number(user.getCoin()));

    ui->inputName->setText(user.getName());
    ui->inputEmail->setText(user.getEmail());
    ui->inputUsername->setText(user.getUsername());

    isValidEmail = true;
    isValidUsername = true;
}

mainMenu::~mainMenu()
{
    delete ui;
}

void mainMenu::on_nameEdit_clicked()
{
    ui->inputName->setReadOnly(false);
    ui->inputName->selectAll();
    ui->nameEdit->setHidden(true);
}

void mainMenu::on_emailEdit_clicked()
{
    ui->inputEmail->setReadOnly(false);
    ui->inputEmail->selectAll();
    ui->emailEdit->setIcon(QIcon(":/tools/otherPic/valid.png"));
}

void mainMenu::on_usernameEdit_clicked()
{
    ui->inputUsername->setReadOnly(false);
    ui->inputUsername->selectAll();
    ui->usernameEdit->setIcon(QIcon(":/tools/otherPic/valid.png"));
}

void mainMenu::on_inputName_editingFinished()
{
    ui->inputName->setReadOnly(true);
    if(ui->inputName->text() == "")
        ui->inputName->setText(user.getName());
    ui->nameEdit->setHidden(false);
}

void mainMenu::on_inputEmail_editingFinished()
{
    ui->inputEmail->setReadOnly(true);
    if(!isValidEmail)
        ui->inputEmail->setText(user.getEmail());
    ui->emailEdit->setIcon(QIcon(":/tools/otherPic/edit.png"));
}

void mainMenu::on_inputUsername_editingFinished()
{
    ui->inputUsername->setReadOnly(true);
    if(!isValidUsername)
        ui->inputUsername->setText(user.getUsername());
    ui->usernameEdit->setIcon(QIcon(":/tools/otherPic/edit.png"));
}

void mainMenu::on_inputEmail_textEdited(const QString &arg1)
{
    if(arg1 == "")
    {
        isValidEmail = false;
        ui->emailEdit->setIcon(QIcon(":/tools/otherPic/invalid.png"));
        return;
    }

    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray users = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();

    for(int i = 0; i < users.size(); i++)
    {
        if((users[i].toObject())["email"].toString() == arg1 && user.getEmail() != arg1)
        {
            isValidEmail = false;
            ui->emailEdit->setIcon(QIcon(":/tools/otherPic/invalid.png"));
            return;
        }
    }
    isValidEmail = true;
    ui->emailEdit->setIcon(QIcon(":/tools/otherPic/valid.png"));
}

void mainMenu::on_inputUsername_textEdited(const QString &arg1)
{
    if(arg1 == "")
    {
        isValidUsername = false;
        ui->usernameEdit->setIcon(QIcon(":/tools/otherPic/invalid.png"));
        return;
    }

    QFile file("Users.json");
    file.open(QIODevice::ReadOnly);
    QJsonArray users = ((QJsonDocument::fromJson(file.readAll())).object())["users"].toArray();
    file.close();

    for(int i = 0; i < users.size(); i++)
    {
        if((users[i].toObject())["username"].toString() == arg1 && user.getUsername() != arg1)
        {
            isValidUsername = false;
            ui->usernameEdit->setIcon(QIcon(":/tools/otherPic/invalid.png"));
            return;
        }
    }
    isValidUsername = true;
    ui->usernameEdit->setIcon(QIcon(":/tools/otherPic/valid.png"));
}

void mainMenu::on_nextDay_clicked()
{
    user.nextDay();
    DayNight dn;
    dn.exec();
    ui->levelShow->setText(QString::number(user.getLevelPlayer()));
    ui->expShow->setText(QString::number(user.getExp()));
    ui->coinShow->setText(QString::number(user.getCoin()));
}

void mainMenu::on_exitKey_clicked()
{
    user.setName(ui->inputName->text());
    user.setEmail(ui->inputEmail->text());
    user.setUsername(ui->inputUsername->text());
    user.saveToFile();
    Login* lp = new Login;
    lp->show();
    close();
}

void mainMenu::on_continueKey_clicked()
{
    user.setName(ui->inputName->text());
    user.setEmail(ui->inputEmail->text());
    user.setUsername(ui->inputUsername->text());
    user.saveToFile();
    CourtGame* cgp = new CourtGame(user.getQjo(), user.getIndex());
    cgp->show();
    close();
}

