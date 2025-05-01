#include "../../Headers/LogicModel/creationVisitor.h"

CreationVisitor::CreationVisitor(const unordered_map<string, string>& prmts) : parametri(prmts) {}

void CreationVisitor::visit(Libro& lib) const {
    // Anno
    auto it = parametri.find("Anno");
    if(it != parametri.end() && !it->second.empty())
        lib.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
    else
        lib.setAnno(0);  // Default: Anno "0"

    // Lingua
    it = parametri.find("Lingua");
    if(it != parametri.end() && !it->second.empty())
        lib.setLingua(it->second);
    else
        lib.setLingua("Indefinita");

    // Copertina
    it = parametri.find("Copertina");
    if(it != parametri.end() && !it->second.empty())
        lib.setCopertina(it->second);
    else
        lib.setCopertina("Indefinita");

    // Pagine
    it = parametri.find("Pagine");
    if(it != parametri.end() && !it->second.empty())
        lib.setPagine(static_cast<unsigned int>(std::stoi(it->second)));
    else
        lib.setPagine(0);  // Default: Pagine "0"

    // Autore
    it = parametri.find("Autore");
    if(it != parametri.end() && !it->second.empty())
        lib.setAutore(it->second);
    else
        lib.setAutore("Indefinito");

    // Editore
    it = parametri.find("Editore");
    if(it != parametri.end() && !it->second.empty())
        lib.setEditore(it->second);
    else
        lib.setEditore("Indefinito");

    // Publisher
    it = parametri.find("Publisher");
    if(it != parametri.end() && !it->second.empty())
        lib.setPublisher(it->second);
    else
        lib.setPublisher("Indefinito");

    // Genere
    it = parametri.find("Genere");
    if(it != parametri.end() && !it->second.empty())
        lib.setGenere(it->second);
    else
        lib.setGenere("Indefinito");
}

void CreationVisitor::visit(Manga& mng) const {
    // Anno
    auto it = parametri.find("Anno");
    if(it != parametri.end() && !it->second.empty())
        mng.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
    else
        mng.setAnno(0);  // Default: Anno "0"

    // Lingua
    it = parametri.find("Lingua");
    if(it != parametri.end() && !it->second.empty())
        mng.setLingua(it->second);
    else
        mng.setLingua("Indefinita");

    // Copertina
    it = parametri.find("Copertina");
    if(it != parametri.end() && !it->second.empty())
        mng.setCopertina(it->second);
    else
        mng.setCopertina("Indefinita");

    // Pagine
    it = parametri.find("Pagine");
    if(it != parametri.end() && !it->second.empty())
        mng.setPagine(static_cast<unsigned int>(std::stoi(it->second)));
    else
        mng.setPagine(0);  // Default: Pagine "0"

    // Cadenza
    it = parametri.find("Cadenza");
    if(it != parametri.end() && !it->second.empty())
        mng.setCadenza(it->second);
    else
        mng.setCadenza("Indefinita");

    // Mangaka
    it = parametri.find("Mangaka");
    if(it != parametri.end() && !it->second.empty())
        mng.setMangaka(it->second);
    else
        mng.setMangaka("Indefinito");

    // Editore
    it = parametri.find("Editore");
    if(it != parametri.end() && !it->second.empty())
        mng.setEditore(it->second);
    else
        mng.setEditore("Indefinito");

    // Capitoli
    it = parametri.find("Capitoli");
    if(it != parametri.end() && !it->second.empty())
        mng.setCapitoli(static_cast<unsigned int>(std::stoi(it->second)));
    else
        mng.setCapitoli(0);  // Default: Capitoli "0"

    // Genere
    it = parametri.find("Genere");
    if(it != parametri.end() && !it->second.empty())
        mng.setGenere(it->second);
    else
        mng.setGenere("Indefinito");
}

