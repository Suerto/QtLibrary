#include "../../Headers/LogicModel/indexVisitor.h"

void IndexVisitor::visit(Libro& lib) { index = 0; }

void IndexVisitor::visit(Manga& mng) { index = 1; }

void IndexVisitor::visit(Film& flm) { index = 2; }

void IndexVisitor::visit(Anime& anm) { index = 3; }

int IndexVisitor::getIndex() const { return index; }
