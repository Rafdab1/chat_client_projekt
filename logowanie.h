#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QHostAddress>

#include "client_manager.h"
#include "podaj_ip_dialog.h"
#include "tworzenie_konta.h"
#include "funkcje_pomocnicze.h"
#include "okno_chat.h"

namespace Ui {
class Logowanie;
}

class Logowanie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = nullptr);
    ~Logowanie();

private slots:
    void dodaj_serwer();
    void on_stworz_konto_pushButton_clicked();
    void sprawdz_polaczenie();
    void on_zaloguj_Button_clicked();
    void data_recived(QByteArray data);

private: //metody
    void dodaj_serwer_akcja(QString ip, QString name);
    void set_serwery();
private:
    Ui::Logowanie *ui;
    QHostAddress _adress;
    Client_manager *_client;
    okno_chat *_chat;
};

#endif // LOGOWANIE_H
