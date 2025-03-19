#include <Headers/film.h>

Film::Film(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, Risoluzione r = Risoluzione::Undefined, unsigned int d = 0, string re = "", string co = "", string cp = "", Genere g = Genere::Undefined) :
           Digitale(n, a, l, r, d), regista(re), composer(co), casaProduttrice(cp), genere(g) {}

string Film::getRegista() const { return regista; }

string Film::getComposer() const { return composer; }

string Film::getCasa() const { return casaProduttrice; }

string Film::getGenere() const {
    switch(genere) {
        case Genere::Undefined : return "Indefinito";
        case Genere::Horror : return "Horror";
        case Genere::Fantasy : return "Fantasy";
        case Genere::Thriller : return "Thriller";
    }
}

void Film::setRegista(const string& re) { regista = re; }

void Film::setComposer(const string& co) { composer = co; }

void Film::setCasa(const string& ca) { casaProduttrice = ca; }

void Film::setGenere(const Genere& g) { genere = g; }