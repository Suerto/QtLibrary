#include "../../Headers/GUI/filterVisitor.h"

//Il puntatore è per forza di cose nullo all'inizio
FilterVisitor::FilterVisitor(Filters* ptr) : contenutoWidget(ptr) {}

void FilterVisitor::visit(Libro& lib) {
    BookFilters* libro = new BookFilters;
    
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

void FilterVisitor::visit(Manga& mng) {}

void FilterVisitor::visit(Anime& anm) {}

void FilterVisitor::visit(Film& flm) {}

Filters* FilterVisitor::getFilters() const { return contenutoWidget; }
