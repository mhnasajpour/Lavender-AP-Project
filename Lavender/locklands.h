#ifndef LOCKLANDS_H
#define LOCKLANDS_H

#include <QDialog>

namespace Ui {
class LockLands;
}

class LockLands : public QDialog
{
    Q_OBJECT

public:
    explicit LockLands(QWidget *parent = nullptr);
    ~LockLands();

private:
    Ui::LockLands *ui;
};

#endif // LOCKLANDS_H
