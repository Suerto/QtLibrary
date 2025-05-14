#include "../../Headers/LogicModel/fisico.h"

const unordered_map<const Fisico::Copertina, const string> Fisico::MappaCopertine {
    { Fisico::Copertina::Brossura, "Brossura" },
    { Fisico::Copertina::Plastificata, "Plastificata" },
    { Fisico::Copertina::Rigida, "Rigida" },
    { Fisico::Copertina::Ruvida, "Ruvida" }
};

Fisico::Fisico(string n, unsigned int a, Lingua l, Copertina ca, unsigned int p) :
                Contenuto(n, a, l), copertina(ca), pagine(p) {}

string Fisico::getCopertina() const { 
    auto it = Fisico::MappaCopertine.find(copertina);
    return it != Fisico::MappaCopertine.end() ? it->second : "Indefinita";
}

unsigned int Fisico::getPagine() const { return pagine; }

void Fisico::setCopertina(const string& cp) {
    if(!cp.empty()) {
        for(const auto&[cop, str] : Fisico::MappaCopertine) {
            if(cp == str) { 
                copertina = cop;
                return;
            }
        }
    }
    copertina = Fisico::Copertina::Indefinita;
}

void Fisico::setPagine(const unsigned int& pg) { pagine = pg; }

unordered_map<const Fisico::Copertina, const string> Fisico::getMappaCopertine() { return MappaCopertine; }

Fisico::~Fisico() = default;
