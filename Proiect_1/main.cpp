#include <iostream>
#include <cstring>
#include "client.h"

// cd Desktop\lab_poo\Proiect_POO\Proiect_1 path for files to be compiled
// g++ *.cpp -o output
// output

int main (){

    Client client1("cunt", "paul");
    Client client = Client("sal");
    std::cout << client << '\n';

    Client client2 = client1;
    client2.setEmail("yoskibi@outlook.dop");
    client2.setTelefon("075924000000");
    std::cout << client2 << '\n';
    
    Client client3("salut", "skibi", "yahoo_mail@.com", "+40716716831");
    std::cout << client3 << '\n';

    Client client4 = Client(client3);
    std::cout << client4 << '\n';
    return 0;
}