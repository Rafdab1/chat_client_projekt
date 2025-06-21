#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QDialog>
#include <QFile>
#include <QDebug>
#include <QHostAddress>

#include "client_manager.h"
#include "podaj_ip_dialog.h"
#include "tworzenie_konta.h"
#include "funkcje_pomocnicze.h"

namespace Ui {
class Logowanie;
}

class Logowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Logowanie(Client_manager *client,QWidget *parent = nullptr);
    ~Logowanie();

private slots:
    void dodaj_serwer();
    void on_stworz_konto_pushButton_clicked();
    void sprawdz_polaczenie();
    void on_zaloguj_Button_clicked();
    void data_recived(QByteArray data);

signals:
    void send_nazwa(QString nazwa);

private: //metody
    void dodaj_serwer_akcja(QString ip, QString name);
    void set_serwery();
private:
    Ui::Logowanie *ui;
    QHostAddress _adress;
    Client_manager *_client;
};

#endif // LOGOWANIE_H
