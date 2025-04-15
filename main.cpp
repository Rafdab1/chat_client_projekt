#include <QApplication>
#include "logowanie.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    Logowanie start;
    start.show();
    start.setFixedSize(start.size());
    return app.exec();
}
