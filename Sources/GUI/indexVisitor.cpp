#include "../../Headers/GUI/indexVisitor.h"

void IndexVisitor::visit(const BookFilters& book) { index = 0; }

void IndexVisitor::visit(const MangaFilters& manga) { index = 1; }

void IndexVisitor::visit(const FilmFilters& film) { index = 2; }

void IndexVisitor::visit(const AnimeFilters& anime) { index = 3; }

int IndexVisitor::getIndex() const { return index; }
