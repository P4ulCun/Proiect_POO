#include <iostream>
#include <cstring>
#include "tranzactii.h"
#include "client.h"

Tranzactii::Tranzactii (const int pretBiletAvion, const int pretVacantaWeekend, const int pretCityBreak,
    const int pretVacantaCroaziera, const int pretTabaraGhid, const char *dataVacantaWeekend, 
    const char *dataCityBreak, const char *dataVacantaCroaziera, const char *dataTabaraGhid){

        this -> pretBiletAvion = pretBiletAvion;
        this -> pretVacantaWeekend = pretVacantaWeekend;
        this -> pretCityBreak = pretCityBreak;
        this -> pretVacantaCroaziera = pretVacantaCroaziera;
        this -> pretTabaraGhid = pretTabaraGhid;
        this -> reducere = 0;

        if (dataVacantaWeekend != NULL){
            this -> dataVacantaWeekend = new char[strlen(dataVacantaWeekend) + 1];
            strcpy(this -> dataVacantaWeekend, dataVacantaWeekend);
        }
        else{
            this -> dataVacantaWeekend = new char;
            strcpy(this -> dataVacantaWeekend, "-");
        }
        if (dataCityBreak != NULL){
            this -> dataCityBreak = new char[strlen(dataCityBreak) + 1];
            strcpy(this -> dataCityBreak, dataCityBreak);
        }
        else{
            this -> dataCityBreak = new char;
            strcpy(this -> dataCityBreak, "-");
        }
        if (dataVacantaCroaziera != NULL){
            this -> dataVacantaCroaziera = new char[strlen(dataVacantaCroaziera) + 1];
            strcpy(this -> dataVacantaCroaziera, dataVacantaCroaziera);
        }
        else{
            this -> dataVacantaCroaziera = new char;
            strcpy(this -> dataVacantaCroaziera, "-");
        }
        if (dataTabaraGhid != NULL){
            this -> dataTabaraGhid = new char[strlen(dataTabaraGhid) + 1];
            strcpy(this -> dataTabaraGhid, dataTabaraGhid);
        }
        else{
            this -> dataTabaraGhid = new char;
            strcpy(this -> dataTabaraGhid, "-");
        }
    }

//constructor de copiere
Tranzactii::Tranzactii (Tranzactii& newTranzactie){
    this -> pretBiletAvion = newTranzactie.pretBiletAvion;
    this -> pretVacantaWeekend = newTranzactie.pretVacantaWeekend;
    this -> pretCityBreak = newTranzactie.pretCityBreak;
    this -> pretVacantaCroaziera = newTranzactie.pretVacantaCroaziera;
    this -> pretTabaraGhid = newTranzactie.pretTabaraGhid;
    this -> reducere = newTranzactie.reducere;

    this -> dataVacantaWeekend = new char[strlen(newTranzactie.dataVacantaWeekend) + 1];
    strcpy(this -> dataVacantaWeekend, newTranzactie.dataVacantaWeekend);

    this -> dataCityBreak = new char[strlen(newTranzactie.dataCityBreak) + 1];
    strcpy(this -> dataCityBreak, newTranzactie.dataCityBreak);

    this -> dataVacantaCroaziera = new char[strlen(newTranzactie.dataVacantaCroaziera) + 1];
    strcpy(this -> dataVacantaCroaziera, newTranzactie.dataVacantaCroaziera);

    this -> dataTabaraGhid = new char[strlen(newTranzactie.dataTabaraGhid) + 1];
    strcpy(this -> dataTabaraGhid, newTranzactie.dataTabaraGhid);
}

Tranzactii& Tranzactii::operator=(const Tranzactii& tranzactie){
    if (this != &tranzactie){
        this -> pretBiletAvion = pretBiletAvion;
        this -> pretVacantaWeekend = pretVacantaWeekend;
        this -> pretCityBreak = pretCityBreak;
        this -> pretVacantaCroaziera = pretVacantaCroaziera;
        this -> pretTabaraGhid = pretTabaraGhid;
        this -> reducere = reducere;

        delete[] this -> dataVacantaWeekend;
        this -> dataVacantaWeekend = new char[strlen(tranzactie.dataVacantaWeekend) + 1];
        strcpy(this -> dataVacantaWeekend, tranzactie.dataVacantaWeekend);

        delete[] this -> dataCityBreak;
        this -> dataCityBreak = new char[strlen(tranzactie.dataCityBreak) + 1];
        strcpy(this -> dataCityBreak, tranzactie.dataCityBreak);

        delete[] this -> dataVacantaCroaziera;
        this -> dataVacantaCroaziera = new char[strlen(tranzactie.dataVacantaCroaziera) + 1];
        strcpy(this -> dataVacantaCroaziera, tranzactie.dataVacantaCroaziera);

        delete[] this -> dataTabaraGhid;
        this -> dataTabaraGhid = new char[strlen(tranzactie.dataTabaraGhid) + 1];
        strcpy(this -> dataTabaraGhid, tranzactie.dataTabaraGhid);
    }
    return *this;
}

// getters
int Tranzactii::getPretBiletAvion (){
    return pretBiletAvion;
}
int Tranzactii::getPretVacantaWeekend (){
    return pretVacantaWeekend;
}
int Tranzactii::getPretCityBreak (){
    return pretCityBreak;
}
int Tranzactii::getPretVacantaCroaziera (){
    return pretVacantaCroaziera;
}
int Tranzactii::getPretTabaraGhid (){\
    return pretTabaraGhid;}
