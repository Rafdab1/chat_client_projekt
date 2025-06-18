QT += core gui network

greaterThan(QT_MAJOR_VERSION,4) : QT += widgets

SOURCES += \
    chatclientwidget.cpp \
    client_manager.cpp \
    funkcje_pomocnicze.cpp \
    konwersacjawidget.cpp \
    logowanie.cpp \
    main.cpp \
    okno_chat.cpp \
    podaj_ip_dialog.cpp \
    tworzenie_konta.cpp

FORMS += \
    chatclientwidget.ui \
    konwersacjawidget.ui \
    logowanie.ui \
    okno_chat.ui \
    podaj_ip_dialog.ui \
    tworzenie_konta.ui

HEADERS += \
    chatclientwidget.h \
    client_manager.h \
    funkcje_pomocnicze.h \
    konwersacjawidget.h \
    logowanie.h \
    okno_chat.h \
    podaj_ip_dialog.h \
    tworzenie_konta.h
