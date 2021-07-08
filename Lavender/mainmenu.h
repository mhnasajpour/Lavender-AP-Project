#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QJsonObject>
#include <user.h>

namespace Ui {
class mainMenu;
}

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainMenu(User, QWidget *parent = nullptr);
    ~mainMenu();

private slots:
    void on_nameEdit_clicked();
    void on_emailEdit_clicked();
    void on_usernameEdit_clicked();
    void on_inputName_editingFinished();
    void on_inputEmail_editingFinished();
    void on_inputUsername_editingFinished();
    void on_inputEmail_textEdited(const QString &arg1);
    void on_inputUsername_textEdited(const QString &arg1);
    void on_nextDay_clicked();
    void on_exitKey_clicked();
    void on_continueKey_clicked();

private:
    Ui::mainMenu *ui;
    User user;
    bool isValidEmail;
    bool isValidUsername;
};

#endif // MAINMENU_H
