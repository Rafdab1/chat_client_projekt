#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <QObject>
#include <QTcpSocket>

class Client_manager : public QObject
{
    Q_OBJECT
public:
    explicit Client_manager(QHostAddress ip, QObject *parent = nullptr);
    void connect_To_Server();
    void sendMessage(QString message);
    void get_state();
signals:
    void connected();
    void disconected();
    void dataRecived(QByteArray data);
private slots:
    void readyRead();

private:
    QTcpSocket *_socket;
    QHostAddress _ip;
};

#endif // CLIENT_MANAGER_H
