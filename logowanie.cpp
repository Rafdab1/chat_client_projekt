#include "logowanie.h"
#include "ui_logowanie.h"

Logowanie::Logowanie(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Logowanie)
{
    ui->setupUi(this);
    set_serwery();
    connect(ui->actionDodaj_Serwer,&QAction::triggered,this,&Logowanie::dodaj_serwer);
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::set_adress(QList<QString> lista)
{
    _adress.setAddress(lista[1]);
    qDebug() << _adress.toString().toUtf8();
}

void Logowanie::dodaj_serwer()
{
    Podaj_ip_dialog *dialog = new Podaj_ip_dialog(this);
    dialog->exec(); //pozyskanie danych od
    QList<QString> lista = dialog->podane_dane();
    if(!lista.empty()){
        dodaj_serwer_akcja(lista[0],lista[1]);
    }
    delete dialog;
}

void Logowanie::dodaj_serwer_akcja(QString ip, QString name)
{
    QAction *Serwer = ui->menuWybor_Serwera->addAction(name);
    Serwer->setProperty("Adress",ip);
    connect(Serwer,&QAction::triggered,this,[this,Serwer](){
        _adress.setAddress(Serwer->property("Adress").toString());
        ui->server_name_label->setText(Serwer->text());
        // qDebug() << Serwer->property("Adress").toString();
        // qDebug() << _adress.toString();
    });
}

void Logowanie::set_serwery()
{
    QString filename = "Serwery.txt";
    QFile file(filename);
    //otwarcie pliku
    if(!file.exists()){
        qDebug() << "Plik " << filename << "Nie istnieje";
        if(file.open(QIODevice::Append)){
            qDebug() << "Stworzono plik " << filename;
        }
        else
            qDebug() << "Błąd podczas tworzenie pliku " << filename;
    }
    else{
        if(file.open(QIODevice::ReadOnly)){
            qDebug() << "Pomyślnie otwarto plik" << filename;
        }
        else
            qDebug() << "Błąd podczas otwierania pliku" << filename;
    }
    //zczytywanie listy serwerów
    QString linia;
    QTextStream stream(&file);
    while(stream.atEnd() == false){
        linia = stream.readLine(); // nazwa_serwera | ip | port
        QList<QString> lista = linia.split("|");
        // for(int i = 0; i < lista.size(); i++){
        //     qDebug() << lista[i];
        // }
        dodaj_serwer_akcja(lista[0],lista[1]);
    }
    file.close();
}
