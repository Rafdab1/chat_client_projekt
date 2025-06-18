#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <QObject>
#include <QTcpSocket>

class Client_manager : public QObject
{
    Q_OBJECT
public:
    explicit Client_manager(QHostAddress ip, QObject *parent = nullptr);
    ~Client_manager();
    void connect_To_Server();
    void disconect_from_server();
    void sendMessage(QString message);
    void check_data_recived_recivers();
    QByteArray read_data();
    bool wait_for_responce(int ms);
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
