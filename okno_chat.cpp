#include "okno_chat.h"
#include "ui_okno_chat.h"

okno_chat::okno_chat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::okno_chat)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose);

    _client = new Client_manager(QHostAddress::LocalHost);
    Logowanie *okno_logowania_dialog = new Logowanie(_client);
    connect(okno_logowania_dialog,&Logowanie::send_nazwa,this,&okno_chat::set_imie_nazwisko);


    switch (okno_logowania_dialog->exec()) {
    case QDialog::Accepted:
        zalogowany = true;
        connect(_client,&Client_manager::dataRecived,this,&okno_chat::setup_read);
        break;
    case QDialog::Rejected:
        _client->disconect_from_server();
        delete _client;
        zalogowany = false;
        break;
    }
    setup_okno();
    delete okno_logowania_dialog;
}

okno_chat::~okno_chat()
{
    _client->disconect_from_server();
    delete _client;
    delete ui;
}

void okno_chat::set_imie_nazwisko(QString nazwa)
{
    imie_nazwisko = nazwa;
}

void okno_chat::setup_read(QByteArray data)
{
    qDebug() << "Setup read: " + data.toStdString();
    QString polecenie = QString::fromStdString(data.toStdString()).split(">>")[0];
    qDebug() << "Polecenie: " + polecenie;
    if(polecenie == "Lista konwersacji"){
        setup_konwersacje(QString::fromStdString(data.toStdString()).split(">>")[1]);
    }
}

void okno_chat::run_read(QByteArray data)
{
    qDebug() << "Run read: " + data.toStdString();
}

void okno_chat::setup_okno()
{
    ui->nazwa_konta_lable->setText(imie_nazwisko);
    request_konwersacje();
}

void okno_chat::request_konwersacje()
{
    _client->sendMessage( sformatowany_czas() + ">>Lista konwersacji<<" );
}

void okno_chat::setup_konwersacje(QString lista)
{
    qDebug() << lista;
    QRegularExpression separator("[()]");
    QStringList konwersacje = lista.split(separator,Qt::SkipEmptyParts);
    for(int i =0; i < konwersacje.size(); i++){
        QStringList dane_konwersacji = konwersacje[i].split("|");
        konwersacjaWidget *widget = new konwersacjaWidget(dane_konwersacji[0],dane_konwersacji[1],dane_konwersacji[2],this);
        auto listwidgetitem = new QListWidgetItem();
        listwidgetitem->setSizeHint(QSize(0,65));
        ui->konwersacje_lista->addItem(listwidgetitem);
        ui->konwersacje_lista->setItemWidget(listwidgetitem,widget);
    }
}

