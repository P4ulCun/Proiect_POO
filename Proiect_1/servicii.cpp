// count the number of services for a customer
// coutn the total services available aka the number of private elements

// la tranzactii fac pret pentru fiecare serviciu utilizat 
// si metoda de plata

#include <iostream>
#include <cstring>
#include "servicii.h"
// constructor initializare
Servicii::Servicii (const char *biletAvion, const char *vacantaWeekend, 
    const char *cityBreak, const char *vacantaCroaziera, const char *tabaraGhid){

    if (biletAvion != NULL || biletAvion[0] != ' '){
        this -> biletAvion = new char[strlen(biletAvion) + 1];
        strcpy(this -> biletAvion, biletAvion);
    }
    else{
        this -> biletAvion = new char;
        strcpy(this -> biletAvion, "-");
    }
    if (vacantaWeekend != NULL){
        this -> vacantaWeekend = new char[strlen(vacantaWeekend) + 1];
        strcpy(this -> vacantaWeekend, vacantaWeekend);
    }
    else{
        this -> vacantaWeekend = new char;
        strcpy(this -> vacantaWeekend, "-");
    }
    if (cityBreak != NULL){
        this -> cityBreak = new char[strlen(cityBreak) + 1];
        strcpy(this -> cityBreak, cityBreak);
    }
    else{
        this -> cityBreak = new char;
        strcpy(this -> cityBreak, "-");
    }
    if (vacantaCroaziera != NULL){
        this -> vacantaCroaziera = new char[strlen(vacantaCroaziera) + 1];
        strcpy(this -> vacantaCroaziera, vacantaCroaziera);
    }
    else{
        this -> vacantaCroaziera = new char;
        strcpy(this -> vacantaCroaziera, "-");
    }
    if (tabaraGhid != NULL){
        this -> tabaraGhid = new char[strlen(tabaraGhid) + 1];
        strcpy(this -> tabaraGhid, tabaraGhid);
    }
    else{
        this -> tabaraGhid = new char;
        strcpy(this -> tabaraGhid, "-");
    }
}

// constructor de copiere
Servicii::Servicii (const Servicii& newServicii){
    this -> biletAvion = new char[strlen(newServicii.biletAvion) + 1];
    strcpy(this -> biletAvion, newServicii.biletAvion);
    this -> vacantaWeekend = new char[strlen(newServicii.vacantaWeekend) + 1];
    strcpy(this -> vacantaWeekend, newServicii.vacantaWeekend);
    this -> cityBreak = new char[strlen(newServicii.cityBreak) + 1];
    strcpy(this -> cityBreak, newServicii.cityBreak);
    this -> vacantaCroaziera = new char[strlen(newServicii.vacantaCroaziera) + 1];
    strcpy(this -> vacantaCroaziera, newServicii.vacantaCroaziera);
    this -> tabaraGhid = new char[strlen(newServicii.tabaraGhid) + 1];
    strcpy(this -> tabaraGhid, newServicii.tabaraGhid);
}

// supraincarcare a operatorului = (copiere obiecte)
Servicii& Servicii::operator=(const Servicii& servicii){  
    // Servicii este cel de copiat ; this este opiectul nou in care se copiaza
    if (this != &servicii){
        delete[] this -> biletAvion;
        this -> biletAvion = new char[strlen(servicii.biletAvion) + 1];
        strcpy(this -> biletAvion, servicii.biletAvion);

        delete[] this -> vacantaWeekend;
        this -> vacantaWeekend = new char[strlen(servicii.vacantaWeekend) + 1];
        strcpy(this -> vacantaWeekend, servicii.vacantaWeekend);

        delete[] this -> cityBreak;
        this -> cityBreak = new char[strlen(servicii.cityBreak) + 1];
        strcpy(this -> cityBreak, servicii.cityBreak);

        delete[] this -> vacantaCroaziera;
        this -> vacantaCroaziera = new char[strlen(servicii.vacantaCroaziera) + 1];
        strcpy(this -> vacantaCroaziera, servicii.vacantaCroaziera);

        delete[] this -> tabaraGhid;
        this -> tabaraGhid = new char[strlen(servicii.tabaraGhid) + 1];
        strcpy(this -> tabaraGhid, servicii.tabaraGhid);
    }
    return *this;
}

