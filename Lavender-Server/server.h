#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "user.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Server *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    QTime time;

public slots:
    void readyRead();
    void newConnectionSlot();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // SERVER_H
