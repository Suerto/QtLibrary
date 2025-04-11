#include "../../Headers/LogicModel/manga.h"

const unordered_map<const Manga::Genere, const string> Manga::MappaGeneri = {
    { Manga::Genere::Seinen, "Seinen" },
    { Manga::Genere::Shonen, "Shonen" },
    { Manga::Genere::Shojo, "Shojo" },
    { Manga::Genere::Mecha, "Mecha" },
    { Manga::Genere::Action, "Action" }
};

Manga::Manga(string n, unsigned int a, Lingua l, Copertina co, unsigned int p, Cadenza ca, string m, string ed, unsigned int cp, Genere g) :
            Fisico(n, a, l, co, p), Periodico(ca), mangaka(m), editore(ed), capitoli(getPagine() > 0 ? cp : 0), genere(g) {}
    
string Manga::getMangaka() const { return mangaka; }    
    
string Manga::getEditore() const { return editore; }

unsigned int Manga::getCapitoli() const { return capitoli; }

string Manga::getGenere() const {
    auto it = MappaGeneri.find(genere);
    return it != MappaGeneri.end() ? it->second : "Indefinito";
}

void Manga::setMangaka(const string& mngk) { mangaka = mngk; }

void Manga::setEditore(const string& edtr) { editore = edtr; }

void Manga::setCapitoli(const unsigned int& cp) { 
    if(getPagine() > 0) capitoli = cp;
    else capitoli = 0;
}

void Manga::setGenere(const string& gnr) {
    if(!gnr.empty()) {
        for(const auto&[g, s] : MappaGeneri) {
            if(gnr == s) {
                genere = g;
                return;
            }
        }
    }
    genere = Manga::Genere::Indefinito;
}

void Manga::accept(const Visitors& visitor) const {
    visitor.visit(*this);
}

const unordered_map<const Manga::Genere, const string> Manga::getMappaGeneri() { return MappaGeneri; }
