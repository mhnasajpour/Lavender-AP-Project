#include "server.h"

Server::Server(QWidget *parent)
    : QMainWindow(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2020);

    if (!server->isListening())
        qDebug() << "not listening. There is a problem";

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    qDebug() << "Listening...";
}

void Server::newConnectionSlot()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

Server::~Server()
{}

void Server::connected()
{
    qDebug()<<"Connected";
}
void Server::readyRead()
{
    QByteArray data = socket->readAll();

    if(data == "I WANT DATA")
    {
        QFile file("Lavender-Database.json");
        if(!file.open(QIODevice::ReadOnly))
            file.open(QIODevice::WriteOnly);

        socket->write(file.readAll());
        socket->waitForBytesWritten();
        qDebug() << "Send data succesfully";
        file.close();
    }
    else
    {
        QFile file("Lavender-Database.json");
        file.open(QIODevice::ReadWrite | QIODevice::Truncate);
        file.write(data);
        socket->waitForBytesWritten();
        qDebug() << "Write in file succesfully";
        file.close();
    }
}
