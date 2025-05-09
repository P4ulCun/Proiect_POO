#pragma once

// se retin date fiecarui client
#include "tranzactii.h"

class Client{
private:
    char *nume;
    char *prenume;
    char *email;
    char *telefon;
    int nivelFidelitate;

public:
    friend class Tranzactii;
    // constructor initializare
    Client (const char* nume = NULL, const char* prenume = NULL, const char* email = NULL, 
        const char* telefon = NULL, const int nivelFidelitate = 0);

    // constructor de copiere
    Client (const Client& newClient);

    // supraincarcare a operatorului = (copiere obiecte)
    Client& operator=(const Client& client);

    // getteri:
    char* getNume ();
    char* getPrenume ();
    char* getEmail ();
    char* getTelefon ();
    int getFidelitate ();

    // setteri:
    void setNume (const char *nume);
    void setPrenume (const char *prenume);
    void setEmail (const char *email);
    void setTelefon (const char *telefon);
    void setFidelitate (const int fidelitate);
    
    // supraincarcare operator <<
    // friend - pentru acces direct la date private
    friend std::ostream& operator<<(std::ostream& stream, const Client& client);

    // destructor obiect
    ~Client ();
};