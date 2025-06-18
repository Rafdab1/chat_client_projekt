#ifndef OKNO_CHAT_H
#define OKNO_CHAT_H

#include <QDialog>
#include "client_manager.h"
#include "funkcje_pomocnicze.h"
#include <QDebug>

namespace Ui {
class okno_chat;
}

class okno_chat : public QDialog
{
    Q_OBJECT

public:
    explicit okno_chat(Client_manager *client,QWidget *parent = nullptr);
    ~okno_chat();

private slots:
    void setup_read( QByteArray data );
    void running_read( QByteArray data );

    void on_pushButton_clicked();

signals:
    void chat_zamkniety();

private:
    void request_conversationn_list();
    void set_lista_konwersacji();

private:
    Ui::okno_chat *ui;
    Client_manager *_client;
};

#endif // OKNO_CHAT_H
