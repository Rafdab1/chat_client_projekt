#ifndef OKNO_CHAT_H
#define OKNO_CHAT_H

#include <QMainWindow>
#include "logowanie.h"
#include "client_manager.h"
#include <QDebug>
#include <QTimer>

namespace Ui {
class okno_chat;
}

class okno_chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno_chat(QWidget *parent = nullptr);
    ~okno_chat();
    bool zalogowany;

private slots:
    void setup_read();
    void run_read();

private:
    Ui::okno_chat *ui;
    Client_manager *_client;
};

#endif // OKNO_CHAT_H
