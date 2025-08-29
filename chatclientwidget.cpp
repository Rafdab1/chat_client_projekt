#include "chatclientwidget.h"
#include "ui_chatclientwidget.h"

ChatClientWidget::ChatClientWidget(QString nazwa_konwersacji, QString wiadomosci,QString nazwa_uzytkownika, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatClientWidget)
    , nazwa_konwersacji(nazwa_konwersacji)
    , nazwa_uzytkonika(nazwa_uzytkownika)
{
    ui->setupUi(this);
    set_messages(wiadomosci);
}

ChatClientWidget::~ChatClientWidget()
{
    delete ui;
    emit zamkniecie_okna(this);
}

void ChatClientWidget::nowa_wiadomosc(QStringList lista)
{
    chat_message *message = new chat_message(this);
    QString wiadomosc = lista.join("|");
    message->set_message(wiadomosc,nazwa_uzytkonika);
    QListWidgetItem *item = new QListWidgetItem();
    item->setSizeHint(QSize(0,65));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,message);
}

void ChatClientWidget::set_messages(QString wiadomosci)
{
    QRegularExpression separator("[()]");
    QStringList lista_wiadomosci = wiadomosci.split(separator,Qt::SkipEmptyParts);
    int count = lista_wiadomosci.count();
    for(int i =0 ; i < count ; i++){
        chat_message *message = new chat_message(this);
        message->set_message(lista_wiadomosci[i],nazwa_uzytkonika);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(0,65));
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,message);
    }
}

QString ChatClientWidget::getNazwa_konwersacji() const
{
    return nazwa_konwersacji;
}

void ChatClientWidget::on_pushButton_clicked()
{
    QString wiadomosc = nazwa_konwersacji + "|" +  ui->lineEdit->text();
    ui->lineEdit->setText("");
    emit send_message(wiadomosc);
}

