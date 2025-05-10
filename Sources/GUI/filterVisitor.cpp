#include "../../Headers/GUI/filterVisitor.h"

//Il puntatore è per forza di cose nullo all'inizio
FilterVisitor::FilterVisitor(Filters* ptr) : contenutoWidget(ptr) {}

void FilterVisitor::visit(Libro& lib) {
    BookFilters* libro = new BookFilters;
    
    type = "Libro";

    libro->setLanguage(QString::fromStdString(lib.getLingua()));
    libro->setYear(lib.getAnno());

    libro->setCover(QString::fromStdString(lib.getCopertina()));
    libro->setPages(lib.getPagine());

    libro->setAuthor(QString::fromStdString(lib.getAutore()));
    libro->setEditor(QString::fromStdString(lib.getEditore()));
    libro->setPublisher(QString::fromStdString(lib.getPublisher()));
    libro->setGenre(QString::fromStdString(lib.getGenere()));

    contenutoWidget = libro;
}

void FilterVisitor::visit(Manga& mng) {
    MangaFilters* manga = new MangaFilters;

    type = "Manga";

    manga->setLanguage(QString::fromStdString(mng.getLingua()));
    manga->setYear(mng.getAnno());

    manga->setCover(QString::fromStdString(mng.getCopertina()));
    manga->setPages(mng.getPagine());

    manga->setCadence(QString::fromStdString(mng.getCadenza()));

    manga->setMangaka(QString::fromStdString(mng.getMangaka()));
    manga->setEditor(QString::fromStdString(mng.getEditore()));
    manga->setChapters(mng.getCapitoli());
    manga->setGenre(QString::fromStdString(mng.getGenere()));

    contenutoWidget = manga;
}

void FilterVisitor::visit(Anime& anm) {
    AnimeFilters* anime = new AnimeFilters;

    type = "Anime";
    
    anime->setYear(anm.getAnno());
    anime->setLanguage(QString::fromStdString(anm.getLingua()));

    anime->setResolution(QString::fromStdString(anm.getRisoluzione()));
    anime->setDuration(anm.getDurata());


    anime->setCadence(QString::fromStdString(anm.getCadenza()));

    anime->setProducer(QString::fromStdString(anm.getProducer()));
    anime->setEpisodes(anm.getEpisodi());
    anime->setSeasons(anm.getStagioni());
    anime->setSubtitle(anm.isSubtitled());
    anime->setGenre(QString::fromStdString(anm.getGenere()));
}

void FilterVisitor::visit(Film& flm) {

    FilmFilters* film = new FilmFilters;

    type = "Film";
    
    film->setYear(flm.getAnno());
    film->setLanguage(QString::fromStdString(flm.getLingua()));

    film->setResolution(QString::fromStdString(flm.getRisoluzione()));
    film->setDuration(flm.getDurata());

    film->setDirector(QString::fromStdString(flm.getRegista()));
    film->setComposer(QString::fromStdString(flm.getComposer()));
    film->setProducer(QString::fromStdString(flm.getProducer()));
    film->setGenre(QString::fromStdString(flm.getGenere()));

    contenutoWidget = film;
}
    
Filters* FilterVisitor::getFilters() const { return contenutoWidget; }

string FilterVisitor::getType() const { return type; }
