#include <iostream>
#include <cstring>
#include "client.h"
#include "servicii.h"
#include "tranzactii.h"

// cd Desktop\lab_poo\Proiect_POO\Proiect_1 path for files to be compiled
// g++ *.cpp -o output
// output


// definirea problemei
// sa se afiseze toti clientii care au folosit serviciul de transport acvatic
// sau
// sa se calculeze cel mai profiabil serviciu ; avg ( cati clienti au folosit si cat au platit pentru serviciu )

// sa se afiseze toate servicile solicitate de un anumit client

struct dateClient{
    Client *client;
    Servicii *servicii;
    Tranzactii *tranzactii;
    dateClient *urmClient;
};

void addClient (dateClient*& lista, Client& client, Servicii& servicii, Tranzactii& tranzactii){
    dateClient *clientNou = new dateClient;
    clientNou -> client = &client;
    clientNou -> servicii = &servicii;
    clientNou -> tranzactii = &tranzactii;

    clientNou -> urmClient = lista;
    lista = clientNou;
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

    return client;
}

int main (){
    dateClient *listaClienti = NULL;

    Client client = citesteClient();

    std::cout << client << '\n';
    // addClient(listaClienti, client, servicii, tranzactii);

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