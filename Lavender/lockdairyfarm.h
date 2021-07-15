#ifndef LOCKDAIRYFARM_H
#define LOCKDAIRYFARM_H

#include <QWidget>

namespace Ui {
class LockDairyFarm;
}

class LockDairyFarm : public QWidget
{
    Q_OBJECT

public:
    explicit LockDairyFarm(QWidget *parent = nullptr);
    ~LockDairyFarm();

private:
    Ui::LockDairyFarm *ui;
};

#endif // LOCKDAIRYFARM_H
