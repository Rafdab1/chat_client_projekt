#ifndef CHATCLIENTWIDGET_H
#define CHATCLIENTWIDGET_H

#include <QWidget>

namespace Ui {
class ChatClientWidget;
}

class ChatClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatClientWidget(QString nazwa_konwersacji = "", QString wiadomosci = "",QWidget *parent = nullptr);
    ~ChatClientWidget();

signals:
    void send_message(QString wiadomosc);

private slots:
    void on_pushButton_clicked();

private:
    void set_messages(QString wiadomosci);
private:
    Ui::ChatClientWidget *ui;
    QString nazwa_konwersacji;
};

#endif // CHATCLIENTWIDGET_H
