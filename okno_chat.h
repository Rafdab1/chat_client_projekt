#ifndef OKNO_CHAT_H
#define OKNO_CHAT_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QListWidgetItem>
#include <QStringList>

#include "logowanie.h"
#include "client_manager.h"
#include "funkcje_pomocnicze.h"
#include "konwersacjawidget.h"
#include "chatclientwidget.h"

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
    void on_konwersacje_lista_itemClicked(QListWidgetItem *item);
    void on_chat_client_widget_tab_close(int index);

    void on_tabWidget_currentChanged(int index);

private:
    void setup_okno();
    void request_konwersacje();
    void setup_konwersacje(QString lista);
    void request_konwersacja_data(QString nazwa_konwersacji);
    void open_conversation_window(QString dane);
private:
    Ui::okno_chat *ui;
    Client_manager *_client;
    QString imie_nazwisko;
    QStringList open_chats;
};

#endif // OKNO_CHAT_H
