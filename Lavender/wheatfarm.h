#ifndef WHEATFARM_H
#define WHEATFARM_H

#include <QWidget>

namespace Ui {
class WheatFarm;
}

class WheatFarm : public QWidget
{
    Q_OBJECT

public:
    explicit WheatFarm(QWidget *parent = nullptr);
    ~WheatFarm();

private:
    Ui::WheatFarm *ui;
};

#endif // WHEATFARM_H