void CreationVisitor::visit(Film& flm) const {
    // Anno
    auto it = parametri.find("Anno");
    if(it != parametri.end() && !it->second.empty())
        flm.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
    else
        flm.setAnno(0);  // Default: Anno "0"

    // Lingua
    it = parametri.find("Lingua");
    if(it != parametri.end() && !it->second.empty())
        flm.setLingua(it->second);
    else
        flm.setLingua("Indefinita");

    // Risoluzione
    it = parametri.find("Risoluzione");
    if(it != parametri.end() && !it->second.empty())
        flm.setRisoluzione(it->second);
    else
        flm.setRisoluzione("Indefinita");

    // Durata
    it = parametri.find("Durata");
    if(it != parametri.end() && !it->second.empty())
        flm.setDurata(static_cast<unsigned int>(std::stoi(it->second)));
    else
        flm.setDurata(0);  // Default: Durata "0"

    // Regista
    it = parametri.find("Regista");
    if(it != parametri.end() && !it->second.empty())
        flm.setRegista(it->second);
    else
        flm.setRegista("Indefinito");

    // Compositore
    it = parametri.find("Compositore");
    if(it != parametri.end() && !it->second.empty())
        flm.setComposer(it->second);
    else
        flm.setComposer("Indefinito");

    // Produttore
    it = parametri.find("Produttore");
    if(it != parametri.end() && !it->second.empty())
        flm.setProducer(it->second);
    else
        flm.setProducer("Indefinito");

    // Genere
    it = parametri.find("Genere");
    if(it != parametri.end() && !it->second.empty())
        flm.setGenere(it->second);
    else
        flm.setGenere("Indefinito");
}

void CreationVisitor::visit(Anime& anm) const {
    // Anno
    auto it = parametri.find("Anno");
    if(it != parametri.end() && !it->second.empty())
        anm.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
    else
        anm.setAnno(0);  // Default: Anno "0"

    // Lingua
    it = parametri.find("Lingua");
    if(it != parametri.end() && !it->second.empty())
        anm.setLingua(it->second);
    else
        anm.setLingua("Indefinita");

    // Risoluzione
    it = parametri.find("Risoluzione");
    if(it != parametri.end() && !it->second.empty())
        anm.setRisoluzione(it->second);
    else
        anm.setRisoluzione("Indefinita");

    // Durata
    it = parametri.find("Durata");
    if(it != parametri.end() && !it->second.empty())
        anm.setDurata(static_cast<unsigned int>(std::stoi(it->second)));
    else
        anm.setDurata(0);  // Default: Durata "0"

    // Cadenza
    it = parametri.find("Cadenza");
    if(it != parametri.end() && !it->second.empty())
        anm.setCadenza(it->second);
    else
        anm.setCadenza("Indefinita");

    // Episodi
    it = parametri.find("Episodi");
    if(it != parametri.end() && !it->second.empty())
        anm.setEpisodi(static_cast<unsigned int>(std::stoi(it->second)));
    else
        anm.setEpisodi(0);  // Default: Episodi "0"

    // Stagioni
    it = parametri.find("Stagioni");
    if(it != parametri.end() && !it->second.empty())
        anm.setStagioni(static_cast<unsigned int>(std::stoi(it->second)));
    else
        anm.setStagioni(0);  // Default: Stagioni "0"

    // Sottotitolato
    it = parametri.find("Sottotitolato");
    if(it != parametri.end() && !it->second.empty())
        anm.setSubtitle(static_cast<bool>(std::stoi(it->second)));
    else
        anm.setSubtitle(false);  // Default: Non sottotitolato

    // Produttore
    it = parametri.find("Produttore");
    if(it != parametri.end() && !it->second.empty())
        anm.setProducer(it->second);
    else
        anm.setProducer("Indefinito");

    // Genere
    it = parametri.find("Genere");
    if(it != parametri.end() && !it->second.empty())
        anm.setGenere(it->second);
    else
        anm.setGenere("Indefinito");
}

unordered_map<string, string> CreationVisitor::getMap() const { return parametri; }
