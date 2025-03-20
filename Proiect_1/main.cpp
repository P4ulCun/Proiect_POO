#include <iostream>
#include <cstring>
#include "client.h"
#include "servicii.h"
#include "tranzactii.h"

// cd Desktop\lab_poo\Proiect_POO\Proiect_1 path for files to be compiled
// g++ *.cpp -o output
// output < date.in


// definirea problemei
// sa se afiseze toti clientii care au folosit serviciul de transport acvatic
// sau
// sa se calculeze cel mai profiabil serviciu ; avg ( cati clienti au folosit si cat au platit pentru serviciu )

// sa se afiseze toate servicile solicitate de un anumit client

struct dateClient{
    Client client;
    Servicii servicii;
    Tranzactii tranzactii;
    dateClient *urmClient;

    dateClient(Client clientNou, Servicii serviciiNoi, Tranzactii tranzactiiNoi) : client(clientNou), 
    servicii(serviciiNoi), tranzactii(tranzactiiNoi), urmClient(nullptr) {}
    // constructor pentru struct
};

void addClientInLista (dateClient*& lista, Client& client, Servicii& servicii, Tranzactii& tranzactii){
    dateClient *clientNou = new dateClient(client, servicii, tranzactii); // apelez constructorul

    clientNou -> urmClient = lista;
    lista = clientNou;
}

void afisareListaClienti (dateClient* lista){
    dateClient *clientCurent;
    for (clientCurent = lista; clientCurent != NULL; clientCurent = clientCurent -> urmClient){
        std::cout << clientCurent -> client << '\n';
        std::cout << clientCurent -> servicii << '\n';
        std::cout << clientCurent -> tranzactii << '\n';
        std::cout << '\n';
    }
}

void clearListaClienti (dateClient* lista){
    dateClient *clientCurent, *clientUrm;
    for (clientCurent = lista; clientCurent != NULL; clientCurent = clientUrm -> urmClient){
        clientUrm = clientCurent;

        delete[] clientCurent;
    }
}

Client citesteClient (){
    char nume[50];
    std::cin.getline(nume, 50);
    char prenume[50];
    std::cin.getline(prenume, 50);
    char email[50];
    std::cin.getline(email, 50);
    char telefon[50];
    std::cin.getline(telefon, 50);
    int nivelFidelitate;
    std::cin >> nivelFidelitate;

    Client client(nume, prenume, email, telefon, nivelFidelitate);

    std::cin.getline(nume, 50); // este pentru \n ramas la sfarsitul intului

    return client;
}

Servicii citesteServicii (){
    char biletAvion[50];
    std::cin.getline(biletAvion, 50);
    char vacantaWeekend[50];
    std::cin.getline(vacantaWeekend, 50);
    char cityBreak[50];
    std::cin.getline(cityBreak, 50);
    char vacantaCroaziera[50];
    std::cin.getline(vacantaCroaziera, 50);
    char tabaraGhid[50];
    std::cin.getline(tabaraGhid, 50);

    Servicii servicii(biletAvion, vacantaWeekend, cityBreak, vacantaCroaziera, tabaraGhid);

    return servicii;
}

Tranzactii citesteTranzactii (){
    int pretBiletAvion;
    std::cin >> pretBiletAvion;
    int pretVacantaWeekend;
    std::cin >> pretVacantaWeekend;
    int pretCityBreak;
    std::cin >> pretCityBreak;
    int pretVacantaCroaziera;
    std::cin >> pretVacantaCroaziera;
    int pretTabaraGhid;
    std::cin >> pretTabaraGhid;

    char dataVacantaWeekend[50];
    std::cin.getline(dataVacantaWeekend, 50); // pentru terminator la int
    std::cin.getline(dataVacantaWeekend, 50);
    char dataCityBreak[50];
    std::cin.getline(dataCityBreak, 50);
    char dataVacantaCroaziera[50];
    std::cin.getline(dataVacantaCroaziera, 50);
    char dataTabaraGhide[50];
    std::cin.getline(dataTabaraGhide, 50);

    Tranzactii tranzactii(pretBiletAvion, pretVacantaWeekend, pretCityBreak, pretVacantaCroaziera, pretTabaraGhid, 
        dataVacantaWeekend, dataCityBreak, dataVacantaCroaziera, dataTabaraGhide);

    return tranzactii;
}

int main (){
    dateClient *listaClienti = NULL;

    int nrClienti = 0, i = 0;
    char temp[10];
    std::cin >> nrClienti;
    std::cin.getline(temp, 10); // ca sa iau endl de la sfarsitul int-ului
    for (i = 0; i < nrClienti; i++){
        Client client = citesteClient();
        Servicii servicii = citesteServicii();
        Tranzactii tranzactii = citesteTranzactii();

        addClientInLista(listaClienti, client, servicii, tranzactii);
    }

    afisareListaClienti(listaClienti);

    clearListaClienti(listaClienti);
    // Client client1("cunt", "paul");
    // Client client = Client("sal");
    // client1.setFidelitate(3);
    // std::cout << client << '\n';

    // Client client2 = client1;
    // client2.setEmail("yoskibi@outlook.dop");
    // client2.setTelefon("075924000000");
    // std::cout << client2 << '\n';
    
    // Client client3("salut", "skibi", "yahoo_mail@.com", "+40716716831");
    // std::cout << client3 << '\n';

    // Client client4 = Client(client3);
    // std::cout << client4 << '\n';

    // Servicii serviciu("avion", "weekend", "city");
    // serviciu.setVacantaWeekend("Roma");
    // serviciu.setTabaraGhid("drumetie");
    // std::cout << serviciu << '\n';

    // Client client6;
    // std::cout << client6 << '\n';

    // Tranzactii tranzactie1(1000, 2000);
    // tranzactie1.setReducere(client1);

    // std::cout << tranzactie1 << '\n';
    return 0;
}