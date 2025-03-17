// count the number of services for a customer
// coutn the total services available aka the number of private elements

// la tranzactii fac pret pentru fiecare serviciu utilizat 
// si metoda de plata

#include <iostream>
#include <cstring>
#include "servicii.h"
// constructor initializare
Servicii::Servicii (const char *biletAvionDus, const char *biletAvionIntors, const char *vacantaWeekend, const char *cityBreak, const char *vacantaCroaziera, const char *tabaraGhid){
    if (biletAvionDus != NULL){
        this -> biletAvionDus = new char[strlen(biletAvionDus) + 1];
        strcpy(this -> biletAvionDus, biletAvionDus);
    }
    else{
        this -> biletAvionDus = new char;
        strcpy(this -> biletAvionDus, "-");
    }
    if (biletAvionIntors != NULL){
        this -> biletAvionIntors = new char[strlen(biletAvionIntors) + 1];
        strcpy(this -> biletAvionIntors, biletAvionIntors);
    }
    else{
        this -> biletAvionIntors = new char;
        strcpy(this -> biletAvionIntors, "-");
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
    this -> biletAvionDus = new char[strlen(newServicii.biletAvionDus) + 1];
    strcpy(this -> biletAvionDus, newServicii.biletAvionDus);
    this -> biletAvionIntors = new char[strlen(newServicii.biletAvionIntors) + 1];
    strcpy(this -> biletAvionIntors, newServicii.biletAvionIntors);
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
Servicii& Servicii::operator=(const Servicii& Servicii){  // Servicii este cel de copiat ; this este opiectul nou in care se copiaza
    if (this != &Servicii){
        delete[] this -> biletAvionDus;
        this -> biletAvionDus = new char[strlen(Servicii.biletAvionDus) + 1];
        strcpy(this -> biletAvionDus, Servicii.biletAvionDus);

        delete[] this -> biletAvionIntors;
        this -> biletAvionIntors = new char[strlen(Servicii.biletAvionIntors) + 1];
        strcpy(this -> biletAvionIntors, Servicii.biletAvionIntors);

        delete[] this -> vacantaWeekend;
        this -> vacantaWeekend = new char[strlen(Servicii.vacantaWeekend) + 1];
        strcpy(this -> vacantaWeekend, Servicii.vacantaWeekend);

        delete[] this -> cityBreak;
        this -> cityBreak = new char[strlen(Servicii.cityBreak) + 1];
        strcpy(this -> cityBreak, Servicii.cityBreak);

        delete[] this -> vacantaCroaziera;
        this -> vacantaCroaziera = new char[strlen(Servicii.vacantaCroaziera) + 1];
        strcpy(this -> vacantaCroaziera, Servicii.vacantaCroaziera);

        delete[] this -> tabaraGhid;
        this -> tabaraGhid = new char[strlen(Servicii.tabaraGhid) + 1];
        strcpy(this -> tabaraGhid, Servicii.tabaraGhid);
    }
    return *this;
}

// getteri:
char* Servicii::getBiletAvionDus (){
    char *bufferbiletAvionDus = new char[strlen(biletAvionDus) + 1];
    strcpy(bufferbiletAvionDus, biletAvionDus);
    return bufferbiletAvionDus;
}
char* Servicii::getBiletAvionIntors (){
    char *bufferbiletAvionIntors = new char[strlen(biletAvionIntors) + 1];
    strcpy(bufferbiletAvionIntors, biletAvionIntors);
    return bufferbiletAvionIntors;
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
void Servicii::setBiletAvionDus (const char *biletAvionDus){
    if (strcmp(this -> biletAvionDus, biletAvionDus) != 0){
        // sa nu fie acelasi biletAvionDus
        delete[] this -> biletAvionDus;
        this -> biletAvionDus = new char[strlen(biletAvionDus) + 1];
        strcpy(this -> biletAvionDus, biletAvionDus);
    }
}
void Servicii::setBiletAvionIntors (const char *biletAvionIntors){
    if (strcmp(this -> biletAvionIntors, biletAvionIntors) != 0){
        delete[] this -> biletAvionIntors;
        this -> biletAvionIntors = new char[strlen(biletAvionIntors) + 1];
        strcpy(this -> biletAvionIntors, biletAvionIntors);
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
    stream << "Bilet de avion dus: : " << Servicii.biletAvionDus << '\n';
    stream << "Bilet de avion intors: " << Servicii.biletAvionIntors << '\n';
    stream << "Vacanta weekend in: " << Servicii.vacantaWeekend << '\n';
    stream << "City-Break in: " << Servicii.cityBreak << '\n';
    stream << "Vacanta pe croaziera: " << Servicii.vacantaCroaziera << '\n';
    stream << "Tabara cu ghid: " << Servicii.tabaraGhid << '\n';
    return stream;
}


// destructor obiect
Servicii::~Servicii (){
    delete[] biletAvionDus;
    delete[] biletAvionIntors;
    delete[] vacantaWeekend;
    delete[] cityBreak;
    delete[] vacantaCroaziera;
    delete[] tabaraGhid;
}