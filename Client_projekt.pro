QT += core gui network

greaterThan(QT_MAJOR_VERSION,4) : QT += widgets

SOURCES += \
    logowanie.cpp \
    main.cpp \
    podaj_ip_dialog.cpp

FORMS += \
    logowanie.ui \
    podaj_ip_dialog.ui

HEADERS += \
    logowanie.h \
    podaj_ip_dialog.h
