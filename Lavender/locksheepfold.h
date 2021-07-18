#ifndef LOCKSHEEPFOLD_H
#define LOCKSHEEPFOLD_H

#include <QWidget>
#include "sheepfoldbuilding.h"
#include "courtgame.h"

namespace Ui
{
    class LockSheepfold;
}

class LockSheepfold : public QWidget
{
    Q_OBJECT

public:
    explicit LockSheepfold(QJsonObject, int, QWidget *parent = nullptr);
    ~LockSheepfold();

private slots:
    void on_unlock_clicked();
    void on_door_clicked();
    void closeEvent(QCloseEvent *);

private:
    Ui::LockSheepfold *ui;
    SheepFoldBuilding sheepfold;
    int index;
};

#endif // LOCKSHEEPFOLD_H
