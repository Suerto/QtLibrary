#ifndef PREIODICO_H
#define PERIODICO_H

#include <string>
using std::string;

#include <cadenza.h>

class Periodico {
private:
    Cadenza cadenza;
public:
    Periodico(Cadenza ca = Cadenza::Undefined);

    string getCadenza() const;

    void setCadenza(const Cadenza& cad);
};     

#endif PERIODICO_H