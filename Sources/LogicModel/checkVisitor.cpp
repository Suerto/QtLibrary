#include "../../Headers/LogicModel/checkVisitor.h"
#include "qdebug.h"

CheckVisitor::CheckVisitor(unordered_map<string, string> prm, bool sml) : 
    parametri(prm), similar(sml) {}

void CheckVisitor::visit(Libro& lib) {
    unsigned int anno = static_cast<unsigned int>(stoi(parametri.find("Anno")->second));
    if(anno != 0) {
        if(anno != lib.getAnno()) {
            similar = false;
            return;
        }
    }

    string lingua = parametri.find("Lingua")->second;
    if(lingua != "Indefinita") {
        if(lingua != lib.getLingua()) {
            similar = false; 
            return;
        }
    }
    
    string copertina = parametri.find("Copertina")->second;
    if(copertina != "Indefinita") {
        if(copertina != lib.getCopertina()) {
            similar = false;
            return;
        }
    }
    
    unsigned int pagine = static_cast<unsigned int>(stoi(parametri.find("Pagine")->second));
    if(pagine != 0) {
        if(pagine != lib.getPagine()) {
            similar = false;
            return;
        }
    }
    
    string autore = parametri.find("Autore")->second;
    if(autore != "Indefinito") {
        if(autore != lib.getAutore()) {
            similar = false;
            return;
        }
    }

    string editore = parametri.find("Editore")->second;
    if(editore != "Indefinito") {
        if(editore != lib.getEditore()) {
            similar = false;
            return;
        }
    }

    string publisher = parametri.find("Publisher")->second;
    if(publisher != "Indefinito") {
        if(publisher != lib.getPublisher()) {
            similar = false;
            return;
        }
    }
    
    string genere = parametri.find("Genere")->second;
    if(genere != "Indefinito") {
        if(genere != lib.getGenere()) {
            similar = false;
            return;
        }
    }
}

void CheckVisitor::visit(Manga& mng) {
    unsigned int anno = static_cast<unsigned int>(stoi(parametri.find("Anno")->second));
    if(anno != 0) {
        if(anno != mng.getAnno()) {
            similar = false;
            return;
        }
    }

    string lingua = parametri.find("Lingua")->second;
    if(lingua != "Indefinita") {
        if(lingua != mng.getLingua()) {
            similar = false; 
            return;
        }
    }
 
    string copertina = parametri.find("Copertina")->second;
    if(copertina != "Indefinita") {
        if(copertina != mng.getCopertina()) {
            similar = false;
            return;
        }
    }

    unsigned int pagine = static_cast<unsigned int>(stoi(parametri.find("Pagine")->second));
    if(pagine != 0) {
        if(pagine != mng.getPagine()) {
            similar = false;
            return;
        }
    }

    string cadenza = parametri.find("Cadenza")->second;
    if(cadenza != "Indefinita") {
        if(cadenza != mng.getCadenza()) {
            similar = false;
            return;
        }
    }

    string mangaka = parametri.find("Mangaka")->second;
    if(mangaka != "Indefinito") {
        if(mangaka != mng.getMangaka()) {
            similar = false;
            return;
        }
    }

    string editore = parametri.find("Editore")->second;
    if(editore != "Indefinito") {
        if(editore != mng.getEditore()) {
            similar = false;
            return;
        }
    }

    unsigned int capitoli = static_cast<unsigned int>(stoi(parametri.find("Capitoli")->second));
    if(capitoli != 0) {
        if(capitoli != mng.getCapitoli()) {
            similar = false;
            return;
        }
    }

    string genere = parametri.find("Genere")->second;
    if(genere != "Indefinito") {
        if(genere != mng.getGenere()) {
            similar = false;
            return;
        }
    }
}

void CheckVisitor::visit(Film& flm) {
    unsigned int anno = static_cast<unsigned int>(stoi(parametri.find("Anno")->second));
    if(anno != 0) {
        if(anno != flm.getAnno()) {
            similar = false;
            return;
        }
    }

    qDebug() << "Anno trovato";
    string lingua = parametri.find("Lingua")->second;
    if(lingua != "Indefinita") {
        if(lingua != flm.getLingua()) {
            similar = false; 
            return;
        }
    }

    qDebug() << "Lingua trovato";
    string risoluzione = parametri.find("Risoluzione")->second;
    if(risoluzione != "Indefinita") {
        if(risoluzione != flm.getRisoluzione()) {
            similar = false; 
            return;
        }
    }
 
    unsigned int durata = static_cast<unsigned int>(stoi(parametri.find("Durata")->second));
    if(durata != 0) {
        if(durata != flm.getDurata()) {
            similar = false; 
            return;
        }
    }

    string regista = parametri.find("Regista")->second;
    if(regista != "Indefinito") {
        if(regista != flm.getRegista()) {
            similar = false; 
            return;
        }
    }

    string compositore = parametri.find("Compositore")->second;
    if(compositore != "Indefinito") {
        if(compositore != flm.getComposer()) {
            similar = false; 
            return;
        }
    }

    string produttore = parametri.find("Producer")->second;
    if(produttore != "Indefinito") {
        if(produttore != flm.getProducer()) {
            similar = false; 
            return;
        }
    }

    string genere = parametri.find("Genere")->second;
    if(genere != "Indefinito") {
        if(genere != flm.getGenere()) {
            similar = false; 
            return;
        }
    }
}

void CheckVisitor::visit(Anime& anm) {
    unsigned int anno = static_cast<unsigned int>(stoi(parametri.find("Anno")->second));
    if(anno != 0) {
        if(anno != anm.getAnno()) {
            similar = false;
            return;
        }
    }

    string lingua = parametri.find("Lingua")->second;
    if(lingua != "Indefinita") {
        if(lingua != anm.getLingua()) {
            similar = false; 
            return;
        }
    }
 
    string risoluzione = parametri.find("Risoluzione")->second;
    if(risoluzione != "Indefinita") {
        if(risoluzione != anm.getRisoluzione()) {
            similar = false; 
            return;
        }
    }
 
    unsigned int durata = static_cast<unsigned int>(stoi(parametri.find("Durata")->second));
    if(durata != 0) {
        if(durata != anm.getDurata()) {
            similar = false; 
            return;
        }
    }


    string cadenza = parametri.find("Cadenza")->second;
    if(cadenza != "Indefinita") {
        if(cadenza != anm.getCadenza()) {
            similar = false;
            return;
        }
    }

    string produttore = parametri.find("Producer")->second;
    if(produttore != "Indefinito") {
        if(produttore != anm.getProducer()) {
            similar = false; 
            return;
        }
    }

    unsigned int episodi = static_cast<unsigned int>(stoi(parametri.find("Episodi")->second));
    if(episodi != 0) {
        if(episodi != anm.getEpisodi()) {
            similar = false; 
            return;
        }
    }
    
    unsigned int stagioni = static_cast<unsigned int>(stoi(parametri.find("Stagioni")->second));
    if(stagioni != 0) {
        if(stagioni != anm.getStagioni()) {
            similar = false; 
            return;
        }
    }
    
    if(anm.isSubtitled() != static_cast<bool>(std::stoi(parametri.find("Sottotitolato")->second))) {
        similar = false;
        return;
    }

    string genere = parametri.find("Genere")->second;
    if(genere != "Indefinito") {
        if(genere != anm.getGenere()) {
            similar = false; 
            return;
        }
    }
}

bool CheckVisitor::isSimilar() const { return similar; }

void CheckVisitor::setDefault() { similar = true; }

unordered_map<string, string> CheckVisitor::getMap() const { return parametri; }
