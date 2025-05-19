#include "../../Headers/LogicModel/contenuto.h"

const unordered_map<const Contenuto::Lingua, const string> Contenuto::MappaLingue = {
    { Contenuto::Lingua::Italiano, "Italiano" },
    { Contenuto::Lingua::Inglese, "Inglese" },
    { Contenuto::Lingua::Tedesco, "Tedesco" },
    { Contenuto::Lingua::Francese, "Francese" },
    { Contenuto::Lingua::Giapponese, "Giapponese" },
};

Contenuto::Contenuto(string n, unsigned int a, Contenuto::Lingua l, string ant) : nome(n), anno(a), lingua(l), anteprima(ant) {}

string Contenuto::getNome() const { return nome; }

unsigned int Contenuto::getAnno() const { return anno; }

string Contenuto::getLingua() const { 
    auto it = Contenuto::MappaLingue.find(lingua);
    return it != Contenuto::MappaLingue.end() ?  it->second : "Indefinita";
}

string Contenuto::getAnteprima() const { return anteprima; }

void Contenuto::setNome(const string& nm) { nome = nm; }

void Contenuto::setAnno(const unsigned int& ann) { anno = ann; }

void Contenuto::setLingua(const string& lng) {
    if(!lng.empty()) {
        for(const auto&[lan, str] : Contenuto::MappaLingue) {
            if(lng == str) {
                lingua = lan;
                return;
            }
        } 
    }
    lingua = Contenuto::Lingua::Indefinita;
}

void Contenuto::setAnteprima(const string& ant) { anteprima = ant; }

unordered_map<string, string> Contenuto::fromObjectToMap() const {
    unordered_map<string, string> attributi;

    attributi.insert({"Titolo", getNome()});
    attributi.insert({"Anno", std::to_string(getAnno())});
    attributi.insert({"Lingua", getLingua()});
    attributi.insert({"Anteprima", getAnteprima()});

    return attributi;
}

const unordered_map<const Contenuto::Lingua, const string> Contenuto::getMappaLingue() { return MappaLingue; }

Contenuto::~Contenuto() = default;
