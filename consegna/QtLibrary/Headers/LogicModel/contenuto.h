#ifndef CONTENUTO_H
#define CONTENUTO_H

#include <string>
#include <vector>
#include <unordered_map>

#include "visitors.h"

using std::string;
using std::unordered_map;
using std::vector;

class Contenuto {
public:
    enum Lingua { Indefinita,
                  Italiano, 
                  Inglese, 
                  Tedesco, 
                  Francese, 
                  Giapponese };
protected:
    static const unordered_map<const Contenuto::Lingua, const string> MappaLingue;
private:
    string nome;
    unsigned int anno;
    Lingua lingua;
    string anteprima;
public:   
    Contenuto(string n = "", unsigned int a = 0,
              Lingua l = Lingua::Indefinita, string ant = "");

    string getNome() const;
    unsigned int getAnno() const;
    string getLingua() const;
    string getAnteprima() const;

    void setNome(const string& nm);
    void setAnno(const unsigned int& an);
    void setLingua(const string& lng);
    void setAnteprima(const string& ant);

    virtual unordered_map<string, string> fromObjectToMap() const;
    virtual void accept(Visitors* visitor) = 0;

    static const unordered_map<const Contenuto::Lingua, const string> getMappaLingue(); 
    
    virtual ~Contenuto();
};

#endif
