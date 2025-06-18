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
    explicit ChatClientWidget(QWidget *parent = nullptr);
    ~ChatClientWidget();

private:
    Ui::ChatClientWidget *ui;
};

#endif // CHATCLIENTWIDGET_H
