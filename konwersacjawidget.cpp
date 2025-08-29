#include "konwersacjawidget.h"
#include "ui_konwersacjawidget.h"

konwersacjaWidget::konwersacjaWidget(QString &nazwa, QString &ostatnia, QString &tresc, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::konwersacjaWidget)
    , nazwa_konwersacji(nazwa)
    , ostatni_wysylajacy(ostatnia)
    , tresc_wiadomosci(tresc)
{
    ui->setupUi(this);
    ui->nazwaKonwersacji_label->setText(nazwa);
    ui->wysylajacy_label->setText(ostatni_wysylajacy);
    ui->trescWiadomosci_label->setText(tresc_wiadomosci);
}

konwersacjaWidget::~konwersacjaWidget()
{
    delete ui;
}

QString konwersacjaWidget::getNazwa_konwersacji() const
{
    return nazwa_konwersacji;
}

void konwersacjaWidget::setNazwa_konwersacji(const QString &newNazwa_konwersacji)
{
    nazwa_konwersacji = newNazwa_konwersacji;
}

QString konwersacjaWidget::getOstatni_wysylajacy() const
{
    return ostatni_wysylajacy;
}

void konwersacjaWidget::setOstatni_wysylajacy(const QString &newOstatni_wysylajacy)
{
    ostatni_wysylajacy = newOstatni_wysylajacy;
}

QString konwersacjaWidget::getTresc_wiadomosci() const
{
    return tresc_wiadomosci;
}

void konwersacjaWidget::setTresc_wiadomosci(const QString &newTresc_wiadomosci)
{
    tresc_wiadomosci = newTresc_wiadomosci;
}

void konwersacjaWidget::update(QStringList wiadomosc)
{
    ui->wysylajacy_label->setText(wiadomosc[1]);
    ui->trescWiadomosci_label->setText(wiadomosc[2]);
}
