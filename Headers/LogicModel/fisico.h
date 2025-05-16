#ifndef FISICO_H
#define FISICO_H

#include "contenuto.h"

class Fisico : public Contenuto {
public:
    enum Copertina { Indefinita, Brossura, Rigida, Ruvida, Plastificata };
protected:
    static const unordered_map<const Copertina, const string> MappaCopertine;
private:
    Copertina copertina;
    unsigned int pagine;
public:
    Fisico(string n = "", unsigned int a = 1970, Lingua l = Lingua::Indefinita, 
           Copertina ca = Copertina::Indefinita, unsigned int p = 0);

    string getCopertina() const;
    unsigned int getPagine() const;

    void setCopertina(const string& co);
    void setPagine(const unsigned int& pg);

    virtual unordered_map<string, string> fromObjectToMap() const override;
    static unordered_map<const Copertina, const string> getMappaCopertine();
};

#endif
