#include "okno_chat.h"
#include "ui_okno_chat.h"

okno_chat::okno_chat(Client_manager *client, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::okno_chat)
{
    ui->setupUi(this);
    _client = client;
    connect(_client,&Client_manager::dataRecived,this,&okno_chat::setup_read);
    connect(_client,&Client_manager::dataRecived,this,&okno_chat::running_read);
    _client->check_data_recived_recivers();
    request_conversationn_list();
    this->dumpObjectInfo();
}

okno_chat::~okno_chat()
{
    qDebug() << "chat dupa";
    delete ui;
}

void okno_chat::setup_read(QByteArray data)
{
    qDebug() << "debug";
    QString dane = QString::fromStdString(data.toStdString());
    qDebug() << dane;
}

void okno_chat::running_read(QByteArray data)
{
    qDebug() << data.toStdString();
}

void okno_chat::request_conversationn_list()
{
    QString message = sformatowany_czas() +">>Lista konwersacji<<";
    _client->sendMessage(message);
    _client->wait_for_responce(30000);
}


void okno_chat::on_pushButton_clicked()
{
    qDebug() << _client->read_data().toStdString();
}

