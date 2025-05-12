#ifndef TWORZENIE_KONTA_H
#define TWORZENIE_KONTA_H

#include <QDialog>
#include <QDateTime>
#include <QDebug>
#include "funkcje_pomocnicze.h"
#include "client_manager.h"

namespace Ui {
class Tworzenie_konta;
}

class Tworzenie_konta : public QDialog
{
    Q_OBJECT

public:
    explicit Tworzenie_konta(QHostAddress ip,QWidget *parent = nullptr);
    ~Tworzenie_konta();
    bool _connected;
private slots:
    void on_potwierdz_Button_clicked();
    void on_connection();
    void on_disconnect();

private:
    Ui::Tworzenie_konta *ui;
    Client_manager *polaczenie;
};

#endif // TWORZENIE_KONTA_H
