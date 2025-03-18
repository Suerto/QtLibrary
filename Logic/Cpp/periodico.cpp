#include <Headers/periodico.h>

Periodico::Periodico(Cadenza ca = Cadenza::Undefined) :
                     cadenza(ca) {}

string Periodico::getCadenza() const {
    switch(cadenza) {
        case Cadenza::Annuale : return "Annuale";
        case Cadenza::Mensile : return "Mensile";
        case Cadenza::Trimestrale : return "Trimestrale";
        case Cadenza::Semestrale : return "Semestrale";
        case Cadenza::Settimanale : return "Settimanale";
        case Cadenza::Quotidiano : return "Quotidiano";
    }
}

void Periodico::setCadenza(const Cadenza& cad) { cadenza = cad; }   