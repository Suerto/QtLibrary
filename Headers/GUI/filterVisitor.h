#ifndef FILTER_VISITOR_H
#define FILTER_VISITOR_H

#include "../LogicModel/visitors.h"
#include "../LogicModel/anime.h"
#include "../LogicModel/film.h"
#include "../LogicModel/libro.h"
#include "../LogicModel/manga.h"

#include "animeFilters.h"
#include "bookFilters.h"
#include "filmFilters.h"
#include "mangaFilters.h"

class FilterVisitor : public Visitors {
private:
    Filters* contenutoWidget;
public:
    FilterVisitor(Filters* ptr = nullptr); 

    virtual void visit(Libro& lib) override;
    virtual void visit(Manga& mng) override;
    virtual void visit(Film& flm) override;
    virtual void visit(Anime& anm) override;

    Filters* getFilters() const;
};
#endif //FILTER_VISITOR_H
