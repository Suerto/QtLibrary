#ifndef ANIME_H
#define ANIME_H

#include <digitale.h>
#include <periodico.h>

class Anime : public Digitale, public Periodico {
protected:
    enum class Genere {
        Shonen,
        Seinen,
        Isekai,
        Mecha,
        Undefined
    };
private:
    unsigned int numeroEpisodi;
    unsigned int numeroStagioni;
    string casaProduttrice;
    Genere genere;
    bool subtitled;
public:
    Anime(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined,
          Risoluzione r = Risoluzione::Undefined, unsigned int d = 0,
          Cadenza ca = Cadenza::Undefined,
          unsigned int ne = 0, unsigned int ns = 0, string cp = "", bool sub = false);

    unsigned int getEpisodi() const;
    unsigned int getStagioni() const;
    string getCasa() const;
    string getGenere() const;
    bool hasSubtitle() const;

    void setEpisodi(const unsigned int& ne);
    void setStagioni(const unsigned int& ns);
    void setCasa(const string& cp);
    void setGenere(const Genere& g);
    void setSubtitle(const bool& sub);

};

#endif ANIME_H