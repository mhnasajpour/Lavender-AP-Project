#ifndef RANKING_H
#define RANKING_H

#include <QDialog>

namespace Ui {
class Ranking;
}

class Ranking : public QDialog
{
    Q_OBJECT

public:
    explicit Ranking(QString username, QWidget *parent = nullptr);
    ~Ranking();

private:
    Ui::Ranking *ui;
    int index;
};

#endif // RANKING_H
