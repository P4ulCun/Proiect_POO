// comenzi run
// g++ *.cpp -o output
// output.exe

// ENUNTUL PROBLEMEI
// O agentie de turism doreste sa isi optimizeze resursele si sa isi imbunatateasca
// oferta de servicii, analizand comportamentul si preferintele clientilor sai. 
// Pentru aceasta, trebuie realizata o analiza a datelor despre clienti, reducerile
// aplicate si popularitatea serviciilor oferite.

// CERINTE
// 1. Afisarea tuturor clientilor impreuna cu datele lor relevante, inclusiv preturile
// finale platite dupa aplicarea reducerilor in functie de nivelul de fidelitate.

// 2. Determinarea serviciului cel mai profitabil, adica acel serviciu care a generat
// cel mai mare venit total.

// 3.Identificarea celor mai frecventate luni din an, in functie de numarul de clienti
// care au achizitionat servicii in fiecare luna.

// DATE DE INTRARE
// Datele vor fi citite din fisier
// Se vor introduce date despre client, servicile cerute de client si tranzactile,
// cate o informatie pe rand si fara linii goale, dupa modelul si formatul precizat
// in fisierul boilerplate.in. Datele dintre 2 clienti nu vor fi separate 
// printr-o linie goala!!

// DATE DE IESIRE
// 1. Lista clientilor cu datele lor si costurile finale platite dupa aplicarea reducerilor.
// 2. Cel mai profitabil serviciu, cu cel mai mare venit total.
// 3. Cele mai frecventate luni, lunile cu cel mai mare numar de achizitii.

#include <iostream>
#include <cstring>
#include <fstream>
#include "client.h"
#include "servicii.h"
#include "tranzactii.h"
// mi se strica tot programul daca pun include header files primele
// si dupa include iostream

std::ifstream file;

// citire si memorare date:

struct dateClient{
    Client client;
    Servicii servicii;
    Tranzactii tranzactii;
    dateClient *urmClient;

    dateClient(Client clientNou, Servicii serviciiNoi, Tranzactii tranzactiiNoi) : client(clientNou), 
    servicii(serviciiNoi), tranzactii(tranzactiiNoi), urmClient(nullptr) {}
    // constructor pentru struct
};

// inserare eficienta in lista
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
        std::cout << "--------------------------------------------------\n";
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
    file.getline(nume, 50);
    char prenume[50];
    file.getline(prenume, 50);
    char email[50];
    file.getline(email, 50);
    char telefon[50];
    file.getline(telefon, 50);
    int nivelFidelitate;
    file >> nivelFidelitate;

    Client client(nume, prenume, email, telefon, nivelFidelitate);

    file.getline(nume, 50); // este pentru \n ramas la sfarsitul intului

    return client;
}

Servicii citesteServicii (){
    char biletAvion[50];
    file.getline(biletAvion, 50);
    char vacantaWeekend[50];
    file.getline(vacantaWeekend, 50);
    char cityBreak[50];
    file.getline(cityBreak, 50);
    char vacantaCroaziera[50];
    file.getline(vacantaCroaziera, 50);
    char tabaraGhid[50];
    file.getline(tabaraGhid, 50);

    Servicii servicii(biletAvion, vacantaWeekend, cityBreak, vacantaCroaziera, tabaraGhid);

    return servicii;
}

Tranzactii citesteTranzactii (){
    int pretBiletAvion;
    file >> pretBiletAvion;
    int pretVacantaWeekend;
    file >> pretVacantaWeekend;
    int pretCityBreak;
    file >> pretCityBreak;
    int pretVacantaCroaziera;
    file >> pretVacantaCroaziera;
    int pretTabaraGhid;
    file >> pretTabaraGhid;

    char dataVacantaWeekend[50];
    file.getline(dataVacantaWeekend, 50); // pentru terminator la int
    file.getline(dataVacantaWeekend, 50);
    char dataCityBreak[50];
    file.getline(dataCityBreak, 50);
    char dataVacantaCroaziera[50];
    file.getline(dataVacantaCroaziera, 50);
    char dataTabaraGhide[50];
    file.getline(dataTabaraGhide, 50);

    Tranzactii tranzactii(pretBiletAvion, pretVacantaWeekend, pretCityBreak, 
        pretVacantaCroaziera, pretTabaraGhid, dataVacantaWeekend, dataCityBreak, 
        dataVacantaCroaziera, dataTabaraGhide);

    return tranzactii;
}

char* afisareMonth(int month){
    char *luna = new char[12];
    switch (month){
        case 1:
            strcpy(luna, "IANUARIE");
            break;
        case 2:
            strcpy(luna, "FEBRUARIE");
            break;
        case 3:
            strcpy(luna, "MARTIE");
            break;
        case 4:
            strcpy(luna, "APRILIE");
            break;
        case 5:
            strcpy(luna, "MAI");
            break;
        case 6:
            strcpy(luna, "IUNIE");
            break;
        case 7:
            strcpy(luna, "IULIE");
            break;
        case 8:
            strcpy(luna, "AUGUST");
            break;
        case 9:
            strcpy(luna, "SEPTEMBRIE");
            break;
        case 10:
            strcpy(luna, "OCTOMBRIE");
            break;
        case 11:
            strcpy(luna, "NOIEMBRIE");
            break;
        case 12:
            strcpy(luna, "DECEMBRIE");
            break;
        }
    return luna;
}
// rezolvarea problemei: 

