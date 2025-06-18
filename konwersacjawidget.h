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
    explicit konwersacjaWidget(QWidget *parent = nullptr);
    ~konwersacjaWidget();

private:
    Ui::konwersacjaWidget *ui;
};

#endif // KONWERSACJAWIDGET_H
