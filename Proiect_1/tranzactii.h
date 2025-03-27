#pragma once

// se retin toate detalile despre serviciile oferite clientului ; pretul servicilor
// si data cand se planuieste vacanta

class Client;
struct dateServicii{
    float suma = 0;
    int nrClienti = 0;
    char numeServiciu[24];
};
// foloses pt countPret, metoda din clasa Tranzactii

class Tranzactii{
private:
    float pretBiletAvion;
    float pretVacantaWeekend;
    float pretCityBreak;
    float pretVacantaCroaziera;
    float pretTabaraGhid;

    int reducere; // % - procentaj
    // oferita pe mai multe nivele in functie de nivelul de fidelitate a clientului

    char *dataVacantaWeekend;
    char *dataCityBreak;
    char *dataVacantaCroaziera;
    char *dataTabaraGhid;
public:
    Tranzactii (const float pretBiletAvion = -1, const float pretVacantaWeekend = -1, const float pretCityBreak = -1,
        const float pretVacantaCroaziera = -1, const float pretTabaraGhid = -1, const char *dataVacantaWeekend = NULL, 
        const char *dataCityBreak = NULL, const char *dataVacantaCroaziera = NULL, const char *dataTabaraGhid = NULL);
        
    Tranzactii (Tranzactii& tranzactie);

    Tranzactii& operator=(const Tranzactii& tranzactie);

    float getPretBiletAvion ();
    float getPretVacantaWeekend ();
    float getPretCityBreak ();
    float getPretVacantaCroaziera ();
    float getPretTabaraGhid ();
    float getReducere ();

    char* getDataVacantaWeekend ();
    char* getDataCityBreak ();
    char* getDataVacantaCroaziera ();
    char* getDataTabaraGhid ();

    // setters
    void setPretBiletAvion (const float pretBiletAvion);
    void setPretVacantaWeekend (const float pretVacantaWeekend);
    void setPretCityBreak (const float pretCityBreak);
    void setPretVacantaCroaziera (const float pretVacantaCroaziera);
    void setPretTabaraGhid (const float pretTabaraGhid);
    void setReducere (Client& client);
    // setez reducerea in functie de nivelul de fidelitate

    void setVacantaWeekend (const char *dataVacantaWeekend);
    void setCityBreak (const char *dataCityBreak);
    void setVacantaCroaziera (const char *dataVacantaCroaziera);
    void setTabaraGhid (const char *dataTabaraGhid);

    friend std::ostream& operator<<(std::ostream& stream, Tranzactii& tranzactie);

    int countPret (dateServicii& serviciu, float pretServiciu);

    void countMonths (int frecventaMonths[]);

    ~Tranzactii ();
};