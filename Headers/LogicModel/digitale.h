#ifndef DIGITALE_H
#define DIGITALE_H

#include "contenuto.h"

class Digitale : public Contenuto {
public:
    enum Risoluzione { FHD, UHD, _2K, _4K, Indefinita };
private:
    Risoluzione risoluzione;
    unsigned int durata;
    static const unordered_map<const Risoluzione, const string> MappaRisoluzioni;
public:
    Digitale(string n = "", unsigned int a = 1970, Lingua l = Lingua::Indefinita, Risoluzione res = Risoluzione::Indefinita, unsigned int dur = 0);

    string getRisoluzione() const;
    unsigned int getDurata() const;

    void setRisoluzione(const string& res);
    void setDurata(const unsigned int& dur);

    static const unordered_map<const Risoluzione, const string> getMappaRisoluzioni();

    virtual ~Digitale();
};

#endif
