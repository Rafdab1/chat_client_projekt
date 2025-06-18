#include <QApplication>
#include "logowanie.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    Logowanie start;
    start.setFixedSize(start.size());
    start.show();
    return app.exec();
}
