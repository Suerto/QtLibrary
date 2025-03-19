#ifndef FISICO_H
#define FISICO_H

#include <contenuto.h>
class Fisico : public Contenuto {
protected:
    enum class Copertina {
        Undefined,
        Rigida,
        Flessibile,
        Ruvida,
        InBrossura,
    };
private:
    Copertina copertina;
public:
    Fisico(string n = "", unsigned int a = 0, Lingua l = Lingua::Undefined, Copertina c = Copertina::Undefined);                                                                    
    
    string getCopertina() const;

    void setCopertina(const Copertina& cop);
};

#endif FISICO_H