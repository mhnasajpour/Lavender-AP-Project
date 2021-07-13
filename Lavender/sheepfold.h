#ifndef SHEEPFOLD_H
#define SHEEPFOLD_H

#include <QWidget>

namespace Ui {
class Sheepfold;
}

class Sheepfold : public QWidget
{
    Q_OBJECT

public:
    explicit Sheepfold(QWidget *parent = nullptr);
    ~Sheepfold();

private:
    Ui::Sheepfold *ui;
};

#endif // SHEEPFOLD_H
