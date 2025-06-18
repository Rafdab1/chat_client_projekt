#include "konwersacjawidget.h"
#include "ui_konwersacjawidget.h"

konwersacjaWidget::konwersacjaWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::konwersacjaWidget)
{
    ui->setupUi(this);
}

konwersacjaWidget::~konwersacjaWidget()
{
    delete ui;
}
