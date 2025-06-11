#ifndef ANIME_H
#define ANIME_H

#include "periodico.h"
#include "digitale.h"

class Anime : public Digitale, public Periodico {
public:
    enum Genere { Indefinito, Isekai, Shonen, Seinen, Mecha };
private:
    unsigned int episodi;
    unsigned int stagioni;
    bool sottotitolato;
    string producer;
    Genere genere;
    static const unordered_map<const Genere, const string> MappaGeneri;
public:
    Anime(string n = "", unsigned int a = 0, Lingua l = Lingua::Indefinita, 
          Risoluzione res = Risoluzione::Indefinita, unsigned int d = 0, 
          Cadenza ca = Cadenza::Indefinita, 
          unsigned int ep = 0, unsigned int s = 0, bool sub = false, string prd = "", 
          Genere g = Genere::Indefinito);

    unsigned int getEpisodi() const;
    unsigned int getStagioni() const;
    bool isSubtitled() const;
    string getProducer() const;
    string getGenere() const;

    void setEpisodi(const unsigned int& ep);
    void setStagioni(const unsigned int& s);
    void setSubtitle(const bool& sub);
    void setProducer(const string& prd);
    void setGenere(const string& gnr);
    
    virtual unordered_map<string, string> fromObjectToMap() const override;
    virtual void accept(Visitors* visitor) override;

    static const unordered_map<const Genere, const string>& getMappaGeneri();

    virtual ~Anime() override;
};
#endif
