#include <Headers/contenuto.h>

Contenuto::Contenuto(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined) :
                     nome(n), annoUscita(a), lingua(l) {}

string Contenuto::getNome() const { return nome; }

unsigned int Contenuto::getAnno() const { return annoUscita; }

string Contenuto::getLingua() const {
    switch(lingua) {
        case Lingua::Undefined : return "Indefinito";
        case Lingua::Cinese : return "Cinese";
        case Lingua::Francese : return "Francese";
        case Lingua::Giapponese : return "Giapponese";
        case Lingua::Inglese : return "Inglese";
        case Lingua::Italiano : return "Italiano";
        case Lingua::Russo : return "Russo";
        case Lingua::Tedesco : return "Tedesco";
    }
}

void Contenuto::setLingua(const Lingua& li) { lingua = li; }

void Contenuto::setNome(const string& nom) { nome = nom; }

void Contenuto::setAnno(unsigned int& ann) { annoUscita = ann; }
