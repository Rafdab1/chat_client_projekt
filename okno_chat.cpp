#include "okno_chat.h"
#include "ui_okno_chat.h"

okno_chat::okno_chat(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::okno_chat)
{
    ui->setupUi(this);
    ui->tabWidget->setTabsClosable(true);
    connect(ui->tabWidget->tabBar(), &QTabBar::tabCloseRequested, this, &okno_chat::on_chat_client_widget_tab_close);
    connect(ui->wyloguj_action, &QAction::triggered, this, &okno_chat::wylogowanie);
    this->setAttribute(Qt::WA_QuitOnClose);

    _client = new Client_manager(QHostAddress::LocalHost);
    setup_logowanie();
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
    QString tresc = QString::fromStdString(data.toStdString()).split(">>")[1];
    if(polecenie == "Lista konwersacji"){
        setup_konwersacje(tresc);
    }else if(polecenie == "Dane konwersacji"){
        open_conversation_window(tresc);
    }else if(polecenie == "Nowa wiadomosc"){
        odbieranie_wiadomosci(tresc);
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

void okno_chat::setup_logowanie()
{
    Logowanie *okno_logowania_dialog = new Logowanie(_client);
    connect(okno_logowania_dialog,&Logowanie::send_nazwa,this,&okno_chat::set_imie_nazwisko);
    switch (okno_logowania_dialog->exec()) {
    case QDialog::Accepted:
        zalogowany = true;
        connect(_client,&Client_manager::dataRecived,this,&okno_chat::setup_read);
        this->show();
        break;
    case QDialog::Rejected:
        break;
    }
    setup_okno();
    delete okno_logowania_dialog;
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
        kon_wig.append(widget);
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
    ChatClientWidget *nowe_okno;
    if(list.size() == 2)
        nowe_okno = new ChatClientWidget(list[0],list[1]);
    else
        nowe_okno = new ChatClientWidget(list[0]);
    connect(nowe_okno,&ChatClientWidget::send_message,this,&okno_chat::wyslij_wiadomosc);
    connect(nowe_okno,&ChatClientWidget::zamkniecie_okna,this,&okno_chat::zamkniecie_okna_chatu);
    int index;
    index = ui->tabWidget->addTab(nowe_okno,list[0]);
    ui->tabWidget->setCurrentIndex(index);
    chat_wig.append(nowe_okno);
    //qDebug() << "Count: " << ui->tabWidget->count();
}

void okno_chat::odbieranie_wiadomosci(QString wiadomosc)
{
    QStringList lista = wiadomosc.split("|");
    qDebug() << lista;
    QString nazwa_konwersacji = lista[0];
    lista.pop_front();
    //otwarty czat
    int count = ui->tabWidget->count();
    for(int i = 0;i < count; i++){
        if(ui->tabWidget->tabText(i) == nazwa_konwersacji){
            for(int j = 0;j < chat_wig.count(); j++){
                if(chat_wig[j]->getNazwa_konwersacji() == nazwa_konwersacji){
                    chat_wig[j]->nowa_wiadomosc(lista);
                    break;
                }
            }
            break;
        }
    }
    //aktualizowanie listy konwersacji
    count = kon_wig.count();
    for(int i = 0; i< count ; i++){
        if(kon_wig[i]->getNazwa_konwersacji() == nazwa_konwersacji){
            kon_wig[i]->update(lista);
            break;
        }
    }
}

void okno_chat::clear_okno()
{
    ui->konwersacje_lista->clear();
    ui->tabWidget->clear();
    open_chats.clear();
    int count = kon_wig.count();
    for(int i = 0;i < count; i++){
        konwersacjaWidget* temp = kon_wig.front();
        kon_wig.pop_front();
        delete temp;
    }
    count = chat_wig.count();
    for(int i =0;i < count;i++){
        ChatClientWidget* temp = chat_wig.front();
        chat_wig.pop_front();
        delete temp;
    }
}


void okno_chat::on_konwersacje_lista_itemClicked(QListWidgetItem *item)
{
    if(open_chats.contains(item->text())){
        int count = ui->tabWidget->count();
        for(int i = 0; i < count; i ++){
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

void okno_chat::wyslij_wiadomosc(QString wiadomosc)
{
    _client->sendMessage(sformatowany_czas() + ">>Wyslana wiadomosc<<" + wiadomosc);
}

void okno_chat::zamkniecie_okna_chatu(ChatClientWidget *addres)
{
    chat_wig.removeOne(addres);
}

void okno_chat::on_Search_edit_textChanged(const QString &arg1)
{
    int count = kon_wig.count();
    for(int i =0;i < count; i++){
        if(!kon_wig[i]->getNazwa_konwersacji().contains(arg1)){
            kon_wig[i]->hide();
        }
        else{
            kon_wig[i]->show();
        }
    }
}

void okno_chat::wylogowanie()
{
    this->hide();
    clear_okno();
    _client->disconect_from_server();
    disconnect(_client, &Client_manager::dataRecived,nullptr,nullptr);
    setup_logowanie();
}

