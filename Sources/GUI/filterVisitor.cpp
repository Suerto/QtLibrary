#include "../../Headers/GUI/filterVisitor.h"

//Il puntatore è per forza di cose nullo all'inizio
FilterVisitor::FilterVisitor(Filters* ptr) : contenutoWidget(ptr) {}

void FilterVisitor::visit(Libro& lib) {
    BookFilters* libro = new BookFilters;
    
    type = "Libro";

    libro->setAttributes(lib.fromObjectToMap());

    contenutoWidget = libro;
}

void FilterVisitor::visit(Manga& mng) {
    MangaFilters* manga = new MangaFilters;

    type = "Manga";
    
    manga->setAttributes(mng.fromObjectToMap());

    contenutoWidget = manga;
}

void FilterVisitor::visit(Anime& anm) {
    AnimeFilters* anime = new AnimeFilters;

    type = "Anime";
    
    anime->setAttributes(anm.fromObjectToMap());
    
    contenutoWidget = anime;
}

void FilterVisitor::visit(Film& flm) {

    FilmFilters* film = new FilmFilters;

    type = "Film";
    
    film->setAttributes(flm.fromObjectToMap());

    contenutoWidget = film;
}
    
Filters* FilterVisitor::getFilters() const { return contenutoWidget; }

string FilterVisitor::getType() const { return type; }
