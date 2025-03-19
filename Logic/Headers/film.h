#ifndef FILM_H
#define FILM_H

#include <digitale.h>

class Film : public Digitale {
protected:
    enum class Genere {
        Horror,
        Avventura,
        Fantasy,
        Thriller,
        Storico,
        Undefined
    };
private:
    string regista;
    Genere genere;
public:
    Film(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined,
         Risoluzione r = Risoluzione::Undefined, unsigned int d = 0,
         Genere g = Genere::Undefined);
};

#endif FILM_H