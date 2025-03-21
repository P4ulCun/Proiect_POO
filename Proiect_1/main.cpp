#include <iostream>
#include <cstring>
#include "client.h"
#include "servicii.h"
#include "tranzactii.h"

// mi se strica tot programul daca pun include header files primele si dupa
// include iostream

// cd Desktop\lab_poo\Proiect_POO\Proiect_1 path for files to be compiled
// g++ *.cpp -o output
// output < date.in


// definirea problemei
// sa se afiseze toti clientii care au folosit serviciul de transport acvatic
// sau

// !!!!!
// mai trb sa descriu datele de intrare
// si ce functii am sau sa ma ajute la rezolvarea problemei

// enuntul problemei in mare
// sa se calculeze cel mai profiabil serviciu ; 
// avg ( cati clienti au folosit si cat au platit pentru serviciu )
// si sa se determine care sunt cele mai frecventate luni din an de clienti
// pentru a ajuta agentia de turism sa isi gestioneze mai bine resursele
// aka sa stie pe ce sa sa axeze, sau sa introduca mai multe servicii
// in lunile cele mai frecventate cu servicii ce le aduc cel mai mult profit
// !!!!!

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

    Tranzactii tranzactii(pretBiletAvion, pretVacantaWeekend, pretCityBreak, 
        pretVacantaCroaziera, pretTabaraGhid, dataVacantaWeekend, dataCityBreak, 
        dataVacantaCroaziera, dataTabaraGhide);

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
        tranzactii.setReducere(client);

        addClientInLista(listaClienti, client, servicii, tranzactii);
    }

    afisareListaClienti(listaClienti);

    clearListaClienti(listaClienti);
    return 0;
}