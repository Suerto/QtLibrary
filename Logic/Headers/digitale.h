#ifndef DIGITALE_H
#define DIGITALE_H

#include <contenuto.h>

class Digitale : public Contenuto {
protected:
    enum class Risoluzione {
        Undefined,
        HD,
        FHD,
        UHD,
        _2K,
        _4K
    };
private:
    Risoluzione risoluzione;
    unsigned int durata;
public:
    Digitale(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, vector<Premio> p = vector<Premio>(),
             Risoluzione r = Risoluzione::Undefined, unsigned int d = 0);

    string getRisoluzione() const;
    unsigned int getDurata() const;

    void setDurata(const unsigned int& dur);
    void setRisoluzione(const Risoluzione& res);
};

#endif DIGITALE_H