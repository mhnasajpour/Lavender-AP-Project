#ifndef STORAGE_H
#define STORAGE_H

#include <QWidget>

namespace Ui {
class Storage;
}

class Storage : public QWidget
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    ~Storage();

private:
    Ui::Storage *ui;
};

#endif // STORAGE_H
