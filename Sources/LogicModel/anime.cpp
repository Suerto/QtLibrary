#include "../../Headers/LogicModel/anime.h"

const unordered_map<const Anime::Genere, const string> Anime::MappaGeneri = {
    { Anime::Genere::Isekai, "Isekai" },
    { Anime::Genere::Shonen, "Shonen" },
    { Anime::Genere::Seinen, "Seinen" },
    { Anime::Genere::Mecha, "Mecha" },
};

Anime::Anime(string n, unsigned int a, Lingua l, 
             Risoluzione res, unsigned int d, 
             Cadenza ca, 
             unsigned int ep, unsigned int s, bool sub, string prd, Genere g) : 
    Digitale(n, a, l, res, d), Periodico(ca), 
    episodi(getDurata() > 0 ? ep : 0), stagioni(episodi > 0 ? s : 0), 
    sottotitolato(sub), producer(prd), genere(g) {} 

unsigned int Anime::getEpisodi() const { return episodi; }

unsigned int Anime::getStagioni() const { return stagioni; }

bool Anime::isSubtitled() const { return sottotitolato; }

string Anime::getProducer() const { return producer; }

string Anime::getGenere() const {
    auto it = Anime::MappaGeneri.find(genere);
    return it != Anime::MappaGeneri.end() ? it->second : "Indefinito";
}

void Anime::setEpisodi(const unsigned int& ep) { 
    if(getDurata() > 0) episodi = ep;
    else episodi = 0; 
}

void Anime::setStagioni(const unsigned int& s) {
    if(getDurata() > 0 && getEpisodi() > 0) stagioni = s;
    else stagioni = 0;
}

void Anime::setSubtitle(const bool& sub) { sottotitolato = sub; }

void Anime::setProducer(const string& prd) { producer = prd; }

void Anime::setGenere(const string& gnr) {
    if(!gnr.empty()) {
        for(const auto&[gen, str] : Anime::MappaGeneri) {
            if(gnr == str) {
                genere = gen;
                return;
            }
        }
    } 
    genere = Anime::Genere::Indefinito;
}

void Anime::accept(Visitors* visitor) {
    visitor->visit(*this);
}

const unordered_map<const Anime::Genere, const string>& Anime::getMappaGeneri() 
{ return MappaGeneri; }

unordered_map<string, string> Anime::fromObjectToMap() const {
    unordered_map<string, string> attributi = Digitale::fromObjectToMap();

    attributi.insert({"Cadenza", getCadenza()});
    
    attributi.insert({"Episodi", std::to_string(getEpisodi())});
    attributi.insert({"Stagioni", std::to_string(getStagioni())});
    attributi.insert({"Sottotitolato", std::to_string(isSubtitled())});
    attributi.insert({"Producer", getProducer()});
    attributi.insert({"Genere", getGenere()});
    attributi.insert({"Anteprima", getAnteprima()});
    
    return attributi;
}

Anime::~Anime() = default;
