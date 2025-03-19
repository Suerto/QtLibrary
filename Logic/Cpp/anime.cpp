#include <Headers/anime.h>

Anime::Anime(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, Risoluzione r = Risoluzione::Undefined, unsigned int d = 0, Cadenza ca = Cadenza::Undefined, unsigned int ne = 0, unsigned int ns = 0, string cp = "", bool sub = false) :
            Digitale(n, a, l, r, d), Periodico(ca), numeroEpisodi(d <= 0 ? 0 : ne), numeroStagioni(ne > 0 ? ns : 0), casaProduttrice(cp), subtitled(sub) {}

unsigned int Anime::getEpisodi() const { return numeroEpisodi; }

unsigned int Anime::getStagioni() const { return numeroStagioni; }

string Anime::getCasa() const { return casaProduttrice; }

string Anime::getGenere() const {
    switch(genere) {
        case Genere::Shonen : return "Shonen";
        case Genere::Seinen : return "Seinen";
        case Genere::Isekai : return "Isekai";
        case Genere::Undefined : return "Indefinito";
        case Genere::Mecha : return "Mecha";
    }
}

bool Anime::hasSubtitle() const { return subtitled; }

void Anime::setEpisodi(const unsigned int& ne) { numeroEpisodi = ne; }

void Anime::setStagioni(const unsigned int& ns) { numeroStagioni = ns; }

void Anime::setCasa(const string& cp) { casaProduttrice = cp; }

void Anime::setGenere(const Genere& g) { genere = g; }

void Anime::setSubtitle(const bool& sub) { subtitled = sub; }