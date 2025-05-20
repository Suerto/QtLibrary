#include "../../Headers/LogicModel/film.h"

const unordered_map<const Film::Genere, const string> Film::MappaGeneri = {
    { Film::Genere::Thriller, "Thriller" },
    { Film::Genere::Horror, "Horror" },
    { Film::Genere::Action, "Azione" },
    { Film::Genere::Autobiografico, "Autobiografico" },
    { Film::Genere::Comedy, "Commedia" },
    { Film::Genere::Guerra, "Guerra" },
    { Film::Genere::Romantico, "Romantico" }
};

Film::Film(string n, unsigned int a, Lingua l, Risoluzione res, unsigned int d, string rgs, string cmp, string prd, Genere g) :
            Digitale(n, a, l, res, d), regista(rgs), composer(cmp), producer(prd), genere(g) {}

string Film::getRegista() const { return regista; }

string Film::getComposer() const { return composer; }

string Film::getProducer() const { return producer; }

string Film::getGenere() const {
    auto it = Film::MappaGeneri.find(genere);
    return it != Film::MappaGeneri.end() ? it->second : "Indefinito";
}

void Film::setRegista(const string& rgs) { regista = rgs; }

void Film::setProducer(const string& prd) { producer = prd; }

void Film::setComposer(const string& cmp) { composer = cmp; }

void Film::setGenere(const string& gnr) {
    if(!gnr.empty()) {
        for(const auto&[gen, str] : Film::MappaGeneri) {
            if(gnr == str) {
                genere = gen; 
                return;
            }
         }
    }
    genere = Film::Genere::Indefinito;
}

void Film::accept(Visitors* visitor) {
    visitor->visit(*this);
}

unordered_map<string, string> Film::fromObjectToMap() const {
    unordered_map<string, string> attributi = Digitale::fromObjectToMap();

    attributi.insert({"Regista", getRegista()});
    attributi.insert({"Compositore", getComposer()});
    attributi.insert({"Producer", getProducer()});
    attributi.insert({"Genere", getGenere()});
    attributi.insert({"Anteprima", getAnteprima()});
    return attributi;
}

const unordered_map<const Film::Genere, const string> Film::getMappaGeneri() { return MappaGeneri; }
