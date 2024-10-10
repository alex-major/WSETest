#include "tcpserver.h"

TCPServer::TCPServer(QObject *parent)
    : QObject{parent}
{
    server = new QTcpServer(this);
    clients = 0;

    connect(server, SIGNAL(newConnection()),
            this, SLOT(newConnection()));

    if(!server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void TCPServer::newConnection()
{
    this->clients = this->clients + 1;
    QTcpSocket *socket = server->nextPendingConnection();

    QJsonObject json;

    json["client"] = QString::number(this->clients);

    QJsonDocument doc(json);

    socket->write(doc.toJson());
    socket->flush();
}