int main (){
    // citire date
    dateClient *listaClienti = NULL;

    int nrClienti = 0, i = 0;

    file.open("./date.in", std::ifstream::in); // se deschide doar pt read

    while (!file.eof()){
        // cat timp am ce sa citesc / fisierul nu e gol
        Client client = citesteClient();
        Servicii servicii = citesteServicii();
        Tranzactii tranzactii = citesteTranzactii();
        tranzactii.setReducere(client);

        addClientInLista(listaClienti, client, servicii, tranzactii);
    }

    file.close();

    // rezolvarea problemei:
    // am structul de dateServicii in tranzactii.h
    dateServicii biletAvion, vacantaWeekend, cityBreak, vacantaCroaziera, tabaraGhid;
    strcpy(biletAvion.numeServiciu, "BILETELE DE AVION");
    strcpy(vacantaWeekend.numeServiciu, "VACANTELE DE WEEKEND");
    strcpy(cityBreak.numeServiciu, "CITY-BREAK-URILE");
    strcpy(vacantaCroaziera.numeServiciu, "VACANTELE DE CROAZIERA");
    strcpy(tabaraGhid.numeServiciu, "TABERELE CU GHID");

    int frecventaMonths[13] = {};

    dateClient *clientUrm;
    // parcurg lista de clienti
    for (clientUrm = listaClienti; clientUrm != NULL; clientUrm = clientUrm -> urmClient){
        int reducere = clientUrm -> tranzactii.getReducere();

        float pretBiletAvion = clientUrm -> tranzactii.getPretBiletAvion();
        float pretDupaReducere = clientUrm -> tranzactii.countPret(biletAvion, pretBiletAvion);
        clientUrm -> tranzactii.setPretBiletAvion(pretDupaReducere);
        
        float pretVacantaWeekend = clientUrm -> tranzactii.getPretVacantaWeekend();
        pretDupaReducere = clientUrm -> tranzactii.countPret(vacantaWeekend, pretVacantaWeekend);
        clientUrm -> tranzactii.setPretBiletAvion(pretDupaReducere);
        
        float pretCityBreak = clientUrm -> tranzactii.getPretCityBreak();
        pretDupaReducere = clientUrm -> tranzactii.countPret(cityBreak, pretCityBreak);
        clientUrm -> tranzactii.setPretBiletAvion(pretDupaReducere);

        float pretVacantaCroaziera = clientUrm -> tranzactii.getPretVacantaCroaziera();
        pretDupaReducere = clientUrm -> tranzactii.countPret(vacantaCroaziera, pretVacantaCroaziera);
        clientUrm -> tranzactii.setPretBiletAvion(pretDupaReducere);

        float pretTabaraGhid = clientUrm -> tranzactii.getPretTabaraGhid();
        pretDupaReducere = clientUrm -> tranzactii.countPret(tabaraGhid, pretTabaraGhid);
        clientUrm -> tranzactii.setPretBiletAvion(pretDupaReducere);

        // afla care este cea mai frecventata perioada de calatorit
        clientUrm -> tranzactii.countMonths(frecventaMonths);
    }
    
    afisareListaClienti(listaClienti);

    dateServicii dateServicii[5] = {biletAvion, vacantaWeekend, cityBreak, vacantaCroaziera, tabaraGhid};
    float sumaMax = -1;
    for (int i = 0; i < 5; i++){
        if (sumaMax < dateServicii[i].suma){
            sumaMax = dateServicii[i].suma;
        }
    }
    for (int i = 0; i < 5; i++){
        if ((int)dateServicii[i].suma == (int)sumaMax){  
            // pun int ca sa nu am bug uri cu floating point
            std::cout << "Unele dintre cele mai profitabile servicii au fost " << '\n' <<
            dateServicii[i].numeServiciu << " avand un CASTIG de " << dateServicii[i].suma 
            << " lei," << '\n' << "fiind UTILIZATE de un numar de " 
            << dateServicii[i].nrClienti << " clienti." << '\n';
        }
    }
    std::cout << "--------------------------------------------------\n";

    int frecvMax = -1;
    for (int i = 1; i <= 12; i++){
        if (frecvMax < frecventaMonths[i]){
            frecvMax = frecventaMonths[i];
        }
    }
    std::cout << "Cele mai frecventate luni din an" << '\n' << "de catre turisti sunt ";
    for (int i = 1; i <= 12; i++)
    {
        if (frecventaMonths[i] == frecvMax){
            char *luna = afisareMonth(i);
            std::cout << luna << " ";
            delete[] luna;
        }
    }
    std::cout << '\n' << "--------------------------------------------------\n";

    clearListaClienti(listaClienti);
    return 0;
}