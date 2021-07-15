#ifndef STORAGE_H
#define STORAGE_H

#include <QWidget>
#include "storagebuilding.h"

namespace Ui {
class Storage;
}

class Storage : public QWidget
{
    Q_OBJECT

public:
    explicit Storage(QJsonObject, int, QWidget *parent = nullptr);
    ~Storage();

private slots:
    void on_pushButton_clicked();
    void on_request_accepted();
    void on_request_rejected();
    void on_continueKey_clicked();

private:
    Ui::Storage *ui;
    StorageBuilding storage;
    int index;
};

#endif // STORAGE_H
