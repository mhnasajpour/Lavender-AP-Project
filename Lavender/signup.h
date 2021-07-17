#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "login.h"

namespace Ui
{
    class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

private:
    void addUser(QString name, QString email, QString username, unsigned long password);
    int check(QString _username, QString _email);

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_returnKey_clicked();
    void on_nextKey_clicked();
    void on_acceptKey_clicked();
    void on_eye1_pressed();
    void on_eye1_released();
    void on_eye2_pressed();
    void on_eye2_released();
    void on_inputPassword_textEdited(const QString &arg1);
    void on_inputRepeat_textEdited(const QString &arg1);

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H