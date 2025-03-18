#include <Headers/fisico.h>

Fisico::Fisico(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, Copertina c = Copertina::Undefined) :
               Contenuto(n, a, l), copertina(c) {}

string Fisico::getCopertina() const { 
    switch(copertina) {
        case Copertina::Undefined : return "Indefinito";
        case Copertina::Flessibile : return "Flessibile";
        case Copertina::InBrossura : return "In Brossura";
        case Copertina::Rigida : return "Rigida";
        case Copertina::Ruvida : return "Ruvida";
    }
}

void Fisico::setCopertina(const Copertina& c) { copertina = c; }