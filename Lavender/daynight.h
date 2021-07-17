#ifndef DAYNIGHT_H
#define DAYNIGHT_H

#include <QDialog>
#include <QMovie>

namespace Ui
{
    class DayNight;
}

class DayNight : public QDialog
{
    Q_OBJECT

public:
    explicit DayNight(QWidget *parent = nullptr);
    ~DayNight();

private:
    Ui::DayNight *ui;
};

#endif // DAYNIGHT_H