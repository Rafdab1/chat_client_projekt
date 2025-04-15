#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QHostAddress>

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
    void set_adress(QList<QString> lista);

private: //metody
    void set_serwery();
    void dodaj_serwer();

private:
    Ui::Logowanie *ui;
    QHostAddress _adress;
};

#endif // LOGOWANIE_H
