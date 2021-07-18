#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2020);

    if (!server->isListening())
        ui->textEdit->setText("not listening. There is a problem");

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    ui->textEdit->setText("Listening...");
}

Server::~Server()
{
    delete ui;
}

void Server::newConnectionSlot()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Server::connected()
{
    ui->textEdit->append("Connected");
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
        ui->textEdit->append("Send data succesfully");
        file.close();
    }
    else
    {
        QFile file("Lavender-Database.json");
        file.open(QIODevice::ReadWrite | QIODevice::Truncate);
        file.write(data);
        ui->textEdit->append("Write in file succesfully");
        file.close();
    }
}
