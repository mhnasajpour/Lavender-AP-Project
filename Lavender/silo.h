#ifndef SILO_H
#define SILO_H

#include <QWidget>
#include "silobuilding.h"
#include "user.h"
#include <QJsonObject>

namespace Ui {
class Silo;
}

class Silo : public QWidget
{
    Q_OBJECT

public:
    explicit Silo(QJsonObject, int, QWidget *parent = nullptr);
    ~Silo();

private slots:
    void on_pushButton_clicked();
    void on_request_accepted();
    void on_request_rejected();
    void on_continueKey_clicked();
    void closeEvent(QCloseEvent*);

private:
    Ui::Silo *ui;
    SiloBuilding silo;
    int index;
};

#endif // SILO_H
