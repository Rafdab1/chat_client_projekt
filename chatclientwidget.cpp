#include "chatclientwidget.h"
#include "ui_chatclientwidget.h"

ChatClientWidget::ChatClientWidget(QString nazwa_konwersacji, QString wiadomosci, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatClientWidget)
    , nazwa_konwersacji(nazwa_konwersacji)
{
    ui->setupUi(this);
    set_messages(wiadomosci);
}

ChatClientWidget::~ChatClientWidget()
{
    delete ui;
}

void ChatClientWidget::set_messages(QString wiadomosci)
{
    QRegularExpression separator("[()]");
    QStringList lista_wiadomosci = wiadomosci.split(separator,Qt::SkipEmptyParts);
    int count = lista_wiadomosci.count();
    for(int i =0 ; i < count ; i++){
        qDebug() << lista_wiadomosci;
    }
}

void ChatClientWidget::on_pushButton_clicked()
{
    QString wiadomosc = ui->lineEdit->text();
    ui->lineEdit->setText("");
    emit(send_message(wiadomosc));
}

