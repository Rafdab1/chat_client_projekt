#include "chat_message.h"
#include "ui_chat_message.h"

chat_message::chat_message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chat_message)
{
    ui->setupUi(this);
}

chat_message::~chat_message()
{
    delete ui;
}

void chat_message::set_message(QString wiadomosc, QString &nazwa_uzytkownika)
{
    QStringList lista = wiadomosc.split("|");
    ui->czas_label->setText(lista[0]);
    ui->nazwa_uzytkownika_label->setText(lista[1]);
    if(lista[1] == nazwa_uzytkownika)
        ui->tresc_label->setAlignment(Qt::AlignRight);
    ui->tresc_label->setText(lista[2]);
}
