#include "client_manager.h"

Client_manager::Client_manager(QHostAddress ip, QObject *parent)
    :QObject{parent},
    ip(ip)
{
    _socket = new QTcpSocket(this);
    connect(_socket, &QTcpSocket::connected,this,&Client_manager::connected);
    connect(_socket, &QTcpSocket::disconnected,this,&Client_manager::disconected);
    connect(_socket, &QTcpSocket::readyRead,this,&Client_manager::readyRead);
}

Client_manager::~Client_manager()
{
    qDebug() << "Client_manager dupa";
}

void Client_manager::connect_To_Server()
{
    _socket->connectToHost(ip,4500);
}

void Client_manager::disconect_from_server()
{
    _socket->disconnectFromHost();
    _socket->close();
}

void Client_manager::sendMessage(QString message)
{
    _socket->write(message.toUtf8());
}

void Client_manager::check_data_recived_recivers()
{
    qDebug() << this->receivers(SIGNAL(dataRecived(QByteArray)));
}

QByteArray Client_manager::read_data()
{
    return _socket->readAll();
}

bool Client_manager::wait_for_responce(int ms)
{
    return _socket->waitForReadyRead(ms);
}


void Client_manager::readyRead()
{
    QByteArray data = _socket->readAll();
    qDebug() << "Recived";
    qDebug() << "Client_manager: " + QString::fromStdString(data.toStdString());
    emit dataRecived(data);
}
