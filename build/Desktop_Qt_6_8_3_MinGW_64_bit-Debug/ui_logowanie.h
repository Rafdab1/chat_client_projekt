/********************************************************************************
** Form generated from reading UI file 'logowanie.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGOWANIE_H
#define UI_LOGOWANIE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logowanie
{
public:
    QAction *actionSprawdz_Po_czenie;
    QAction *actionDodaj_Serwer;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *haslo_label;
    QLineEdit *lineEdit_2;
    QPushButton *stworz_konto_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *zaloguj_Button;
    QMenuBar *menubar;
    QMenu *opcje_menu;
    QMenu *menuWybor_Serwera;

    void setupUi(QMainWindow *Logowanie)
    {
        if (Logowanie->objectName().isEmpty())
            Logowanie->setObjectName("Logowanie");
        Logowanie->resize(397, 210);
        actionSprawdz_Po_czenie = new QAction(Logowanie);
        actionSprawdz_Po_czenie->setObjectName("actionSprawdz_Po_czenie");
        actionDodaj_Serwer = new QAction(Logowanie);
        actionDodaj_Serwer->setObjectName("actionDodaj_Serwer");
        centralwidget = new QWidget(Logowanie);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        haslo_label = new QLabel(groupBox);
        haslo_label->setObjectName("haslo_label");

        horizontalLayout_2->addWidget(haslo_label);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);

        stworz_konto_pushButton = new QPushButton(groupBox);
        stworz_konto_pushButton->setObjectName("stworz_konto_pushButton");

        gridLayout->addWidget(stworz_konto_pushButton, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(291, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        zaloguj_Button = new QPushButton(groupBox);
        zaloguj_Button->setObjectName("zaloguj_Button");

        gridLayout->addWidget(zaloguj_Button, 1, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        Logowanie->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Logowanie);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 397, 21));
        opcje_menu = new QMenu(menubar);
        opcje_menu->setObjectName("opcje_menu");
        menuWybor_Serwera = new QMenu(opcje_menu);
        menuWybor_Serwera->setObjectName("menuWybor_Serwera");
        Logowanie->setMenuBar(menubar);

        menubar->addAction(opcje_menu->menuAction());
        opcje_menu->addAction(menuWybor_Serwera->menuAction());
        opcje_menu->addAction(actionSprawdz_Po_czenie);
        menuWybor_Serwera->addAction(actionDodaj_Serwer);

        retranslateUi(Logowanie);

        QMetaObject::connectSlotsByName(Logowanie);
    } // setupUi

    void retranslateUi(QMainWindow *Logowanie)
    {
        Logowanie->setWindowTitle(QCoreApplication::translate("Logowanie", "Logowanie", nullptr));
        actionSprawdz_Po_czenie->setText(QCoreApplication::translate("Logowanie", "Sprawdz Po\305\202\304\205czenie", nullptr));
        actionDodaj_Serwer->setText(QCoreApplication::translate("Logowanie", "Dodaj Serwer", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Logowanie", "Email:", nullptr));
        haslo_label->setText(QCoreApplication::translate("Logowanie", "Has\305\202o:", nullptr));
        stworz_konto_pushButton->setText(QCoreApplication::translate("Logowanie", "Stw\303\263rz konto", nullptr));
        zaloguj_Button->setText(QCoreApplication::translate("Logowanie", "Zaloguj", nullptr));
        opcje_menu->setTitle(QCoreApplication::translate("Logowanie", "opcje", nullptr));
        menuWybor_Serwera->setTitle(QCoreApplication::translate("Logowanie", "Wyb\303\263r Serwera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Logowanie: public Ui_Logowanie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGOWANIE_H
