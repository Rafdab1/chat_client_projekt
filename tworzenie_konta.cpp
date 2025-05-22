#include "tworzenie_konta.h"
#include "ui_tworzenie_konta.h"

Tworzenie_konta::Tworzenie_konta(QHostAddress ip, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Tworzenie_konta),
    _connected(false)
{
    ui->setupUi(this);
    polaczenie = new Client_manager(ip);
    connect(polaczenie,&Client_manager::connected,this,&Tworzenie_konta::on_connection);
    connect(polaczenie,&Client_manager::disconected,this,&Tworzenie_konta::on_disconnect);
    polaczenie->connect_To_Server();
    delay(1);
    if(_connected == false){
        this->close();
        qDebug() <<"Coś innego";
    }
}

Tworzenie_konta::~Tworzenie_konta()
{
    delete polaczenie;
    delete ui;
}

void Tworzenie_konta::on_potwierdz_Button_clicked()
{
    QString message = "";
    message += sformatowany_czas() + ">>" + "Tworzenie konta:";
    QString dane_konta = ui->imie_Edit->text() + "|" + ui->nazwisko_Edit->text() + "|" + ui->email_Edit->text();
    message += dane_konta;
    qDebug()<<message;
    polaczenie  ->sendMessage(message);
}

void Tworzenie_konta::on_connection()
{
    _connected = true;
    qDebug() << "Połączono z serwerm";
}

void Tworzenie_konta::on_disconnect()
{
    _connected = false;
    qDebug() << "Rozłączono z serwerem";
}


