#include "../../Headers/GUI/creationVisitor.h"

CreationVisitor::CreationVisitor(const QVariantMap& prmts) : creationParameters(prmts) {}

void CreationVisitor::visit(Libro& lib) const {
    lib.setNome(creationParameters["titolo"].toString().toStdString());
    lib.setAnno(creationParameters["anno"].toInt());
    lib.setLingua(creationParameters["lingua"].toString().toStdString());
    
    lib.setCopertina(creationParameters["copertina"].toString().toStdString());
    lib.setPagine(creationParameters["pagine"].toInt());    

    lib.setAutore(creationParameters["autore"].toString().toStdString());
    lib.setEditore(creationParameters["editore"].toString().toStdString());
    lib.setPublisher(creationParameters["publisher"].toString().toStdString());
    lib.setGenere(creationParameters["genere"].toString().toStdString());
    
}

void CreationVisitor::visit(Manga& mng) const {
    mng.setNome(creationParameters["titolo"].toString().toStdString());
    mng.setAnno(creationParameters["anno"].toInt());
    mng.setLingua(creationParameters["lingua"].toString().toStdString());

    mng.setCopertina(creationParameters["copertina"].toString().toStdString());
    mng.setPagine(creationParameters["pagine"].toInt());

    mng.setCadenza(creationParameters["cadenza"].toString().toStdString());

    mng.setMangaka(creationParameters["mangaka"].toString().toStdString());
    mng.setEditore(creationParameters["editore"].toString().toStdString());
    mng.setCapitoli(creationParameters["capitoli"].toInt());
    mng.setGenere(creationParameters["genere"].toString().toStdString());
}

void CreationVisitor::visit(Film& flm) const {
    flm.setNome(creationParameters["titolo"].toString().toStdString());
    flm.setAnno(creationParameters["anno"].toInt());
    flm.setLingua(creationParameters["lingua"].toString().toStdString());

    flm.setRisoluzione(creationParameters["risoluzione"].toString().toStdString());
    flm.setDurata(creationParameters["durata"].toInt());

    flm.setRegista(creationParameters["regista"].toString().toStdString());
    flm.setComposer(creationParameters["compositore"].toString().toStdString());
    flm.setProducer(creationParameters["produttore"].toString().toStdString());
    flm.setGenere(creationParameters["genere"].toString().toStdString());
}

void CreationVisitor::visit(Anime& anm) const {

    anm.setNome(creationParameters["titolo"].toString().toStdString());
    anm.setAnno(creationParameters["anno"].toInt());
    anm.setLingua(creationParameters["lingua"].toString().toStdString());

    anm.setRisoluzione(creationParameters["risoluzione"].toString().toStdString());
    anm.setDurata(creationParameters["durata"].toInt());

    anm.setCadenza(creationParameters["cadenza"].toString().toStdString());
    
    anm.setEpisodi(creationParameters["episodi"].toInt());
    anm.setStagioni(creationParameters["stagioni"].toInt());
    anm.setSubtitle(creationParameters["sottotitolato"].toBool());
    anm.setProducer(creationParameters["produttore"].toString().toStdString());
    anm.setGenere(creationParameters["genere"].toString().toStdString());

}
