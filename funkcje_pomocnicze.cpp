#include "funkcje_pomocnicze.h"

QString sformatowany_czas()
{
    QString sformatowany_czas = '[' +QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") + ']';
    return sformatowany_czas;
}

void delay(int sec)
{
    QTime dieTime = QTime::currentTime().addMSecs(sec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
