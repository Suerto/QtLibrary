#include "../../Headers/LogicModel/libro.h"

const unordered_map<const Libro::Genere, const string> Libro::MappaGeneri = {
    { Libro::Genere::Biografia, "Biografia" },
    { Libro::Genere::Avventura, "Avventura" },
    { Libro::Genere::Thriller, "Thriller" },
    { Libro::Genere::Storico, "Storico" },
    { Libro::Genere::Giallo, "Giallo" },
    { Libro::Genere::Fantasy, "Fantasy" },
};

Libro::Libro(string n, unsigned int a, Lingua l,
             Copertina c, unsigned int np, 
             string au, string ed, string pu, Genere g) : 
    Fisico(n, a, l, c, np), autore(au), editore(ed), publisher(pu), genere(g) {}


string Libro::getAutore() const { return autore; }

string Libro::getEditore() const { return editore; }

string Libro::getPublisher() const { return publisher; }

string Libro::getGenere() const {
    auto it = MappaGeneri.find(genere);
    return it != MappaGeneri.end() ? it->second : "Indefinito";
}

void Libro::setAutore(const string& au) { autore = au; }

void Libro::setEditore(const string& ed) { editore = ed; }

void Libro::setPublisher(const string& pu) { publisher = pu; }

void Libro::setGenere(const string& ge) {
    if(!ge.empty()) {
        for(const auto&[gen, str] : Libro::MappaGeneri) {
            if(ge == str) {
                genere = gen;
                return;
            }
        }
    }

    else genere = Libro::Genere::Indefinito;
}

void Libro::accept(Visitors* visitor) {
    visitor->visit(*this);
}

unordered_map<string, string> Libro::fromObjectToMap() const {
    unordered_map<string, string> attributi = Fisico::fromObjectToMap();

    attributi.insert({"Autore", getAutore()});
    attributi.insert({"Editore", getEditore()});
    attributi.insert({"Publisher", getPublisher()});
    attributi.insert({"Genere", getGenere()});
    attributi.insert({"Anteprima", getAnteprima()});
    return attributi;
}

const unordered_map<const Libro::Genere, const string>& Libro::getMappaGeneri() { return MappaGeneri; }

Libro::~Libro() = default;
