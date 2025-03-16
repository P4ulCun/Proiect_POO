// definirea problemei
// sa se afiseze toti clientii care au folosit serviciul de transport acvatic
// sau
// sa se calculeze cel mai profiabil serviciu ; avg ( cati clienti au folosit si cat au platit pentru serviciu )

#include <iostream>
#include <cstring>

class Client{
private:
    char *nume;
    char *prenume;
    char *email;
    char *telefon;
    int nivelFidelitate;

public:
    // constructor initializare
    Client (const char *nume = NULL, const char *prenume = NULL, const char *email = NULL, const char *telefon = NULL, const int nivelFidelitate = 0){
        if (nume != NULL){
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        }
        else{
            this -> nume = "-";
        }
        if (prenume != NULL){
            this -> prenume = new char[strlen(prenume) + 1];
            strcpy(this -> prenume, prenume);
        }
        else{
            this -> prenume = "-";
        }
        if (email != NULL){
            this -> email = new char[strlen(email) + 1];
            strcpy(this -> email, email);
        }
        else{
            this -> email = "-";
        }
        if (telefon != NULL){
            this -> telefon = new char[strlen(telefon) + 1];
            strcpy(this -> telefon, telefon);
        }
        else{
            this -> telefon = "-";
        }
        this -> nivelFidelitate = nivelFidelitate;
    }

    // constructor de copiere

    // supraincarcare a operatorului = (copiere obiecte)
    Client& operator=(const Client& client){  // client este cel de copiat ; this este opiectul nou in care se copiaza
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
        }
        return *this;
    }

    // getteri:
    char* getNume (){
        char *bufferNume = new char[strlen(nume) + 1];
        strcpy(bufferNume, nume);
        return bufferNume;
    }
    char* getPrenume (){
        char *bufferPrenume = new char[strlen(prenume) + 1];
        strcpy(bufferPrenume, prenume);
        return bufferPrenume;
    }
    char* getEmail (){
        char *bufferEmail = new char[strlen(email) + 1];
        strcpy(bufferEmail, email);
        return bufferEmail;
    }
    char* getTelefon (){
        char *bufferTelefon = new char[strlen(telefon) + 1];
        strcpy(bufferTelefon, telefon);
        return bufferTelefon;
    }
    int getFidelitate (){
        return nivelFidelitate;
    }

    // setteri:

    
    // supraincarcare operator <<
    // std::ostream& operator<<(std::ostream& stream, const Client& client){
    //     stream << "Nume: " << client.getNume() << '\n';
    //     stream << "Prenume: " << client.getPrenume() << '\n';
    //     stream << "Email: " << client.getEmail() << '\n';
    //     stream << "Telefon: " << client.getTelefon() << '\n';
    //     stream << "Nivel fidelitate: " << client.getFidelitate() << '\n';
    //     return stream;
    // }


    // destructor obiect
    ~Client (){
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
};

int main () {
    Client client1("cunt", "paul");
    Client client2 = client1;
    std::cout << client1.getNume() << '\n';
    std::cout << client1.getPrenume() << '\n';
    std::cout << client1.getEmail() << '\n';
    std::cout << client1.getTelefon() << '\n';
    std::cout << client1.getFidelitate() << '\n';

    return 0;
}