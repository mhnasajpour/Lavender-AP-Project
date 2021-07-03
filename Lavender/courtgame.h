#ifndef COURTGAME_H
#define COURTGAME_H

#include <QMainWindow>

namespace Ui {
class CourtGame;
}

class CourtGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CourtGame(QWidget *parent = nullptr);
    ~CourtGame();

private:
    Ui::CourtGame *ui;
};

#endif // COURTGAME_H
