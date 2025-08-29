#ifndef CHATCLIENTWIDGET_H
#define CHATCLIENTWIDGET_H

#include <QWidget>

#include "chat_message.h"

namespace Ui {
class ChatClientWidget;
}

class ChatClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClientWidget(QString nazwa_konwersacji = "", QString wiadomosci = "",QString nazwa_uzytkownika = "",QWidget *parent = nullptr);
    ~ChatClientWidget();

    void nowa_wiadomosc(QStringList lista);
    QString getNazwa_konwersacji() const;

signals:
    void send_message(QString wiadomosc);
    void zamkniecie_okna(ChatClientWidget* adres);

private slots:
    void on_pushButton_clicked();

private:
    void set_messages(QString wiadomosci);
private:
    Ui::ChatClientWidget *ui;
    QString nazwa_konwersacji;
    QString nazwa_uzytkonika;
};

#endif // CHATCLIENTWIDGET_H
