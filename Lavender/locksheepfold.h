#ifndef LOCKSHEEPFOLD_H
#define LOCKSHEEPFOLD_H

#include <QWidget>

namespace Ui {
class LockSheepfold;
}

class LockSheepfold : public QWidget
{
    Q_OBJECT

public:
    explicit LockSheepfold(QWidget *parent = nullptr);
    ~LockSheepfold();

private:
    Ui::LockSheepfold *ui;
};

#endif // LOCKSHEEPFOLD_H
