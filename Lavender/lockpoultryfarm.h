#ifndef LOCKPOULTRYFARM_H
#define LOCKPOULTRYFARM_H

#include <QWidget>

namespace Ui {
class LockPoultryFarm;
}

class LockPoultryFarm : public QWidget
{
    Q_OBJECT

public:
    explicit LockPoultryFarm(QWidget *parent = nullptr);
    ~LockPoultryFarm();

private:
    Ui::LockPoultryFarm *ui;
};

#endif // LOCKPOULTRYFARM_H
