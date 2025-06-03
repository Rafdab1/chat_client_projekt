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
    connect(polaczenie,&Client_manager::dataRecived,this,&Tworzenie_konta::on_odpowiedz_recived);
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
    if(check_password()){
        QString message = "";
        message += sformatowany_czas() + ">>" + "Tworzenie konta" + "<<";
        QString dane_konta = ui->imie_Edit->text() + "|" + ui->nazwisko_Edit->text() + "|" + ui->email_Edit->text() + "|" + ui->haslo_Edit->text();
        message += dane_konta;
        qDebug()<<message;
        polaczenie->sendMessage(message);
    }
    else
        QMessageBox::warning(this,"Tworzenie konta","Podane hasła nie są jednakowe");
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

void Tworzenie_konta::on_odpowiedz_recived(QByteArray data)
{
    QString odpowiedz = QString::fromStdString(data.toStdString());
    if(odpowiedz == "Stworzono konto"){
        QMessageBox::information(this,"Tworzenie konta", "Utworzono konto");
        this->close();
    }
    else if(odpowiedz == "Już isnieje"){
        QMessageBox::information(this,"Tworzenie konta","Konto o podanym emailu już istnieje");
        this->close();
    }
}

bool Tworzenie_konta::check_password()
{
    QString haslo_1 = ui->haslo_Edit->text();
    QString haslo_2 = ui->powtorz_haslo_Edit->text();
    if(haslo_1  == haslo_2)
        return true;
    return false;
}


