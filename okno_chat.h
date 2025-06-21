#ifndef OKNO_CHAT_H
#define OKNO_CHAT_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>

#include "logowanie.h"
#include "client_manager.h"
#include "funkcje_pomocnicze.h"
#include "konwersacjawidget.h"

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
    void set_imie_nazwisko(QString nazwa);
    void setup_read(QByteArray data);
    void run_read(QByteArray data);

private:
    void setup_okno();
    void request_konwersacje();
    void setup_konwersacje(QString lista);
private:
    Ui::okno_chat *ui;
    Client_manager *_client;
    QString imie_nazwisko;
};

#endif // OKNO_CHAT_H
