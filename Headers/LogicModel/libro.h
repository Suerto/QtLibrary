#ifndef LIBRO_H
#define LIBRO_H

#include "fisico.h"

class Libro : public Fisico {
public:
    enum Genere { Indefinito, Biografia, Storico, Giallo, Avventura, Thriller, Fantasy };
private:
    static const unordered_map<const Genere, const string> MappaGeneri;
    string autore;
    string editore;
    string publisher;
    Genere genere;
public:
    Libro(string n = "", unsigned int a = 0, Lingua l = Lingua::Indefinita, Copertina c = Copertina::Indefinita, unsigned int np = 0, string au = "", string ed = "", string pu = "", Genere g = Genere::Indefinito);

    string getAutore() const;
    string getEditore() const;
    string getPublisher() const;
    string getGenere() const;

    void setAutore(const string& au);
    void setEditore(const string& ed);
    void setPublisher(const string& pu);
    void setGenere(const string& ge);
    
    virtual void accept(const Visitors& visitor) override;

    static const unordered_map<const Genere, const string> getMappaGeneri();
};

#endif 
