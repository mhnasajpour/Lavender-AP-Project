#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>

class Server : public QMainWindow
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private:
    QTcpServer *server;
    QTcpSocket *socket;

public slots:
    void connected();
    void readyRead();
    void newConnectionSlot();
};
#endif // SERVER_H
