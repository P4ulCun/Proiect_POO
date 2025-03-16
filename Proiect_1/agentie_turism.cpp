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
    Client (const Client& newClient){
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
    void setNume (const char *nume){
        if (strcmp(this -> nume, nume) != 0){
            // sa nu fie acelasi nume
            delete[] this -> nume;
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        }
    }
    void setPrenume (const char *prenume){
        if (strcmp(this -> prenume, prenume) != 0){
            delete[] this -> prenume;
            this -> prenume = new char[strlen(prenume) + 1];
            strcpy(this -> prenume, prenume);
        }
    }
    void setEmail (const char *email){
        if (strcmp(this -> email, email) != 0){
            delete[] this -> email;
            this -> email = new char[strlen(email) + 1];
            strcpy(this -> email, email);
        }
    }
    void setTelefon (const char *telefon){
        if (strcmp(this -> telefon, telefon) != 0){
            delete[] this -> telefon;
            this -> telefon = new char[strlen(telefon) + 1];
            strcpy(this -> telefon, telefon);
        }
    }
    void setFidelitate (const int fidelitate){
        this -> nivelFidelitate = fidelitate;
    }
    
    // supraincarcare operator <<
    // friend - pentru acces direct la date private
    friend std::ostream& operator<<(std::ostream& stream, const Client& client){
        stream << "Nume: " << client.nume << '\n';
        stream << "Prenume: " << client.prenume << '\n';
        stream << "Email: " << client.email << '\n';
        stream << "Telefon: " << client.telefon << '\n';
        stream << "Nivel fidelitate: " << client.nivelFidelitate << '\n';
        return stream;
    }


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
    // ? ce fac cu memoria alocata pentru bufferi ?
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