#ifndef DAIRYFARM_H
#define DAIRYFARM_H

#include <QWidget>

namespace Ui {
class DairyFarm;
}

class DairyFarm : public QWidget
{
    Q_OBJECT

public:
    explicit DairyFarm(QWidget *parent = nullptr);
    ~DairyFarm();

private:
    Ui::DairyFarm *ui;
};

#endif // DAIRYFARM_H
