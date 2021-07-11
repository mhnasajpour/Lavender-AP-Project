#ifndef LEVELUP_H
#define LEVELUP_H

#include <QDialog>

namespace Ui {
class LevelUp;
}

class LevelUp : public QDialog
{
    Q_OBJECT

public:
    explicit LevelUp(QWidget *parent = nullptr);
    ~LevelUp();

private:
    Ui::LevelUp *ui;
};

#endif // LEVELUP_H
