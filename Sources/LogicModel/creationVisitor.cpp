#include "../../Headers/LogicModel/creationVisitor.h"
#include <QDebug>

CreationVisitor::CreationVisitor(const unordered_map<string, string>& prmts) : 
    parametri(prmts) {}

void CreationVisitor::visit(Libro& lib) {
    auto it = parametri.find("Titolo");
    lib.setNome(it->second);
    // Anno
    it = parametri.find("Anno");
    lib.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
   
    // Lingua
    it = parametri.find("Lingua");
    lib.setLingua(it->second);
    // Copertina
    it = parametri.find("Copertina");
    lib.setCopertina(it->second); 
    // Pagine
    it = parametri.find("Pagine");
    lib.setPagine(static_cast<unsigned int>(std::stoi(it->second)));

    // Autore
    it = parametri.find("Autore");
    lib.setAutore(it->second);

    // Editore
    it = parametri.find("Editore");
    lib.setEditore(it->second);

    // Publisher
    it = parametri.find("Publisher");
    lib.setPublisher(it->second);

    // Genere
    it = parametri.find("Genere");
    lib.setGenere(it->second);

    it = parametri.find("Anteprima");
    lib.setAnteprima(it->second);
}

void CreationVisitor::visit(Manga& mng) {
    // Anno
    auto it = parametri.find("Titolo");
    mng.setNome(it->second);
    
    it = parametri.find("Anno");
    mng.setAnno(static_cast<unsigned int>(std::stoi(it->second)));

    // Lingua
    it = parametri.find("Lingua");
    mng.setLingua(it->second);

    // Copertina
    it = parametri.find("Copertina");
    mng.setCopertina(it->second);

    // Pagine
    it = parametri.find("Pagine");
    mng.setPagine(static_cast<unsigned int>(std::stoi(it->second)));

    // Cadenza
    it = parametri.find("Cadenza");
    mng.setCadenza(it->second);

    // Mangaka
    it = parametri.find("Mangaka");
    mng.setMangaka(it->second);

    // Editore
    it = parametri.find("Editore");
    mng.setEditore(it->second);

    // Capitoli
    it = parametri.find("Capitoli");
    mng.setCapitoli(static_cast<unsigned int>(std::stoi(it->second)));

    // Genere
    it = parametri.find("Genere");
    mng.setGenere(it->second);
    
    it = parametri.find("Anteprima");
    mng.setAnteprima(it->second);
}

void CreationVisitor::visit(Film& flm) {
    // Anno
    auto it = parametri.find("Titolo");
    flm.setNome(it->second);
    
    it = parametri.find("Anno");
    flm.setAnno(static_cast<unsigned int>(std::stoi(it->second)));

    // Lingua
    it = parametri.find("Lingua");
    flm.setLingua(it->second);

    // Risoluzione
    it = parametri.find("Risoluzione");
    flm.setRisoluzione(it->second);

    // Durata
    it = parametri.find("Durata");
    flm.setDurata(static_cast<unsigned int>(std::stoi(it->second)));

    // Regista
    it = parametri.find("Regista");
    flm.setRegista(it->second);

    // Compositore
    it = parametri.find("Compositore");
    flm.setComposer(it->second);

    // Produttore
    it = parametri.find("Producer");
    flm.setProducer(it->second);

    // Genere
    it = parametri.find("Genere");
    flm.setGenere(it->second);
    
    it = parametri.find("Anteprima");
    flm.setAnteprima(it->second);
}

void CreationVisitor::visit(Anime& anm) {
    // Anno
    auto it = parametri.find("Titolo");
    anm.setNome(it->second);

    it = parametri.find("Anno");
    anm.setAnno(static_cast<unsigned int>(std::stoi(it->second)));
    // Lingua
    it = parametri.find("Lingua");
    anm.setLingua(it->second);

    // Risoluzione
    it = parametri.find("Risoluzione");
    anm.setRisoluzione(it->second);

    // Durata
    it = parametri.find("Durata");
    anm.setDurata(static_cast<unsigned int>(std::stoi(it->second)));

    // Cadenza
    it = parametri.find("Cadenza");
    anm.setCadenza(it->second);

    // Episodi
    it = parametri.find("Episodi");
    anm.setEpisodi(static_cast<unsigned int>(std::stoi(it->second)));

    // Stagioni
    it = parametri.find("Stagioni");
    anm.setStagioni(static_cast<unsigned int>(std::stoi(it->second)));
    // Sottotitolato
    it = parametri.find("Sottotitolato");
    anm.setSubtitle(std::stoi(it->second));

    // Produttore
    it = parametri.find("Producer");
    anm.setProducer(it->second);

    // Genere
    it = parametri.find("Genere");
    anm.setGenere(it->second);
    
    it = parametri.find("Anteprima");
    anm.setAnteprima(it->second);
}

unordered_map<string, string> CreationVisitor::getMap() const { return parametri; }

CreationVisitor::~CreationVisitor() = default;