#include "../../Headers/LogicModel/searchVisitor.h"
#include <qdebug.h>
#include <algorithm>
#include <cstdlib>

SearchVisitor::SearchVisitor(unordered_map<string, string> prm, bool sml)
    : parametri(prm), similar(sml) {}

std::string SearchVisitor::toLower(const std::string& str) {
    std::string lowered = str;
    std::transform(lowered.begin(), lowered.end(), lowered.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lowered;
}
    // Confronto con supporto per valori speciali e substring match (case-insensitive)
bool SearchVisitor::matches(const string& criterio, const string& valore) const {
    if (criterio.empty()) return true; // campo vuoto: match automatico

    // Se valore è uno di quelli di default (esempio "Indefinito", "0", "Indefinita")
    if (criterio == "Indefinito" || criterio == "0" || criterio == "Indefinita") return true;

    std::string valLower = toLower(valore);
    std::string critLower = toLower(criterio);

    return valLower.find(critLower) != std::string::npos;
}


void SearchVisitor::visit(Libro& lib) {
    if (!matches(parametri["Anno"], std::to_string(lib.getAnno()))) { similar = false; return; }
    if (!matches(parametri["Lingua"], lib.getLingua())) { similar = false; return; }
    if (!matches(parametri["Copertina"], lib.getCopertina())) { similar = false; return; }
    if (!matches(parametri["Pagine"], std::to_string(lib.getPagine()))) { similar = false; return; }
    if (!matches(parametri["Autore"], lib.getAutore())) { similar = false; return; }
    if (!matches(parametri["Editore"], lib.getEditore())) { similar = false; return; }
    if (!matches(parametri["Publisher"], lib.getPublisher())) { similar = false; return; }
    if (!matches(parametri["Genere"], lib.getGenere())) { similar = false; return; }
}

void SearchVisitor::visit(Manga& mng) {
    if (!matches(parametri["Anno"], std::to_string(mng.getAnno()))) { similar = false; return; }
    if (!matches(parametri["Lingua"], mng.getLingua())) { similar = false; return; }
    if (!matches(parametri["Copertina"], mng.getCopertina())) { similar = false; return; }
    if (!matches(parametri["Pagine"], std::to_string(mng.getPagine()))) { similar = false; return; }
    if (!matches(parametri["Cadenza"], mng.getCadenza())) { similar = false; return; }
    if (!matches(parametri["Mangaka"], mng.getMangaka())) { similar = false; return; }
    if (!matches(parametri["Editore"], mng.getEditore())) { similar = false; return; }
    if (!matches(parametri["Capitoli"], std::to_string(mng.getCapitoli()))) { similar = false; return; }
    if (!matches(parametri["Genere"], mng.getGenere())) { similar = false; return; }
}

void SearchVisitor::visit(Film& flm) {
    if (!matches(parametri["Anno"], std::to_string(flm.getAnno()))) { similar = false; return; }
    if (!matches(parametri["Lingua"], flm.getLingua())) { similar = false; return; }
    if (!matches(parametri["Risoluzione"], flm.getRisoluzione())) { similar = false; return; }
    if (!matches(parametri["Durata"], std::to_string(flm.getDurata()))) { similar = false; return; }
    if (!matches(parametri["Regista"], flm.getRegista())) { similar = false; return; }
    if (!matches(parametri["Compositore"], flm.getComposer())) { similar = false; return; }
    if (!matches(parametri["Producer"], flm.getProducer())) { similar = false; return; }
    if (!matches(parametri["Genere"], flm.getGenere())) { similar = false; return; }
}

void SearchVisitor::visit(Anime& anm) {
    if (!matches(parametri["Anno"], std::to_string(anm.getAnno()))) { similar = false; return; }
    if (!matches(parametri["Lingua"], anm.getLingua())) { similar = false; return; }
    if (!matches(parametri["Risoluzione"], anm.getRisoluzione())) { similar = false; return; }
    if (!matches(parametri["Durata"], std::to_string(anm.getDurata()))) { similar = false; return; }
    if (!matches(parametri["Cadenza"], anm.getCadenza())) { similar = false; return; }
    if (!matches(parametri["Producer"], anm.getProducer())) { similar = false; return; }
    if (!matches(parametri["Episodi"], std::to_string(anm.getEpisodi()))) { similar = false; return; }
    if (!matches(parametri["Stagioni"], std::to_string(anm.getStagioni()))) { similar = false; return; }
    
    // Controllo Sottotitolato
    if(anm.isSubtitled() != static_cast<bool>(std::stoi(parametri["Sottotitolato"]))) {
        similar = false;
        return;
    }

    if (!matches(parametri["Genere"], anm.getGenere())) { similar = false; return; }
}

bool SearchVisitor::isSimilar() const {
    return similar;
}

void SearchVisitor::setDefault() {
    similar = true;
}

unordered_map<string, string> SearchVisitor::getMap() const {
    return parametri;
}

SearchVisitor::~SearchVisitor() = default;
