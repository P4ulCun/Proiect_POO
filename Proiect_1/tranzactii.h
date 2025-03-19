#pragma once

class Client;

class Tranzactii{
private:
    int pretBiletAvion;
    int pretVacantaWeekend;
    int pretCityBreak;
    int pretVacantaCroaziera;
    int pretTabaraGhid;

    int reducere; // % - procentaj
    // oferita pe mai multe nivele in functie de nivelul de fidelitate a clientului

    char *dataVacantaWeekend;
    char *dataCityBreak;
    char *dataVacantaCroaziera;
    char *dataTabaraGhid;
public:
    Tranzactii (const int pretBiletAvion = -1, const int pretVacantaWeekend = -1, const int pretCityBreak = -1,
        const int pretVacantaCroaziera = -1, const int pretTabaraGhid = -1, const char *dataVacantaWeekend = NULL, 
        const char *dataCityBreak = NULL, const char *dataVacantaCroaziera = NULL, const char *dataTabaraGhid = NULL);
        
    Tranzactii (Tranzactii& tranzactie);

    Tranzactii& operator=(const Tranzactii& tranzactie);

    int getPretBiletAvion ();
    int getPretVacantaWeekend ();
    int getPretCityBreak ();
    int getPretVacantaCroaziera ();
    int getPretTabaraGhid ();
    int getReducere ();

    char* getDataVacantaWeekend ();
    char* getDataCityBreak ();
    char* getDataVacantaCroaziera ();
    char* getDataTabaraGhid ();

    // setters
    void setPretBiletAvion (const int pretBiletAvion);
    void setPretVacantaWeekend (const int pretVacantaWeekend);
    void setPretCityBreak (const int pretCityBreak);
    void setPretVacantaCroaziera (const int pretVacantaCroaziera);
    void setPretTabaraGhid (const int pretTabaraGhid);
    void setReducere (Client& client);
    // setez reducerea in functie de nivelul de fidelitate

    void setVacantaWeekend (const char *dataVacantaWeekend);
    void setCityBreak (const char *dataCityBreak);
    void setVacantaCroaziera (const char *dataVacantaCroaziera);
    void setTabaraGhid (const char *dataTabaraGhid);

    friend std::ostream& operator<<(std::ostream& stream, Tranzactii& tranzactie);

    ~Tranzactii ();
};