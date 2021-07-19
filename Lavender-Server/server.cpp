#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);

    QFile file("Lavender-Database.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        file.open(QIODevice::WriteOnly);
        QJsonObject main;
        main.insert("users", QJsonArray());
        file.write(QJsonDocument(main).toJson());
        file.close();
    }

    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 2020);

    if (!server->isListening())
        ui->textEdit->setText("not listening. There is a problem");

    connect(server, SIGNAL(newConnection()), this, SLOT(newConnectionSlot()));
    ui->textEdit->setText((time.currentTime()).toString() + "       Listening...\t\n");
}

Server::~Server()
{
    delete ui;
}

void Server::newConnectionSlot()
{
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void Server::readyRead()
{
    QByteArray data = socket->readAll();

    if(data == "I WANT DATA") //get
    {
        QFile file("Lavender-Database.json");
        file.open(QIODevice::ReadOnly);

        socket->write(file.readAll());
        socket->waitForBytesWritten();
        ui->textEdit->append((time.currentTime()).toString() + "       Transferring data       " + QString::number(socket->socketDescriptor()) + "\t");
        file.close();
    }
    else //set
    {
        QFile file("Lavender-Database.json");
        file.open(QIODevice::ReadWrite | QIODevice::Truncate);
        file.write(data);
        file.close();
    }
}

void Server::on_pushButton_clicked()
{
    QString dir;
    dir = QFileDialog::getSaveFileName(this, "Save");
    dir += ".txt";
    QFile file(dir);
    file.open(QFile::WriteOnly | QFile::Truncate);
    file.write(ui->textEdit->toPlainText().toUtf8());
    file.close();
}


void Server::on_pushButton_2_clicked()
{
    QString text = QInputDialog::getText(this, tr("Lavender"), tr("Username:"), QLineEdit::Normal);
    if (!text.isEmpty())
    {
        QFile file("Lavender-Database.json");
        file.open(QIODevice::ReadOnly);

        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonArray arr = (doc.object())["users"].toArray();

        for (int i = 0; i < arr.size(); i++)
            if ((arr[i].toObject())["username"].toString() == text)
            {
                doc.setObject(arr[i].toObject());
                User *u = new User(doc.toJson(), this);
                u->exec();
                return;
            }

        User *u = new User("This user does not exist !!!");
        u->exec();
    }
}

