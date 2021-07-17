#ifndef SHEEPFOLD_H
#define SHEEPFOLD_H

#include <QWidget>
#include "sheepfoldbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class Sheepfold;
}

class Sheepfold : public QWidget
{
    Q_OBJECT

public:
    explicit Sheepfold(QJsonObject, int, QWidget *parent = nullptr);
    ~Sheepfold();

private slots:
    void on_door_clicked();
    void on_boardKey_clicked();
    void on_upgradeKey_clicked();
    void on_request_accepted();
    void on_request_rejected();
    void closeEvent(QCloseEvent *);

private:
    Ui::Sheepfold *ui;
    SheepFoldBuilding sheepfold;
    int index;
};

#endif // SHEEPFOLD_H