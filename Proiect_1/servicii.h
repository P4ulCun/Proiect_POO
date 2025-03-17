#pragma once

// se retin toate serviciile oferite de agentia de turism

class Servicii{
private:
    char *biletAvionDus;
    char *biletAvionIntors;
    char *vacantaWeekend;
    char *cityBreak; // scriu orasul
    char *vacantaCroaziera; // scriu croaziera
    char *tabaraGhid; // drumetii, scuba

public:
    Servicii (const char* = NULL, const char* = NULL, const char* = NULL, const char* = NULL, const char* = NULL, const char* = NULL);
    Servicii (const Servicii& serviciu);

    Servicii& operator=(const Servicii& Servicii);

    char* getBiletAvionDus ();
    char* getBiletAvionIntors ();
    char* getVacantaWeekend ();
    char* getCityBreak ();
    char* getVacantaCroaziera ();
    char* getTabaraGhid ();

    void setBiletAvionDus (const char *biletAvionDus);
    void setBiletAvionIntors (const char *biletAvionIntors);
    void setVacantaWeekend (const char *vacantaWeekend);
    void setCityBreak (const char *cityBreak);
    void setVacantaCroaziera (const char *vacantaCroaziera);
    void setTabaraGhid (const char *tabaraGhid);

    friend std::ostream& operator<<(std::ostream& stream, const Servicii& serviciu);

    ~Servicii ();
};