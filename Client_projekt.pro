QT += core gui network

greaterThan(QT_MAJOR_VERSION,4) : QT += widgets

SOURCES += \
    client_manager.cpp \
    funkcje_pomocnicze.cpp \
    logowanie.cpp \
    main.cpp \
    podaj_ip_dialog.cpp \
    tworzenie_konta.cpp

FORMS += \
    logowanie.ui \
    podaj_ip_dialog.ui \
    tworzenie_konta.ui

HEADERS += \
    client_manager.h \
    funkcje_pomocnicze.h \
    logowanie.h \
    podaj_ip_dialog.h \
    tworzenie_konta.h
