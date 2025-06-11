#include "../../Headers/LogicModel/digitale.h"

const unordered_map<const Digitale::Risoluzione, const string> Digitale::MappaRisoluzioni {
    { Digitale::Risoluzione::_2K, "2K" },
    { Digitale::Risoluzione::_4K, "4K" },
    { Digitale::Risoluzione::FHD, "Full HD" },
    { Digitale::Risoluzione::UHD, "Ultra HD" },
};

Digitale::Digitale(string n, unsigned int a, Lingua l, 
                   Risoluzione res, unsigned int dur) :
    Contenuto(n, a, l), risoluzione(res), durata(dur) {}

string Digitale::getRisoluzione() const {
    auto it = MappaRisoluzioni.find(risoluzione);
    return it != MappaRisoluzioni.end() ? it->second : "Indefinita";
}
unsigned int Digitale::getDurata() const { return durata; }

void Digitale::setRisoluzione(const string& res) {
    if(!res.empty()) {
        for(const auto&[rsl, str] : Digitale::MappaRisoluzioni) {
            if(res == str) {
                risoluzione = rsl;
                return;
            }
        }
    }
    risoluzione = Digitale::Risoluzione::Indefinita;
}

void Digitale::setDurata(const unsigned int& dur) { durata = dur; }

unordered_map<string, string> Digitale::fromObjectToMap() const {
    unordered_map<string, string> attributi = Contenuto::fromObjectToMap();

    attributi.insert({"Risoluzione", getRisoluzione()});
    attributi.insert({"Durata", std::to_string(getDurata())});

    return attributi;
}

const unordered_map<const Digitale::Risoluzione, const string>& 
Digitale::getMappaRisoluzioni() { return MappaRisoluzioni; }

Digitale::~Digitale() = default;
