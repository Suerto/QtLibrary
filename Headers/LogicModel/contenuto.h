#ifndef CONTENUTO_H
#define CONTENUTO_H

#include "visitors.h"
#include <string>
#include <vector>
#include <unordered_map>
using std::string;
using std::unordered_map;
using std::vector;


class Contenuto {
public:
    enum Lingua { Indefinita, Italiano, Inglese, Tedesco, Francese, Giapponese, Mandarino };
protected:
    static const unordered_map<const Contenuto::Lingua, const string> MappaLingue;
private:
    string nome;
    unsigned int anno;
    Lingua lingua;
public:   
    Contenuto(string n = "", unsigned int a = 1970, Lingua l = Lingua::Indefinita);

    string getNome() const;
    unsigned int getAnno() const;
    string getLingua() const;

    void setNome(const string& nm);
    void setAnno(const unsigned int& an);
    void setLingua(const string& lng);
    
    virtual void accept(const Visitors& visitor) = 0;

    static const unordered_map<const Contenuto::Lingua, const string> getMappaLingue(); 
};

#endif
