#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QDebug>

class TCPServer : public QObject
{
    Q_OBJECT
public:
    explicit TCPServer(QObject *parent = nullptr);

signals:

    public slots:
        void newConnection();

    private:
        QTcpServer *server;
        int clients;
};

#endif // TCPSERVER_H
