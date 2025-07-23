#include "chatclientwidget.h"
#include "ui_chatclientwidget.h"

ChatClientWidget::ChatClientWidget(QString nazwa_konwersacji, QString wiadomosci, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatClientWidget)
    , nazwa_konwersacji(nazwa_konwersacji)
{
    ui->setupUi(this);
}

ChatClientWidget::~ChatClientWidget()
{
    delete ui;
}
