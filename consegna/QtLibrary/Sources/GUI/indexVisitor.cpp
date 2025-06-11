#include "../../Headers/GUI/indexVisitor.h"

void IndexVisitor::visit(const BookFilters* book) { if(book) index = 0; }

void IndexVisitor::visit(const MangaFilters* manga) { if(manga) index = 1; }

void IndexVisitor::visit(const FilmFilters* film) { if(film) index = 2; }

void IndexVisitor::visit(const AnimeFilters* anime) { if(anime) index = 3; }

int IndexVisitor::getIndex() const { return index; }