// getteri:
char* Servicii::getBiletAvion (){
    char *bufferbiletAvion = new char[strlen(biletAvion) + 1];
    strcpy(bufferbiletAvion, biletAvion);
    return bufferbiletAvion;
}
char* Servicii::getVacantaWeekend (){
    char *buffervacantaWeekend = new char[strlen(vacantaWeekend) + 1];
    strcpy(buffervacantaWeekend, vacantaWeekend);
    return buffervacantaWeekend;
}
char* Servicii::getCityBreak (){
    char *buffercityBreak = new char[strlen(cityBreak) + 1];
    strcpy(buffercityBreak, cityBreak);
    return buffercityBreak;
}
char* Servicii::getVacantaCroaziera (){
    char *buffervacantaCroaziera = new char[strlen(vacantaCroaziera) + 1];
    strcpy(buffervacantaCroaziera, vacantaCroaziera);
    return buffervacantaCroaziera;
}
char* Servicii::getTabaraGhid (){
    char *buffertabaraGhid = new char[strlen(tabaraGhid) + 1];
    strcpy(buffertabaraGhid, tabaraGhid);
    return buffertabaraGhid;
}

// setteri:
void Servicii::setBiletAvion (const char *biletAvion){
    if (strcmp(this -> biletAvion, biletAvion) != 0){
        // sa nu fie acelasi biletAvion
        delete[] this -> biletAvion;
        this -> biletAvion = new char[strlen(biletAvion) + 1];
        strcpy(this -> biletAvion, biletAvion);
    }
}
void Servicii::setVacantaWeekend (const char *vacantaWeekend){
    if (strcmp(this -> vacantaWeekend, vacantaWeekend) != 0){
        delete[] this -> vacantaWeekend;
        this -> vacantaWeekend = new char[strlen(vacantaWeekend) + 1];
        strcpy(this -> vacantaWeekend, vacantaWeekend);
    }
}
void Servicii::setCityBreak (const char *cityBreak){
    if (strcmp(this -> cityBreak, cityBreak) != 0){
        delete[] this -> cityBreak;
        this -> cityBreak = new char[strlen(cityBreak) + 1];
        strcpy(this -> cityBreak, cityBreak);
    }
}
void Servicii::setVacantaCroaziera (const char *vacantaCroaziera){
    if (strcmp(this -> vacantaCroaziera, vacantaCroaziera) != 0){
        delete[] this -> vacantaCroaziera;
        this -> vacantaCroaziera = new char[strlen(vacantaCroaziera) + 1];
        strcpy(this -> vacantaCroaziera, vacantaCroaziera);
    }
}
void Servicii::setTabaraGhid (const char *tabaraGhid){
    if (strcmp(this -> tabaraGhid, tabaraGhid) != 0){
        delete[] this -> tabaraGhid;
        this -> tabaraGhid = new char[strlen(tabaraGhid) + 1];
        strcpy(this -> tabaraGhid, tabaraGhid);
    }
}

// supraincarcare operator <<
// friend - pentru acces direct la date private
std::ostream& operator<<(std::ostream& stream, const Servicii& Servicii){
    stream << "Bilet de avion: " << Servicii.biletAvion << '\n';
    stream << "Vacanta weekend in: " << Servicii.vacantaWeekend << '\n';
    stream << "City-Break in: " << Servicii.cityBreak << '\n';
    stream << "Vacanta pe croaziera: " << Servicii.vacantaCroaziera << '\n';
    stream << "Tabara cu ghid: " << Servicii.tabaraGhid << '\n';
    return stream;
}


// destructor obiect
Servicii::~Servicii (){
    delete[] biletAvion;
    delete[] vacantaWeekend;
    delete[] cityBreak;
    delete[] vacantaCroaziera;
    delete[] tabaraGhid;
}