#include <Headers/digitale.h>

Digitale::Digitale(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, vector<Premio> p = vector<Premio>(), Risoluzione r = Risoluzione::Undefined, unsigned int d = 0) :
                    Contenuto(n, a, l), risoluzione(r), durata(d) {}

string Digitale::getRisoluzione() const { 
    switch(risoluzione) {
        case Risoluzione::FHD : return "Full HD";
        case Risoluzione::UHD : return "Ultra HD";
        case Risoluzione::_2K : return "2K";
        case Risoluzione::_4K : return "4K";
        case Risoluzione::Undefined : return "Indefinita";
    }
}

unsigned int Digitale::getDurata() const { return durata; }

void Digitale::setRisoluzione(const Risoluzione& res) { risoluzione = res; }

void Digitale::setDurata(const unsigned int& dur) { durata = dur; }