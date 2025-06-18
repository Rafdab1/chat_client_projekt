#include "chatclientwidget.h"
#include "ui_chatclientwidget.h"

ChatClientWidget::ChatClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatClientWidget)
{
    ui->setupUi(this);
}

ChatClientWidget::~ChatClientWidget()
{
    delete ui;
}
