#ifndef MANGA_H
#define MANGA_H

#include <periodico.h>
#include <fisico.h>

class Manga : public Fisico, public Periodico {
protected:
    enum class Premio {
        Shogakukan,

    };

    enum class Genere {
        Undefined,
        Shonen,
        Seinen,
    };
private:
    string mangaka;
    string publisher;
    unsigned int numeroCapitoli;
    unsigned int numeroPagine;
    Genere genere;
public:
    Manga(string n = "Indefinito", unsigned int a = 0, Lingua l = Lingua::Undefined,                                          // Contenuto
          Copertina c = Copertina(),                                                                                          // Fisico
          Cadenza ca = Cadenza::Undefined,                                                                                    // Periodico
          string m = "Indefinito", string pu = "Indefinito", unsigned int nc = 0, Genere g = Genere());  // Manga 

    string getMangaka() const;
    string getPublisher() const;
    unsigned int getPagine() const;
    unsigned int getCapitoli() const;
    string getGenere() const;

    void setMangaka(const string& ma);
    void setPublisher(const string& pu);
    void setCapitoli(const unsigned int& nc);
    void setGenere(const Genere& ge);
};

#endif MANGA_H