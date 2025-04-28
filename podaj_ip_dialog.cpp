#include "podaj_ip_dialog.h"
#include "ui_podaj_ip_dialog.h"

Podaj_ip_dialog::Podaj_ip_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Podaj_ip_dialog)
{
    ui->setupUi(this);
    ui->ip_Edit->setInputMask("000.000.000.000;_");
    ui->pushButton->setDisabled(true);
}

Podaj_ip_dialog::~Podaj_ip_dialog()
{
    delete ui;
}

QList<QString> Podaj_ip_dialog::podane_dane()
{
    QList<QString> lista;
    lista.append(_ip);
    lista.append(_nazwa_serwera);
    return lista;
}

void Podaj_ip_dialog::on_pushButton_clicked(){
    _ip = ui->ip_Edit->text();
    _nazwa_serwera = ui->nazwa_serwera_Edit->text();
    if(!server_in_file(_ip,_nazwa_serwera)){
        QString filename = "serwery.txt";
        QFile file(filename);
        file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);{
            QTextStream linia(&file);
            linia << '\n'<< _ip << "|" <<_nazwa_serwera;
        }
        file.close();
    }
}

void Podaj_ip_dialog::on_ip_Edit_textChanged(const QString &arg1)
{
    QHostAddress adress(arg1);
    QString state = "";
    if(arg1 != "..."){
        if(QAbstractSocket::IPv4Protocol == adress.protocol()){
            state = "1";
            if(ui->nazwa_serwera_Edit->text() != "")
                ui->pushButton->setEnabled(true);
        }
        else{
            state = "0";
            ui->pushButton->setDisabled(true);
        }
    }
    ui->ip_Edit->setProperty("state",state);
    style()->polish(ui->ip_Edit);
}


void Podaj_ip_dialog::on_nazwa_serwera_Edit_textChanged(const QString &arg1)
{
    if(arg1 == ""){
        ui->pushButton->setDisabled(true);
    }
    else
        if(ui->ip_Edit->property("state") == "1")
            ui->pushButton->setEnabled(true);
}

bool Podaj_ip_dialog::server_in_file(QString &ip, QString &name)
{
    QString filename = "serwery.txt";
    QFile plik(filename);
    plik.open(QIODevice::ReadOnly);

    QString linia;
    QTextStream stream(&plik);
    while(stream.atEnd() == false){
        linia = stream.readLine();
        QList<QString> lista = linia.split("|");
        if( ip == lista[0]){
            plik.close();
            QString return_string = "Serwer o podanym ip już istniej pod nazwą " + lista[1];
            QMessageBox::information(this,"Dodawanie serwera",return_string);
            return true;
        }
        if(name == lista[1]){
            plik.close();
            QString return_string = "Serwer o podanym nazwie już istniej: " + lista[1];
            QMessageBox::information(this,"Dodawanie serwera",return_string);
            return true;
        }
    }
    plik.close();
    return false;
}

