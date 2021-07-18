#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QTcpSocket>

class ConnectToServer
{
public:
    ConnectToServer();
    QByteArray get();
    void set(QByteArray);

private:
    QTcpSocket* socket;
};

#endif // CONNECTTOSERVER_H
