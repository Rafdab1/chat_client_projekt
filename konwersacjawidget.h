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

private:
    Ui::konwersacjaWidget *ui;
    QString nazwa_konwersacji;
    QString ostatni_wysylajacy;
    QString tresc_wiadomosci;
};

#endif // KONWERSACJAWIDGET_H
