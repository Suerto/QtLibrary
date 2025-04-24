#include "../../Headers/LogicModel/contenuto.h"

const unordered_map<const Contenuto::Lingua, const string> Contenuto::MappaLingue = {
    { Contenuto::Lingua::Indefinita, "Indefinita" },
    { Contenuto::Lingua::Italiano, "Italiano" },
    { Contenuto::Lingua::Inglese, "Inglese" },
    { Contenuto::Lingua::Tedesco, "Tedesco" },
    { Contenuto::Lingua::Francese, "Francese" },
    { Contenuto::Lingua::Giapponese, "Giapponese" },
};

Contenuto::Contenuto(string n, unsigned int a, Contenuto::Lingua l) : nome(n), anno(a), lingua(l) {}

string Contenuto::getNome() const { return nome; }

unsigned int Contenuto::getAnno() const { return anno; }

string Contenuto::getLingua() const { 
    auto it = MappaLingue.find(lingua);
    return it != MappaLingue.end() ?  it->second : "Indefinita";
}

void Contenuto::setNome(const string& nm) { nome = nm; }

void Contenuto::setAnno(const unsigned int& ann) { anno = ann; }

void Contenuto::setLingua(const string& lng) {
    if(!lng.empty()) {
        for(const auto&[l, s] : Contenuto::MappaLingue) {
            if(lng == s) {
                lingua = l;
                return;
            }
        } 
    }
    lingua = Contenuto::Lingua::Indefinita;
}

const unordered_map<const Contenuto::Lingua, const string> Contenuto::getMappaLingue() { return MappaLingue; }
