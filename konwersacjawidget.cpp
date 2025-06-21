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
