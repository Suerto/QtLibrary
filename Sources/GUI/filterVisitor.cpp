#include "../../Headers/GUI/filterVisitor.h"

//Il puntatore è per forza di cose nullo all'inizio
FilterVisitor::FilterVisitor(Filters* ptr) : contenutoWidget(ptr) {}

void FilterVisitor::visit(Libro& lib) {
    qDebug() << "Ingresso nella visit del libro";
    BookFilters* libro = new BookFilters;
    
    type = "Libro";

    libro->setAttributes(lib.fromObjectToMap());
    libro->setPathImage(QString::fromStdString(lib.getAnteprima()));
    contenutoWidget = libro;
    qDebug() << "Libro creato";
}

void FilterVisitor::visit(Manga& mng) {
    MangaFilters* manga = new MangaFilters;

    type = "Manga";
    
    manga->setAttributes(mng.fromObjectToMap());

    manga->setPathImage(QString::fromStdString(mng.getAnteprima()));
    contenutoWidget = manga;
}

void FilterVisitor::visit(Anime& anm) {
    AnimeFilters* anime = new AnimeFilters;

    type = "Anime";
    
    anime->setAttributes(anm.fromObjectToMap());
    
    anime->setPathImage(QString::fromStdString(anm.getAnteprima()));
    contenutoWidget = anime;
}

void FilterVisitor::visit(Film& flm) {

    FilmFilters* film = new FilmFilters;

    type = "Film";
    
    film->setPathImage(QString::fromStdString(flm.getAnteprima()));
    film->setAttributes(flm.fromObjectToMap());

    contenutoWidget = film;
}
    
Filters* FilterVisitor::getFilters() const { return contenutoWidget; }

string FilterVisitor::getType() const { return type; }
