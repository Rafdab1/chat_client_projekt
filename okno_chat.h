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
    void wyslij_wiadomosc(QString wiadomosc);
    void zamkniecie_okna_chatu(ChatClientWidget* addres);
    void on_Search_edit_textChanged(const QString &arg1);
    void wylogowanie();

private:
    void setup_okno();
    void setup_logowanie();
    void request_konwersacje();
    void setup_konwersacje(QString lista);
    void request_konwersacja_data(QString nazwa_konwersacji);
    void open_conversation_window(QString dane);
    void odbieranie_wiadomosci(QString wiadomosc);
    void clear_okno();
private:
    Ui::okno_chat *ui;
    Client_manager *_client;
    QString imie_nazwisko;
    QStringList open_chats;
    QList<konwersacjaWidget*> kon_wig;
    QList<ChatClientWidget*> chat_wig;
};

#endif // OKNO_CHAT_H
