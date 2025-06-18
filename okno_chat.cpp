#include "okno_chat.h"
#include "ui_okno_chat.h"

okno_chat::okno_chat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::okno_chat)
{
    ui->setupUi(this);
    _client = new Client_manager(QHostAddress::LocalHost);
    this->setAttribute(Qt::WA_QuitOnClose);
    Logowanie *okno_logowania_dialog = new Logowanie(_client);
    switch (okno_logowania_dialog->exec()) {
    case QDialog::Accepted:
        zalogowany = true;
        break;
    case QDialog::Rejected:
        zalogowany = false;
        break;
    }
    delete okno_logowania_dialog;
}



okno_chat::~okno_chat()
{
    _client->disconect_from_server();
    qDebug() << "dupa chat_okno";
    delete _client;
    delete ui;
}

void okno_chat::setup_read()
{

}

void okno_chat::run_read()
{

}
