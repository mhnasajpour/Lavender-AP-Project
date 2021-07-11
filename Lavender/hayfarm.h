#ifndef HAYFARM_H
#define HAYFARM_H

#include <QWidget>

namespace Ui {
class hayFarm;
}

class hayFarm : public QWidget
{
    Q_OBJECT

public:
    explicit hayFarm(QWidget *parent = nullptr);
    ~hayFarm();

private:
    Ui::hayFarm *ui;
};

#endif // HAYFARM_H
