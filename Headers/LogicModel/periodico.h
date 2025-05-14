#ifndef PERIODICO_H
#define PERIODICO_H

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Periodico {
public:
    enum Cadenza { Indefinita, Quotidiana, Settimanale, Mensile, Annuale };
private:
    Cadenza cadenza;
    static const unordered_map<const Cadenza, const string> MappaCadenze;
public:
    Periodico(Cadenza ca = Cadenza::Indefinita);

    string getCadenza() const;

    void setCadenza(const string& cdn);

    static const unordered_map<const Cadenza, const string> getMappaCadenze();

    virtual ~Periodico();
};

#endif
