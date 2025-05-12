#include "client_manager.h"

Client_manager::Client_manager(QHostAddress ip, QObject *parent)
    :QObject{parent},
    _ip(ip)
{
    _socket = new QTcpSocket(this);
    connect(_socket, &QTcpSocket::connected,this,&Client_manager::connected);
    connect(_socket, &QTcpSocket::disconnected,this,&Client_manager::disconected);
    connect(_socket, &QTcpSocket::readyRead,this,&Client_manager::readyRead);
}

void Client_manager::connect_To_Server()
{
    _socket->connectToHost(_ip,4500);
    qDebug() << _socket->state();
}

void Client_manager::sendMessage(QString message)
{
    _socket->write(message.toUtf8());
}


void Client_manager::readyRead()
{
    QByteArray data = _socket->readAll();
    emit dataRecived(data);
}
