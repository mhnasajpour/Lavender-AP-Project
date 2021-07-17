#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->eye->setHidden(true);
}

Login::~Login()
{
    delete ui;
}

void Login::on_ExitKey_clicked()
{
    close();
}

void Login::on_signupKey_clicked()
{
    Signup *signup = new Signup();
    signup->show();
    close();
}

void Login::on_enterKey_clicked()
{
    bool isGood = true;
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
    if (isGood)
    {
        QFile file("Users.json");
        if (file.open(QIODevice::ReadOnly))
        {
            QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
            QJsonArray arr = (doc.object())["users"].toArray();
            file.close();

            std::hash<QString> hashedPassword;
            unsigned long i = hashedPassword(ui->inputPassword->text());
            QString hashPass = QString::number(i);

            for (int i = 0; i < arr.size(); i++) // search array for authentication
                if ((arr[i].toObject())["username"].toString() == ui->inputUsername->text() && (arr[i].toObject())["password"].toString() == hashPass)
                {
                    CourtGame *cg = new CourtGame(arr[i].toObject(), i);
                    cg->show();
                    close();
                    break;
                }
        }
        else
        { // if file doesn't exist
            file.open(QIODevice::WriteOnly);
            file.close();
        }

        ui->inputUsername->setText("");
        ui->inputUsername->setPlaceholderText("invalid");
        ui->inputPassword->setText("");
        ui->inputPassword->setPlaceholderText("invalid");
        ui->eye->setHidden(true);
    }
}

void Login::on_eye_pressed()
{
    ui->inputPassword->setEchoMode(QLineEdit::Normal);
}

void Login::on_eye_released()
{
    ui->inputPassword->setEchoMode(QLineEdit::Password);
}

void Login::on_inputPassword_textEdited(const QString &arg1)
{
    if (arg1 == "")
        ui->eye->setHidden(true);
    else
        ui->eye->setHidden(false);
}