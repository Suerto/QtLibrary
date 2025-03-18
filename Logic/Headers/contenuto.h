#ifndef CONTENT_H
#define CONTENT_H

#include <string>
#include <vector>
using std::string;
using std::vector;

//#include <h/visitor.h>

//!!! TEMPORANEAMENTE SOSPESA L'IDEA DEI PREMI

class Contenuto {
protected:
    enum class Premio;
    enum class Lingua {
        Undefined,
        Italiano,
        Inglese,
        Tedesco,
        Francese,
        Giapponese,
        Cinese,
        Russo
    };
private:
    string nome;
    unsigned int annoUscita;
    Lingua lingua;
public:
    Contenuto(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined);

    string getNome() const;
    unsigned int getAnno() const;
    string getLingua() const;

    void setNome(const string& nom);
    void setAnno(unsigned int& ann);
    void setLingua(const Lingua& lin);
};

#endif CONTENT_H