int Tranzactii::getReducere (){
    return reducere;
}

char* Tranzactii::getDataVacantaWeekend (){
    char *bufferWeekend = new char[strlen(dataVacantaWeekend) + 1];
    strcpy(bufferWeekend, dataVacantaWeekend);
    return bufferWeekend;
}
char* Tranzactii::getDataCityBreak (){
    char *bufferCityBreak = new char[strlen(dataCityBreak) + 1];
    strcpy(bufferCityBreak, dataCityBreak);
    return bufferCityBreak;
}
char* Tranzactii::getDataVacantaCroaziera (){
    char *bufferCroaziera = new char[strlen(dataVacantaCroaziera) + 1];
    strcpy(bufferCroaziera, dataVacantaCroaziera);
    return bufferCroaziera;
}
char* Tranzactii::getDataTabaraGhid (){
    char *bufferTabara = new char[strlen(dataTabaraGhid) + 1];
    strcpy(bufferTabara, dataTabaraGhid);
    return bufferTabara;
}

// setters

void Tranzactii::setPretBiletAvion (const int pretBiletAvion){
    this -> pretBiletAvion = pretBiletAvion;
}
void Tranzactii::setPretVacantaWeekend (const int pretVacantaWeekend){
    this -> pretVacantaWeekend = pretVacantaWeekend;
}
void Tranzactii::setPretCityBreak (const int pretCityBreak){
    this -> pretCityBreak = pretCityBreak;
}
void Tranzactii::setPretVacantaCroaziera (const int pretVacantaCroaziera){
    this -> pretVacantaCroaziera = pretVacantaCroaziera;
}
void Tranzactii::setPretTabaraGhid (const int pretTabaraGhid){
    this -> pretTabaraGhid = pretTabaraGhid;
}

void Tranzactii::setReducere (Client& client){
    switch (client.nivelFidelitate){
        // la 0 nu schimb, il las 0
        case 0:
            break;
        case 1:
            this -> reducere = 10;
            break;
        case 2:
            this -> reducere = 20;
            break;
        case 3:
            this -> reducere = 30;
            break;
        case 4:
            this -> reducere = 40;
            break;
        case 5:
            this -> reducere = 55;
            break;
    }
}

void Tranzactii::setVacantaWeekend (const char *dataVacantaWeekend){
    if (strcmp(this -> dataVacantaWeekend, dataVacantaWeekend) != 0){
        // sa nu fie acelasi dataCityBreak
        delete[] this -> dataVacantaWeekend;
        this -> dataVacantaWeekend = new char[strlen(dataVacantaWeekend) + 1];
        strcpy(this -> dataVacantaWeekend, dataVacantaWeekend);
    }
}
void Tranzactii::setCityBreak (const char *dataCityBreak){
    if (strcmp(this -> dataCityBreak, dataCityBreak) != 0){
        // sa nu fie acelasi dataCityBreak
        delete[] this -> dataCityBreak;
        this -> dataCityBreak = new char[strlen(dataCityBreak) + 1];
        strcpy(this -> dataCityBreak, dataCityBreak);
    }
}
void Tranzactii::setVacantaCroaziera (const char *dataVacantaCroaziera){
    if (strcmp(this -> dataVacantaCroaziera, dataVacantaCroaziera) != 0){
        // sa nu fie acelasi dataCityBreak
        delete[] this -> dataVacantaCroaziera;
        this -> dataVacantaCroaziera = new char[strlen(dataVacantaCroaziera) + 1];
        strcpy(this -> dataVacantaCroaziera, dataVacantaCroaziera);
    }
}
void Tranzactii::setTabaraGhid (const char *dataTabaraGhid){
    if (strcmp(this -> dataTabaraGhid, dataTabaraGhid) != 0){
        // sa nu fie acelasi dataCityBreak
        delete[] this -> dataTabaraGhid;
        this -> dataTabaraGhid = new char[strlen(dataTabaraGhid) + 1];
        strcpy(this -> dataTabaraGhid, dataTabaraGhid);
    }
}

std::ostream& operator<<(std::ostream& stream, Tranzactii& tranzactie){
    stream << "Pret bilet avion: " << tranzactie.pretBiletAvion << '\n';
    stream << "Pret vacanta weekend: " << tranzactie.pretVacantaWeekend << '\n';
    stream << "Pret city-break: " << tranzactie.pretCityBreak << '\n';
    stream << "Pret vacanta pe croaziera: " << tranzactie.pretVacantaCroaziera << '\n';
    stream << "Pret tabara cu ghid: " << tranzactie.pretTabaraGhid << '\n';
    stream << "Procentaj reducere: " << tranzactie.reducere << '\n';

    stream << "Interval vacanta weekend: " << tranzactie.dataVacantaWeekend << '\n';
    stream << "Interval city-break: " << tranzactie.dataCityBreak << '\n';
    stream << "Interval vacanta pe croaziera: " << tranzactie.dataVacantaCroaziera << '\n';
    stream << "Interval tabara cu ghid: " << tranzactie.dataTabaraGhid << '\n';
    return stream;
}

Tranzactii::~Tranzactii (){
    delete[] dataVacantaWeekend;
    delete[] dataCityBreak;
    delete[] dataVacantaCroaziera;
    delete[] dataTabaraGhid;
}