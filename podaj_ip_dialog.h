#ifndef PODAJ_IP_DIALOG_H
#define PODAJ_IP_DIALOG_H

#include <QDialog>
#include <QHostAddress>
#include <QStyle>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Podaj_ip_dialog;
}

class Podaj_ip_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Podaj_ip_dialog(QWidget *parent = nullptr);
    ~Podaj_ip_dialog();
    QList<QString> podane_dane();

private slots:
    void on_pushButton_clicked();

    void on_ip_Edit_textChanged(const QString &arg1);

    void on_nazwa_serwera_Edit_textChanged(const QString &arg1);

private:
    bool server_in_file(QString &ip,QString &name);

private:
    QString _ip;
    QString _nazwa_serwera;
    Ui::Podaj_ip_dialog *ui;
};

#endif // PODAJ_IP_DIALOG_H
