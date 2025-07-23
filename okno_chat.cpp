#include "okno_chat.h"
#include "ui_okno_chat.h"

okno_chat::okno_chat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::okno_chat)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);
    connect(ui->tabWidget->tabBar(), &QTabBar::tabCloseRequested, this, &okno_chat::on_chat_client_widget_tab_close);
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
    //qDebug() << "Setup read: " + data.toStdString();
    QString polecenie = QString::fromStdString(data.toStdString()).split(">>")[0];
    //qDebug() << "Polecenie: " + polecenie;
    if(polecenie == "Lista konwersacji"){
        setup_konwersacje(QString::fromStdString(data.toStdString()).split(">>")[1]);
    }else if(polecenie == "Dane konwersacji"){
        open_conversation_window(QString::fromStdString(data.toStdString()).split(">>")[1]);
    }
}

void okno_chat::run_read(QByteArray data)
{
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
    QRegularExpression separator("[()]");
    QStringList konwersacje = lista.split(separator,Qt::SkipEmptyParts);
    for(int i =0; i < konwersacje.size(); i++){
        QStringList dane_konwersacji = konwersacje[i].split("|");
        konwersacjaWidget *widget = new konwersacjaWidget(dane_konwersacji[0],dane_konwersacji[1],dane_konwersacji[2],this);
        widget->setProperty("nazwa konwersacji",dane_konwersacji[0]);
        auto listwidgetitem = new QListWidgetItem();
        listwidgetitem->setText(dane_konwersacji[0]);
        listwidgetitem->setSizeHint(QSize(0,65));
        ui->konwersacje_lista->addItem(listwidgetitem);
        ui->konwersacje_lista->setItemWidget(listwidgetitem,widget);
    }
}

void okno_chat::request_konwersacja_data(QString nazwa_konwersacji)
{
    _client->sendMessage(sformatowany_czas() + ">>Dane konwersacji<<" + nazwa_konwersacji);
}

void okno_chat::open_conversation_window(QString dane)
{
    QStringList list = dane.split("<<");
    open_chats.append(list[0]);
    ChatClientWidget *widget;
    if(list.size() == 2){
        widget = new ChatClientWidget(list[0],list[0]);
    }
    else
        widget = new ChatClientWidget(list[0]);
    int index;
    index = ui->tabWidget->addTab(widget,list[0]);
    ui->tabWidget->setCurrentIndex(index);

    //qDebug() << "Count: " << ui->tabWidget->count();
}


void okno_chat::on_konwersacje_lista_itemClicked(QListWidgetItem *item)
{
    if(open_chats.contains(item->text())){
        int count = ui->tabWidget->count();
        for(int i = 0; i < count; i ++){
            qDebug() << ui->tabWidget->tabText(i) << item->text();
            if(ui->tabWidget->tabText(i) == item->text()){
                ui->tabWidget->setCurrentIndex(i);
                break;
            }
        }
    }
    else
        request_konwersacja_data(item->text());
}

void okno_chat::on_chat_client_widget_tab_close(int index)
{
    open_chats.removeAt(open_chats.indexOf(ui->tabWidget->tabText(index)));
    ui->tabWidget->removeTab(index);
    ui->tabWidget->setCurrentIndex(-1);

}

void okno_chat::on_tabWidget_currentChanged(int index)
{
    //qDebug() << "Current index:" << index;
}

