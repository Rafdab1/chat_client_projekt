#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include <QWidget>

namespace Ui {
class chat_message;
}

class chat_message : public QWidget
{
    Q_OBJECT

public:
    explicit chat_message(QWidget *parent = nullptr);
    ~chat_message();

    void set_message(QString wiadomosc, QString &nazwa_uzytkownika);

private:
    Ui::chat_message *ui;
};

#endif // CHAT_MESSAGE_H
