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
    void on_storage_clicked();
    void on_silo_clicked();
    void on_wheatFarm_clicked();
    void on_hayFarm_clicked();

    void on_poultryFarm_clicked();

    void on_dairyFarm_clicked();

private:
    Ui::CourtGame *ui;
    User user;
};

#endif // COURTGAME_H
