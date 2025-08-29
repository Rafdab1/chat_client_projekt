#ifndef KONWERSACJAWIDGET_H
#define KONWERSACJAWIDGET_H

#include <QWidget>

namespace Ui {
class konwersacjaWidget;
}

class konwersacjaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit konwersacjaWidget(QString &nazwa , QString &ostatnia, QString &tresc,QWidget *parent = nullptr);
    ~konwersacjaWidget();

    QString getNazwa_konwersacji() const;
    void setNazwa_konwersacji(const QString &newNazwa_konwersacji);

    QString getOstatni_wysylajacy() const;
    void setOstatni_wysylajacy(const QString &newOstatni_wysylajacy);

    QString getTresc_wiadomosci() const;
    void setTresc_wiadomosci(const QString &newTresc_wiadomosci);

    void update(QStringList wiadomosc);

private:
    Ui::konwersacjaWidget *ui;
    QString nazwa_konwersacji;
    QString ostatni_wysylajacy;
    QString tresc_wiadomosci;
};

#endif // KONWERSACJAWIDGET_H
