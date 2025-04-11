#include "../../Headers/LogicModel/periodico.h"

const unordered_map<const Periodico::Cadenza, const string> Periodico::MappaCadenze {
    { Periodico::Cadenza::Quotidiana, "Quotidiana" },
    { Periodico::Cadenza::Settimanale, "Settimanale"},
    { Periodico::Cadenza::Mensile, "Mensile" },
    { Periodico::Cadenza::Annuale, "Annuale" }
};

Periodico::Periodico(Cadenza ca) : cadenza(ca) {}

string Periodico::getCadenza() const {
    auto it = MappaCadenze.find(cadenza);
    return it != MappaCadenze.end() ? it->second : "Indefinita";
}

void Periodico::setCadenza(const string& cdn) {
    if(!cdn.empty()) {
        for(const auto& c : MappaCadenze) {
            if(cdn == c.second) cadenza = c.first;
            break;
        }
    }

    else cadenza = Periodico::Cadenza::Indefinita;
}

const unordered_map<const Periodico::Cadenza, const string> Periodico::getMappaCadenze() { return MappaCadenze; }
