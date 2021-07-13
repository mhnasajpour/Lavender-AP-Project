#ifndef POULTRYFARM_H
#define POULTRYFARM_H

#include <QWidget>

namespace Ui {
class PoultryFarm;
}

class PoultryFarm : public QWidget
{
    Q_OBJECT

public:
    explicit PoultryFarm(QWidget *parent = nullptr);
    ~PoultryFarm();

private:
    Ui::PoultryFarm *ui;
};

#endif // POULTRYFARM_H
