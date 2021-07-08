#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_ExitKey_clicked();
    void on_signupKey_clicked();
    void on_enterKey_clicked();

    void on_eye_clicked();

private:
    Ui::Login *ui;
    bool isShowPassword;
};
#endif // LOGIN_H
