#include <Headers/libro.h>

Libro::Libro(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, Copertina c = Copertina::Undefined, string au = "", string ed = "", string pu = "", unsigned int np = 0, Genere g = Genere()) :
             Fisico(n, a, l, c), autore(au), editore(ed), publisher(pu),  numeroPagine(np), genere(g) {}

string Libro::getAutore() const { return autore; }

string Libro::getEditore() const { return editore; }

string Libro::getPublisher() const { return publisher; }

unsigned int Libro::getPagine() const { return numeroPagine; }

string Libro::getGenere() const { 
    switch(genere) {
        case Genere::Undefined : return "Indefinito";
        case Genere::Biografia : return "Biografico";
        case Genere::Storico : return "Storico";
        case Genere::Giallo : return "Giallo";
        case Genere::Avventura : return "Avventura";
        case Genere::Thriller : return "Thriller";
        case Genere::Fantasy : return "Fantasy";
    }
}