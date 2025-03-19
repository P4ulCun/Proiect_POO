#pragma once

// se retin toate serviciile oferite de agentia de turism

class Servicii{
private:
    char *biletAvion;
    char *vacantaWeekend;
    char *cityBreak; // scriu orasul
    char *vacantaCroaziera; // scriu croaziera
    char *tabaraGhid; // drumetii, scuba

public:
    Servicii (const char* biletAvion = NULL, const char* vacantaWeekend = NULL, 
        const char* cityBreak = NULL, const char* vacantaCroaziera = NULL, const char* tabaraGhid = NULL);
        
    Servicii (const Servicii& serviciu);

    Servicii& operator=(const Servicii& Servicii);

    char* getBiletAvion ();
    char* getVacantaWeekend ();
    char* getCityBreak ();
    char* getVacantaCroaziera ();
    char* getTabaraGhid ();

    void setBiletAvion (const char *biletAvion);
    void setVacantaWeekend (const char *vacantaWeekend);
    void setCityBreak (const char *cityBreak);
    void setVacantaCroaziera (const char *vacantaCroaziera);
    void setTabaraGhid (const char *tabaraGhid);

    friend std::ostream& operator<<(std::ostream& stream, const Servicii& serviciu);

    ~Servicii ();
};