#ifndef LOCKLANDS_H
#define LOCKLANDS_H

#include <QDialog>
#include "hayfarmbuilding.h"

namespace Ui {
class LockLands;
}

class LockLands : public QDialog
{
    Q_OBJECT

public:
    explicit LockLands(BaseEstablish&, QWidget *parent = nullptr);
    ~LockLands();

private slots:
    void on_unlock_clicked();

private:
    Ui::LockLands *ui;
    BaseEstablish& bte;
};

#endif // LOCKLANDS_H
