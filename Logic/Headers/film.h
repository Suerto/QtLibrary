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
    string composer;
    string casaProduttrice;
    Genere genere;
public:
    Film(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined,
         Risoluzione r = Risoluzione::Undefined, unsigned int d = 0,
         string re = "", string co = "", string cp = "", Genere g = Genere::Undefined);

    string getRegista() const;
    string getComposer() const;
    string getCasa() const;
    string getGenere() const;

    void setRegista(const string& re);
    void setComposer(const string& co);
    void setCasa(const string& ca);
    void setGenere(const Genere& g);
};

#endif FILM_H