#include <iostream>
#include <cstring>
#include "client.h"
#include "servicii.h"

// cd Desktop\lab_poo\Proiect_POO\Proiect_1 path for files to be compiled
// g++ *.cpp -o output
// output


// definirea problemei
// sa se afiseze toti clientii care au folosit serviciul de transport acvatic
// sau
// sa se calculeze cel mai profiabil serviciu ; avg ( cati clienti au folosit si cat au platit pentru serviciu )

// sa se afiseze toate servicile solicitate de un anumit client

int main (){

    Client client1("cunt", "paul");
    Client client = Client("sal");
    std::cout << client << '\n';

    Client client2 = client1;
    client2.setEmail("yoskibi@outlook.dop");
    client2.setTelefon("075924000000");
    std::cout << client2 << '\n';
    
    // Client client3("salut", "skibi", "yahoo_mail@.com", "+40716716831");
    // std::cout << client3 << '\n';

    // Client client4 = Client(client3);
    // std::cout << client4 << '\n';

    Servicii serviciu;
    serviciu.setVacantaWeekend("Roma");
    serviciu.setTabaraGhid("drumetie");
    std::cout << serviciu << '\n';

    Client client6;
    std::cout <<client6 << '\n';
    return 0;
}