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
// sa se afiseze toti clientii cu datele lor, dupa reducerea aplicata 
// apoi 
// sa se calculeze si afiseze cel mai profiabil serviciu ; 
// avg ( cati clienti au folosit si cat au platit pentru serviciu )
// si sa se determine care sunt cele mai frecventate luni din an de clienti
// pentru a ajuta agentia de turism sa isi gestioneze mai bine resursele
// aka sa stie pe ce sa sa axeze, sau sa introduca mai multe servicii
// in lunile cele mai frecventate cu servicii ce le aduc cel mai mult profit
// !!!!!
// !!sa se afiseze cel mai fidel client O(1) - fac lista sa se sorteze dupa nivel fidelitate


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

    // mai mult voi memora si luna in care se planuieste vacanta/vacantele
    // daca voi avea dd.07.yyyy - dd.07.yyyy  voi pune o singura data luna 07
    // voi face cum ar fi un vector de frercventa
    // daca voi avea dd.06.yyyy - dd.07.yyyy voi contoriza ambele luni
    // care luna e cea mai frecventata o voi afisa

    // !! sa gasesc cea mai frecventata destinatie?

    // !!sa se afiseze cel mai fidel client O(1) - fac lista sa se sorteze dupa nivel fidelitate

    // char nr[3];
    // cin.getline(nr, 3);
    // int luna = nr[0] - '0';
    // luna = luna * 10 + (nr[1] - '0');
    // cout << luna << '\n';
    // cod pt calcularea lunii;
    // trb sa fac vector de frecventa

    // sa iau pretul serviciului, aplic reducerea si schimb pretul ; folosesc set
    
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