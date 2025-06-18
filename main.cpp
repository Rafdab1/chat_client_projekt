#include <QApplication>
#include "okno_chat.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    app.setQuitOnLastWindowClosed(true);
    okno_chat *start = new okno_chat();
    start->setFixedSize(start->size());
    if(start->zalogowany == false)
        return 0;
    else
        start->show();
    return app.exec();
}
