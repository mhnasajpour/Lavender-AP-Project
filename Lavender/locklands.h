#ifndef LOCKLANDS_H
#define LOCKLANDS_H

#include <QDialog>
#include "hayfarmbuilding.h"

namespace Ui {
class LockLands;
}

class LockLands : public QDialog
{
    Q_OBJECT

public:
    explicit LockLands(QJsonObject, int, QWidget *parent = nullptr);
    ~LockLands();

private slots:
    void on_unlock_clicked();
    void on_door_clicked();

private:
    Ui::LockLands *ui;
    HayFarmBuilding hay_farm;
    int index;
};

#endif // LOCKLANDS_H
