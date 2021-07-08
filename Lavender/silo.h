#ifndef SILO_H
#define SILO_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
class Silo;
}

class Silo : public QWidget
{
    Q_OBJECT

public:
    explicit Silo(QJsonObject _qjo, QWidget *parent = nullptr);
    ~Silo();

private:
    Ui::Silo *ui;
    QJsonObject qjo;
};

#endif // SILO_H
