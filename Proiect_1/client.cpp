#include <iostream>
#include <cstring>
#include "client.h"
// constructor initializare
Client::Client (const char *nume, const char *prenume, const char *email, const char *telefon, const int nivelFidelitate){
    if (nume != NULL){
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }
    else{
        this -> nume = new char;
        strcpy(this -> nume, "-");
    }
    if (prenume != NULL){
        this -> prenume = new char[strlen(prenume) + 1];
        strcpy(this -> prenume, prenume);
    }
    else{
        this -> prenume = new char;
        strcpy(this -> prenume, "-");
    }
    if (email != NULL){
        this -> email = new char[strlen(email) + 1];
        strcpy(this -> email, email);
    }
    else{
        this -> email = new char;
        strcpy(this -> email, "-");
    }
    if (telefon != NULL){
        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);
    }
    else{
        this -> telefon = new char;
        strcpy(this -> telefon, "-");
    }
    this -> nivelFidelitate = nivelFidelitate;
}

// constructor de copiere
Client::Client (const Client& newClient){
    this -> nume = new char[strlen(newClient.nume) + 1];
    strcpy(this -> nume, newClient.nume);
    this -> prenume = new char[strlen(newClient.prenume) + 1];
    strcpy(this -> prenume, newClient.prenume);
    this -> email = new char[strlen(newClient.email) + 1];
    strcpy(this -> email, newClient.email);
    this -> telefon = new char[strlen(newClient.telefon) + 1];
    strcpy(this -> telefon, newClient.telefon);
    this -> nivelFidelitate = newClient.nivelFidelitate;
}

// supraincarcare a operatorului = (copiere obiecte)
Client& Client::operator=(const Client& client){  // client este cel de copiat ; this este opiectul nou in care se copiaza
    if (this != &client){
        delete[] this -> nume;
        this -> nume = new char[strlen(client.nume) + 1];
        strcpy(this -> nume, client.nume);

        delete[] this -> prenume;
        this -> prenume = new char[strlen(client.prenume) + 1];
        strcpy(this -> prenume, client.prenume);

        delete[] this -> email;
        this -> email = new char[strlen(client.email) + 1];
        strcpy(this -> email, client.email);

        delete[] this -> telefon;
        this -> telefon = new char[strlen(client.telefon) + 1];
        strcpy(this -> telefon, client.telefon);

        this -> nivelFidelitate = nivelFidelitate;
    }
    return *this;
}
// getteri:

char* Client::getNume (){
    char *bufferNume = new char[strlen(nume) + 1];
    strcpy(bufferNume, nume);
    return bufferNume;
}
char* Client::getPrenume (){
    char *bufferPrenume = new char[strlen(prenume) + 1];
    strcpy(bufferPrenume, prenume);
    return bufferPrenume;
}
char* Client::getEmail (){
    char *bufferEmail = new char[strlen(email) + 1];
    strcpy(bufferEmail, email);
    return bufferEmail;
}
char* Client::getTelefon (){
    char *bufferTelefon = new char[strlen(telefon) + 1];
    strcpy(bufferTelefon, telefon);
    return bufferTelefon;
}
int Client::getFidelitate (){
    return nivelFidelitate;
}

// setteri:
void Client::setNume (const char *nume){
    if (strcmp(this -> nume, nume) != 0){
        // sa nu fie acelasi nume
        delete[] this -> nume;
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }
}
void Client::setPrenume (const char *prenume){
    if (strcmp(this -> prenume, prenume) != 0){
        delete[] this -> prenume;
        this -> prenume = new char[strlen(prenume) + 1];
        strcpy(this -> prenume, prenume);
    }
}
void Client::setEmail (const char *email){
    if (strcmp(this -> email, email) != 0){
        delete[] this -> email;
        this -> email = new char[strlen(email) + 1];
        strcpy(this -> email, email);
    }
}
void Client::setTelefon (const char *telefon){
    if (strcmp(this -> telefon, telefon) != 0){
        delete[] this -> telefon;
        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);
    }
}
void Client::setFidelitate (const int fidelitate){
    this -> nivelFidelitate = fidelitate;
}

// supraincarcare operator <<
// friend - pentru acces direct la date private
std::ostream& operator<<(std::ostream& stream, const Client& client){
    stream << "Nume: " << client.nume << '\n';
    stream << "Prenume: " << client.prenume << '\n';
    stream << "Email: " << client.email << '\n';
    stream << "Telefon: " << client.telefon << '\n';
    stream << "Nivel fidelitate: " << client.nivelFidelitate << '\n';
    return stream;
}


// destructor obiect
Client::~Client (){
    delete[] nume;
    delete[] prenume;
    delete[] email;
    delete[] telefon;

    // destructor bufferi
    // delete[] bufferNume;
    // delete[] bufferPrenume;
    // delete[] bufferEmail;
    // delete[] bufferTelefon;
}