#ifndef SILO_H
#define SILO_H

#include <QWidget>

namespace Ui {
class Silo;
}

class Silo : public QWidget
{
    Q_OBJECT

public:
    explicit Silo(QWidget *parent = nullptr);
    ~Silo();

private:
    Ui::Silo *ui;
};

#endif // SILO_H
