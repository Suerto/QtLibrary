#ifndef MANGA_H
#define MANGA_H

#include "fisico.h"
#include "periodico.h"

class Manga : public Fisico, public Periodico {
public:
   enum Genere { Indefinito, Seinen, Shonen, Mecha, Shojo, Action };  
private:
    static const unordered_map<const Genere, const string> MappaGeneri;
    string mangaka;
    string editore;
    unsigned int capitoli;
    Genere genere;
public: 
    Manga(string n = "", unsigned int a = 0, Lingua l = Lingua::Indefinita,
          Copertina co = Copertina::Indefinita, unsigned int p = 0, 
          Periodico::Cadenza ca = Periodico::Cadenza::Indefinita, 
          string m = "", string ed = "", unsigned int cp = 0, 
          Genere g = Genere::Indefinito);

    string getMangaka() const;
    string getEditore() const;
    unsigned int getCapitoli() const;
    string getGenere() const;

    void setMangaka(const string& mngk);
    void setEditore(const string& edtr);
    void setCapitoli(const unsigned int& cp);
    void setGenere(const string& gnr);
    
    virtual void accept(Visitors* visitor) override;

    virtual unordered_map<string, string> fromObjectToMap() const override;
    static const unordered_map<const Genere, const string>& getMappaGeneri();

    virtual ~Manga() override;
};
#endif
