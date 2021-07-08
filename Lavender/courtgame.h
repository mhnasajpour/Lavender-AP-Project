#ifndef COURTGAME_H
#define COURTGAME_H

#include <QMainWindow>
#include <QJsonObject>
#include <user.h>

namespace Ui {
class CourtGame;
}

class CourtGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourtGame(QJsonObject qjo, int index, QWidget *parent = nullptr);
    ~CourtGame();

private slots:
    void on_level_clicked();

private:
    Ui::CourtGame *ui;
    User user;
    void saveToFile();
};

#endif // COURTGAME_H
