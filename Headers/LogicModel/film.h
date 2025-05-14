#ifndef FILM_H
#define FILM_H

#include "digitale.h"
//#include <unordered_map>

class Film : public Digitale {
public:
    enum Genere { Horror, Thriller, Action, Comedy, Guerra, Autobiografico, Romantico, Indefinito };
private:
    static const unordered_map<const Genere, const string> MappaGeneri;
    string regista;
    string composer;
    string producer;
    Genere genere;
public:
    Film(string n = "", unsigned int a = 1970, Lingua l = Lingua::Indefinita, Risoluzione res = Risoluzione::Indefinita, unsigned int dur = 0, string rgs = "", string prd = "", string cmp = "", Genere g = Genere::Indefinito);
    
    string getRegista() const;
    string getComposer() const;
    string getProducer() const;
    string getGenere() const;

    void setRegista(const string& rgs);
    void setComposer(const string& cmp);
    void setProducer(const string& prd);
    void setGenere(const string& gnr);

    virtual void accept(Visitors* visitor) override;

    static const unordered_map<const Genere, const string> getMappaGeneri(); 
};

#endif
