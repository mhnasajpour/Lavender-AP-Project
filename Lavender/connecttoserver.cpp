#include "connecttoserver.h"

ConnectToServer::ConnectToServer()
{
    socket = new QTcpSocket;
    socket->connectToHost("127.0.0.1", 2020);
    socket->waitForConnected();
}

QByteArray ConnectToServer::get()
{
    socket->write("I WANT DATA");
    socket->waitForBytesWritten();
    socket->waitForReadyRead();
    return socket->readAll();
}

void ConnectToServer::set(QByteArray qjo)
{
    socket->write(qjo);
    socket->waitForBytesWritten();
}
